#include <iostream>
#include <string>
using namespace std;
#ifndef TICTACTOE_H_INCLUDED
#define TICTACTOE_H_INCLUDED

class Board{
    public:
        int Whole[3][3] = {{0,0,0},{0,0,0},{0,0,0}};
        int WhoWon = 0;
        void IsWon(){
            // 0 is empty, 1 is O, 2 is X
            // return 1 or 2 if there is a win from either
            for (int row=0; row<3; row++) {
                if (Whole[row][0] == Whole[row][1] && Whole[row][1] == Whole[row][2]) {
                    if (Whole[row][0] != 0) WhoWon = Whole[row][0];
                }
            }
            for (int col=0; col<3; col++) {
                if (Whole[0][col] == Whole[1][col] && Whole[0][col] == Whole[2][col]) {
                    if (Whole[0][col] != 0) WhoWon = Whole[0][col];
                }
            }
            if (Whole[0][0] == Whole[1][1] && Whole[1][1] == Whole[2][2]) {
                if (Whole[0][0] != 0) WhoWon = Whole[0][0];
            }
            if (Whole[0][2] == Whole[1][1] && Whole[1][1] == Whole[2][0]) {
                if (Whole[0][2] != 0) WhoWon = Whole[0][2];
            }
        }
};
class MainBoard : public Board{
protected:
    int X;
    int Y;
    bool WhoPlayin; // if false | 0 == O else it's X playing
public:
    int LastPlayedX;
    int LastPlayedY;
    Board Boards[3][3]; // Boardception :)
    bool SpecialMove = 1;

    void PrintBoard(int x, int y){
        cout << "---------------" << endl;
        for(int i=0; i < 3; i++){
            for(int j = 0;j<3;j++){
                int now = Boards[y-1][x-1].Whole[i][j];
                string Current = (now == 0) ? "|   | " : (now == 1) ? "| O | " : "| X | "; // long string ro print any board
                cout << Current;
                if (j == 2) cout << endl ;
            }
            cout << "---------------" << endl;
        }
    }
    void BoardWon(int x, int y, int WhoWon){
        Whole[y-1][x-1] = WhoWon; // Marks Who won on main board
    }
    void SelectBoard(int x,int y){
        X = y; // real y to board y
        Y = x; // real x to board x
    }
    void PlayWherever(bool who, int x, int y){
        //0 == O, 1 == X
        WhoPlayin = who;
        SelectBoard(x,y);
        PlayCurrent();
    }
    void PlayCurrent(){
        if (Whole[Y-1][X-1] != 0){
            SpecialMove = 1;
        }
        else
        {
            SpecialMove = 0;
            string Where = "";
            switch (Y){
                case 1:
                    Where.append("upper ");
                    break;
                case 2:
                    Where.append("middle ");
                    break;
                case 3:
                    Where.append("bottom ");
                    break;
            }
            switch (X){
                case 1:
                    Where.append("left");
                    break;
                case 2:
                    Where.append("total");
                    break;
                case 3:
                    Where.append("rigth");
                    break;
            }
            string Now = (WhoPlayin== true)? "X" : "O";
            cout << "---------------- Playing " << Now << " ----------------------\n";
            cout << "the current board is the " << Where << "and the current state is \n"; PrintBoard(X,Y);
            int Movex,Movey;
            cout << "tell me the coordinates you'd like to place an "<< Now <<" X: "; ;cin>>Movex;cout<<"y: ";cin>>Movey;
            while(Boards[Y-1][X-1].Whole[Movey-1][Movex-1] != 0){
                cout << "That spot is taken, try again, x: ";cin>>Movex;cout<<"y: ";cin>>Movey;
            }
            Boards[Y-1][X-1].Whole[Movey-1][Movex-1] = (WhoPlayin == false) ? 1 : 2;
            LastPlayedX = Movex; LastPlayedY = Movey; // store where last played to know what board to move to
            std::cout<< u8"\033[2J\033[1;1H";
        }
    }
    void Update(){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                Boards[i][j].IsWon();
                if (Boards[i][j].WhoWon != 0){
                    Whole[i][j] == Boards[i][j].WhoWon;
                }
            }
        }
    }
};

#endif // TICTACTOE_H_INCLUDED
