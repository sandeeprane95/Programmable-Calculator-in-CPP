#include "ProgCalculatorAbstract.h"

void ProgCalculatorAbstract::assignmentExp(vector<string> instr)
{
    if(instr[0][0]=='w')
    {
        this->regW = stof(instr[2]);
    }
    if(instr[0][0]=='x')
    {
        this->regX = stof(instr[2]);
    }
    if(instr[0][0]=='y')
    {
        this->regY = stof(instr[2]);
    }
    if(instr[0][0]=='z')
    {
        this->regZ = stof(instr[2]);
    }
}
