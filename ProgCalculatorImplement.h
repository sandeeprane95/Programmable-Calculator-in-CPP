#include "ProgCalculatorAbstract.h"

class ProgCalculatorImplement : public ProgCalculatorAbstract
{
    public:
        ProgCalculatorImplement(vector<string>);
        int currentInst;
        void arithmeticExp(vector<string>);
        void controlTransferExp(vector<string>);
        vector<string> convertInstr(string);
        vector<string> fileInstructions;
        void setW(float);
        void setX(float);
        void setY(float);
        void setZ(float);
        float getW();
        float getX();
        float getY();
        float getZ();
        float getRegisterValue(char);
        void setRegisterValue(char,float);

};
