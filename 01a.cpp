#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "stdint-gcc.h"
 
using namespace std;

int main()
{
    int32_t sLine, sLastLine, count_inc=0, count_no_inc=0, count_total=0;
    string line;
    ifstream myfile ("import/input01.txt");
    if(myfile.is_open()){
        getline(myfile, line);
        sLine = stoi(line);
        sLastLine = sLine;
        while ( getline(myfile, line) ) {
            sLine = stoi(line);
            if (sLastLine < sLine ){
                count_inc += 1;
            }
            else {
                count_no_inc += 1;
            }
            count_total++;
            sLastLine = sLine;
        }
        cout << "Total no. of compairisions: " << count_total << "\nNo. of compairisions w/ increased depth:" << count_inc << "\nNo. of compairisions w/o increased depth: " << count_no_inc;
        myfile.close();
    }   
    else {
        cout << "unable to open file\n";
    }
    return 0;

}