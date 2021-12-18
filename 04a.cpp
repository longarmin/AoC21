#include "aoclib/io.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef struct{
    uint8_t cells[5][5];
}board_t;

board_t get_board(vector<string> lines){
    vector<string>::iterator it = lines.begin();
    board_t sBoard = { 0 };
    size_t p = lines[2].find(" ");
    std::cout << "first 'whitespace' found at: " << p << " sign before is" << lines[2][(p-1)] << '\n';
    return sBoard;
    }

int main(int argc, char** argv){
    vector<string> lines = AOC21::ReadLinesFromFile(argv[1]);
    vector<board_t> sBoardsets;
    sBoardsets.push_back(get_board(lines));

}