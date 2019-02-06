#include<string>
#include<vector>
using namespace std;
class ProgCalculatorAbstract
{
    protected:
        float regW;
        float regX;
        float regY;
        float regZ;
    public:
        ProgCalculatorAbstract(){};
        virtual void arithmeticExp(vector<string>) = 0;
        virtual void controlTransferExp(vector<string>) = 0;
        void assignmentExp(vector<string>);
};
