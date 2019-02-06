#include "Command.h"
#include "ProgCalculatorImplement.h"
#include <iostream>
#include <fstream>
using namespace std;

class Statements1n2 : Command
{
    ProgCalculatorImplement *pc;
    vector<string> x;
    public:
    Statements1n2(ProgCalculatorImplement *p, vector<string> abc)
    {
        pc = p;
        x = abc;
    }
    void run();
};
void Statements1n2::run()
{
    pc->arithmeticExp(x);
}

class Statements3n4 : Command
{
    ProgCalculatorImplement *pc;
    vector<string> x;
    public:
    Statements3n4(ProgCalculatorImplement *p, vector<string> abc)
    {
        pc = p;
        x = abc;
    }
    void run();
};
void Statements3n4::run()
{
    pc->controlTransferExp(x);
}

void printRegisters(ProgCalculatorImplement *p, int f)
{
    cout << "\t__________________________" <<endl;
    cout << "\t    Register contents:" <<endl << endl;
    cout << endl << "\tRegister W: " << p->getW() <<endl;
    cout <<"\tRegister X: " << p->getX() <<endl;
    cout <<"\tRegister Y: " << p->getY() <<endl;
    cout <<"\tRegister Z: " << p->getZ() <<endl;
    int l = p->currentInst;
    int pl = l;
    if(l+1>f)
        pl = 0;
    cout << endl << "\tNext Instruction Index:" << pl+1 << endl;
    cout << "\t__________________________" <<endl;
}

void printFile(vector<string> file, ProgCalculatorImplement *p)
{
    cout << "\t___________________________________________" <<endl;
    cout << "\t\t File Instruction Sequence:" <<endl << endl;
    for(int i=0; i<file.size();i++)
    {
        cout <<"\t" << (i+1) << ": " << file[i] <<endl;
    }
    printRegisters(p, file.size());
    cout << "\t___________________________________________" <<endl;
}

int main()
{
    string inputCommand = "x";
    const int numCommands = 6;
    bool flag = false;
    int commandsExec = 0;
    vector<string> fileLines;
    ProgCalculatorImplement *pcInstance;
    int fileSize = 0;
    cout << endl << "----------------Programmable Calculator---------------" << endl;
    while(inputCommand[0] != 'q')
    {
        cout << "------------------------------------------------------" << endl;
        cout << endl << "\ti <file_name> - Input File" << endl;
        cout << "\td - Debug" << endl;
        cout << "\tr - Run" << endl;
        cout << "\tc - Continue" << endl;
        cout << "\tp - Print" << endl;
        cout << "\tq - Quit" << endl;
        cout << endl << "------------------------------------------------------" << endl;
        cout << endl << "  Input a command..." << endl;
        getline(cin, inputCommand);
        if(inputCommand[0] == 'i')
        {
            string fileName = inputCommand.substr(2);
            string lineRead;
            ifstream myfile;
            myfile.open(fileName);
            if (!myfile) {
                cout << endl << "\tFile does not exist!!!" << endl;
                continue;
            }
            while(getline(myfile, lineRead))
            {
                fileLines.push_back(lineRead);
            }
            pcInstance = new ProgCalculatorImplement(fileLines);
            flag = true;
            fileSize = fileLines.size();
        }
        else if(inputCommand[0] == 'd')
        {
            if(flag==false)
            {
                cout << endl << "\tPlease select a input file before debugging!!!" << endl;
                continue;
            }
            if(pcInstance->currentInst < fileSize)
            {
                vector<string> parsedInstr = pcInstance->convertInstr(pcInstance->fileInstructions[pcInstance->currentInst]);
                if(parsedInstr.size()==4)
                {
                    Statements1n2 stmt(pcInstance, parsedInstr);
                    stmt.run();
                }
                if(parsedInstr.size()==3 && parsedInstr[1][0]=='?')
                {
                    Statements3n4 stmt(pcInstance, parsedInstr);
                    stmt.run();
                }
                if(parsedInstr.size()==3 && parsedInstr[1][0]=='=')
                {
                    pcInstance->assignmentExp(parsedInstr);
                    pcInstance->currentInst+=1;
                }
                printRegisters(pcInstance, fileSize);
            }
            else{
                pcInstance->currentInst = 0;
                vector<string> parsedInstr = pcInstance->convertInstr(pcInstance->fileInstructions[pcInstance->currentInst]);
                if(parsedInstr.size()==4)
                {
                    Statements1n2 stmt(pcInstance, parsedInstr);
                    stmt.run();
                }
                if(parsedInstr.size()==3 && parsedInstr[1][0]=='?')
                {
                    Statements3n4 stmt(pcInstance, parsedInstr);
                    stmt.run();
                }
                if(parsedInstr.size()==3 && parsedInstr[1][0]=='=')
                {
                    pcInstance->assignmentExp(parsedInstr);
                    pcInstance->currentInst+=1;
                }
                printRegisters(pcInstance, fileSize);
            }
        }
        else if(inputCommand[0] == 'r')
        {
            if(flag==false)
            {
                cout << endl << "\tPlease select a input file before running!!!" << endl;
                continue;
            }
            while(commandsExec<100)
            {
                if(pcInstance->currentInst < fileSize)
                {
                    vector<string> parsedInstr = pcInstance->convertInstr(pcInstance->fileInstructions[pcInstance->currentInst]);
                    if(parsedInstr.size()==4)
                    {
                        Statements1n2 stmt(pcInstance, parsedInstr);
                        stmt.run();
                    }
                    if(parsedInstr.size()==3 && parsedInstr[1][0]=='?')
                    {
                        Statements3n4 stmt(pcInstance, parsedInstr);
                        stmt.run();
                    }
                    if(parsedInstr.size()==3 && parsedInstr[1][0]=='=')
                    {
                        pcInstance->assignmentExp(parsedInstr);
                        pcInstance->currentInst+=1;
                    }
                    commandsExec++;
                }
                else
                {
                    commandsExec = 0;
                    printRegisters(pcInstance, fileSize);
                    break;
                }
            }
            if(commandsExec == 100)
            {
                cout << endl << "\t100 executions reached!!!" << endl;
            }
        }
        else if(inputCommand[0] == 'c')
        {
            if(flag==false)
            {
                cout << endl << "\tPlease select a input file before continuing!!!" << endl;
                continue;
            }
            if(commandsExec>=100)
            {
                commandsExec = 0;
                cout << endl << "\tCan continue execution from the next available instruction..." << endl;
            }
        }
        else if(inputCommand[0] == 'p')
        {
            printFile(fileLines, pcInstance);
        }
    }
    return 0;
}

