#include "ProgCalculatorImplement.h"
#include <iostream>
#include <sstream>
#include <iterator>
#include<cmath>

ProgCalculatorImplement::ProgCalculatorImplement(vector<string> instructionSet)
{
    this->regW = 0;
    this->regX = 0;
    this->regY = 0;
    this->regZ = 0;
    this->currentInst = 0;
    this->fileInstructions = instructionSet;
}

vector<string> ProgCalculatorImplement::convertInstr(string instruction)
{
    instruction.pop_back();
    istringstream iss(instruction);
    vector<string> tokens{istream_iterator<string>{iss},
                      istream_iterator<string>{}};
    vector<string> instrArray;
    if(tokens.size()==5)
    {
        instrArray.push_back(tokens[0]);
        instrArray.push_back(to_string(this->getRegisterValue(tokens[2][0])));
        instrArray.push_back(tokens[3]);
        if(isalpha(tokens[4][0]))
            instrArray.push_back(to_string(this->getRegisterValue(tokens[4][0])));
        else
            instrArray.push_back(tokens[4]);
    }
    if(tokens.size()==3)
    {
        return tokens;
    }
    return instrArray;
}

float ProgCalculatorImplement::getW()
{
    return this->regW;
}

float ProgCalculatorImplement::getX()
{
    return this->regX;
}

float ProgCalculatorImplement::getY()
{
    return this->regY;
}

float ProgCalculatorImplement::getZ()
{
    return this->regZ;
}

void ProgCalculatorImplement::setW(float regVal)
{
    this->regW = regVal;
}

void ProgCalculatorImplement::setX(float regVal)
{
    this->regX = regVal;
}

void ProgCalculatorImplement::setY(float regVal)
{
    this->regY = regVal;
}

void ProgCalculatorImplement::setZ(float regVal)
{
    this->regZ = regVal;
}

float ProgCalculatorImplement::getRegisterValue(char a)
{
    if(a == 'w')
        return this->getW();
    if(a == 'x')
        return this->getX();
    if(a == 'y')
        return this->getY();
    if(a == 'z')
        return this->getZ();
}

void ProgCalculatorImplement::setRegisterValue(char a, float regVal)
{
    if(a == 'w')
        this->setW(regVal);
    if(a == 'x')
        this->setX(regVal);
    if(a == 'y')
        this->setY(regVal);
    if(a == 'z')
        this->setZ(regVal);
}

void ProgCalculatorImplement::arithmeticExp(vector<string> instr)
{
    float computedVal;
    if(instr[2].compare("+")==0)
    {
        computedVal = stof(instr[1])+stof(instr[3]);
    }
    if(instr[2].compare("-")==0)
    {
        computedVal = stof(instr[1])-stof(instr[3]);
    }
    if(instr[2].compare("*")==0)
    {
        computedVal = stof(instr[1])*stof(instr[3]);
    }
    if(instr[2].compare("**")==0)
    {
        computedVal = pow(stof(instr[1]),stof(instr[3]));
    }
    if(instr[2].compare("/")==0)
    {
        computedVal = stof(instr[1])/stof(instr[3]);
    }
    this->setRegisterValue(instr[0][0],computedVal);
    this->currentInst += 1;
}

void ProgCalculatorImplement::controlTransferExp(vector<string> instr)
{
    float regVal = this->getRegisterValue(instr[0][0]);
    if(regVal != 0)
    {
        this->currentInst = (stoi(instr[2])-1);
    }
    else
        this->currentInst += 1;
}
