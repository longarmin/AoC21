#include <iostream>
#include <string>
#include <fstream>
#include <cstdint>
#include <cmath>
#include <vector>
#include <utility> //used for swapping

using namespace std;
// typedef struct{
//     vector<string> vZeroes;
//     vector<string> vOnes;
// }Ratings_t;


class ratings_c{
public:
    vector<string> CheckBit(vector<string> sLines, uint8_t ucBitNumber, bool bMinorCnt){
        vector<string> vPickedLines;
        vector<string> vZeroes;
        vector<string> vOnes;
        uint32_t ucCountMajor=0, ucCountMinor=0;
        for (auto & elem : sLines){
            if(elem[ucBitNumber] == '1'){
                vOnes.push_back(elem);
            }
            else if (elem[ucBitNumber] == '0'){
                vZeroes.push_back(elem);
            }
        }
        vPickedLines = VectorSizeCompare(vOnes, vZeroes, bMinorCnt);
        if (size(vPickedLines) > 1){
            ucBitNumber++;
            vPickedLines = CheckBit(vPickedLines, ucBitNumber, bMinorCnt);
        }
        if (size(vPickedLines) == 1){
            return vPickedLines;
        }
        cout << "Error: Could not find final line.\n";
        return vPickedLines;
    }
    vector<string> VectorSizeCompare(vector<string> vOne, vector<string> vZero, bool bMinorCnt){
        uint32_t usSize_vOne = size(vOne);
        uint32_t usSize_vZero = size(vZero);
        if(bMinorCnt){
            swap(vOne, vZero);
        }
        if(usSize_vOne >= usSize_vZero){
            return vOne;
        }
        else {
            return vZero;
        }
    }
};

int main(){
    ifstream myfile ("import/input03.txt");
    ratings_c cRating;
    uint8_t ucLinesize = 0;
    int32_t ssLineCount = 0, ssBit[20] = {0};
    uint32_t usResultGamma[20]={0};
    uint32_t usDecResultOxygen = 0, usDecResultCO2scrubber = 0;
    string sLine, sResult="";
    vector<string> vLines, vMajorLines, vMinorLines;
    if( myfile.is_open() ) {
        while( getline(myfile, sLine) ) {
            if(ssLineCount == 0){
                ucLinesize = size(sLine);
            }
            vLines.push_back(sLine);
            for(uint8_t i = 0; i < ucLinesize; i++){
                ssBit[i] += int32_t(sLine[i]-'0');
            }
            ssLineCount++;
        }
        vMajorLines=cRating.CheckBit(vLines, 0, 0);
        vMinorLines=cRating.CheckBit(vLines, 0, 1);
        cout << vMajorLines[0] << "\n";
        cout << vMinorLines[0] << "\n";
        ssLineCount /= 2;
        for(uint8_t i = 0; i < ucLinesize; i++){
            usDecResultOxygen += pow(2,(ucLinesize-i-1))*(vMajorLines[0][i]-'0');
            usDecResultCO2scrubber += pow(2,(ucLinesize-i-1))*(vMinorLines[0][i]-'0');
        }
        cout << "Result Oxgen, Decimal: " << usDecResultOxygen << "\n";
        cout << "Result CO2 Scrubber, Decimal: " << usDecResultCO2scrubber << "\n";
        cout << "Result Power Consumption (Oxgen * CO2 Scrubber): " << usDecResultOxygen*usDecResultCO2scrubber << "\n";
    }
    return 0;
}