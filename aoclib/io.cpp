#include <iostream>
#include <fstream>
#include <string>
#include <cstdint>
#include <vector>
#include "io.hpp"

using namespace std;

namespace AOC21 {

vector<string> ReadLinesFromFile(const char* file) {
    vector<string> lines;
    string line;
    ifstream myfile(file);
    if(myfile.is_open()){
        while(getline(myfile, line)){
            lines.push_back(line);
        }
    }
    return lines;
}

}