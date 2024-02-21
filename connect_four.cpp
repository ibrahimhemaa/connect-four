//
// Created by Lab Tech on 2/20/2024.
//
#include "connect_four.h"
using namespace std;
int32_t main() {
    int counter=0;
    int flip=0;
    connect_four game;
    int column;
    game.clear();
    game.print();
    while (true){
        cout<<"Player "<<flip+1<<" go play :";
        cin>>column;
        column--;
        if(column<0 || column>=8 ||game.grid[0][column]!=' ' ) { continue; }
        int last=6;
        while (game.grid[last][column]!=' ' ){
            last--;
        }
        game.grid[last][column]=char('X'+flip);
        if(game.win()){
            cout<<"Player "<<char('X'+flip)<<" Win the Game\n";
            game.print();
            return 0;
        }
        counter++;
        flip=!flip;
        if(counter==7*6){
            game.print();
            game.clear();
            game.print();
            counter=0;
        }
    }
}
