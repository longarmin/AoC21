#include <iostream>
#include <fstream>
#include <string>
#include <cstdint>
 
using namespace std;

class cSlidingWindow {
    
    int32_t ssFirst, ssSecond, ssThird;
public:
    cSlidingWindow() : ssFirst(0), ssSecond(0), ssThird(0) {}
    cSlidingWindow(int32_t a, int32_t b, int32_t c ) : ssFirst(a), ssSecond(b), ssThird(c) {}
    
    int32_t compare(int ssOtherSum){
        if ((sum() - ssOtherSum) > 0){
            return 1;
        }
        else{
            return 0;
        }
    }

    int32_t sum(){
        return ssFirst + ssSecond + ssThird;
    }

    void BuildNextWindow(int32_t ssNewVal){
        ssFirst = ssSecond;
        ssSecond = ssThird;
        ssThird = ssNewVal;
    } 
};

int main()
{
    int32_t ssLine[3], ssSumLastWindow, ssCount_inc=0, ssCount_no_inc=0, ssCount_total=0, ssWindowSum=0;
    int32_t *psLine[3];
    string sLine0, sLine1, sLine2;
    ifstream myfile ("import/01.txt");
    if(myfile.is_open()){
        getline(myfile, sLine0);
        getline(myfile, sLine1);
        getline(myfile, sLine2);
        ssLine[0] = stoi(sLine0);
        ssLine[1] = stoi(sLine1);
        ssLine[2] = stoi(sLine2);
        cSlidingWindow cswWindow(ssLine[0], ssLine[1], ssLine[2]);
        ssSumLastWindow = cswWindow.sum();
        cout << "SUM= " << cswWindow.sum() << "\n";
        while ( getline(myfile, sLine0) ) {
            ssLine[0] = stoi(sLine0);
            cswWindow.BuildNextWindow(ssLine[0]);
            ssWindowSum = cswWindow.sum();
            ssCount_inc += cswWindow.compare(ssSumLastWindow);
            ssSumLastWindow = ssWindowSum;
        }
        cout << "Number of increases: " << ssCount_inc << "\n";
        myfile.close();
    }   
    else {
        cout << "unable to open file\n";
    }
    return 0;

}