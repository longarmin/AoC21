#include <iostream>
#include <cstdint>
#include <fstream>
#include <string>

typedef struct {
int32_t ssPos_x, ssPos_y;
int32_t ssAim;
}Pos_t;

using namespace std;
class Position_c {
    Pos_t sPos;
public:
    Position_c() : sPos{0} {}
    void change_pos(char ucDir, int32_t ssUnits){
        switch(ucDir){
            case 'f':   sPos.ssPos_x += ssUnits;
                        sPos.ssPos_y += sPos.ssAim * ssUnits;
                        break;
            case 'u':   sPos.ssAim -= ssUnits;
                        break;
            case 'd':   sPos.ssAim += ssUnits;
                        break;
            default: cout << "Could not interpret Number: " << ssUnits << " - What are you doing?\n";
        }
        //cout << "position changed (" << ucDir << ", " << ssUnits << "). Current Pos: (" << sPos.ssPos_x << ", " << sPos.ssPos_y << ")\n" ;
    }
    
    Pos_t get_pos(){
        return sPos;
    }

    int32_t get_AoC_Result(){
        return sPos.ssPos_x * sPos.ssPos_y;
    }


};

int main() {
    string line;
    ifstream myfile ("../include/input02.txt");
    Position_c Pos; 
    if(myfile.is_open()){
        while( getline(myfile, line)){
            auto it = end(line)-1;
            Pos.change_pos(line[0], (*it - '0'));
        }
    }
    cout << "Final Position: (" << Pos.get_pos().ssPos_x << ", " << Pos.get_pos().ssPos_y << "), Multiplikation, Result for AoC: " << Pos.get_AoC_Result() << "\n";
    return 0;
}