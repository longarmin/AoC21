#include <iostream>
#include <string>
#include <fstream>
#include <cstdint>
#include <cmath>

using namespace std;

int main(){
    ifstream myfile ("import/test.txt");
    uint8_t ucLinesize = 0;
    int32_t ssLineCount = 0, ssBit[20] = {0};
    uint32_t usResultGamma[20]={0};
    uint32_t usDecResultGamma = 0, usDecResultEpsilon = 0;
    string sLine, sResult="";

    if( myfile.is_open() ) {
        while( getline(myfile, sLine) ) {
            if(ssLineCount == 0){
                ucLinesize = size(sLine);
            }
            for(uint8_t i = 0; i < ucLinesize; i++){
                ssBit[i] += int32_t(sLine[i]-'0');
            }
            ssLineCount++;
        }
        ssLineCount /= 2;
        for(uint8_t i = 0; i < ucLinesize; i++){
            usResultGamma[i] = (ssLineCount < ssBit[i]);
            usDecResultGamma += pow(2,(ucLinesize-i-1))*usResultGamma[i];
            usDecResultEpsilon += pow(2,(ucLinesize-i-1))*(!usResultGamma[i]);
            sResult += (usResultGamma[i]+'0');
        }
        cout << "Result Gamma: 0b" << sResult << ", Decimal: " << usDecResultGamma << "\n";
        cout << "Result Epsilon Decimal: " << usDecResultEpsilon << "\n";
        cout << "Result Power Consumption (Gamma * Epsilon): " << usDecResultGamma*usDecResultEpsilon << "\n";
    }
}