#include <iostream>
#include <string>
#include "TIcTacToe.h"
#include <ctype.h>

using namespace std;


int main()
{
    MainBoard CurrentBoard;
    bool PlayinX = false;
    int Xboard,Yboard;
    while(CurrentBoard.WhoWon == 0){
        if(CurrentBoard.SpecialMove == 1){cout << "Select which board would you like to play in x and y coordinates X: "; cin>>Xboard;cout<< " y: ";cin>>Yboard;}
        else
        {
            Xboard = CurrentBoard.LastPlayedX;
            Yboard = CurrentBoard.LastPlayedY;
        }
        if (Xboard > 3 || Xboard <= 0 || Yboard > 3 || Yboard <= 0){
            cout << "that coordinate is not valid, select a coordinate ranging 1-3 in x and y";
        }
        if (CurrentBoard.Whole[Yboard-1][Xboard-1] != 0){
            cout << "that board is already won select another one \n\n";
            continue;
        }
        CurrentBoard.PlayWherever(PlayinX,Xboard,Yboard);
        if (CurrentBoard.SpecialMove == 1){
            continue;
        }
        PlayinX = !PlayinX;
    }
    if (CurrentBoard.IsTie == true){
        std::cout<< u8"\033[2J\033[1;1H";
        cout << "--------------The MATCH ended in a TIE--------------"
    } else {
        string Now = (CurrentBoard.WhoWon== true)? "X" : "O";
        cout << "--------------The MATCH was won by "<< Now <<"--------------"
    }
    return 0;
}
