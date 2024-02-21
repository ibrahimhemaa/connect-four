//
// Created by Lab Tech on 2/20/2024.
//

#ifndef FOLDERC___CONNECT_FOUR_H
#define FOLDERC___CONNECT_FOUR_H
#include <bits/stdc++.h>
using namespace std;
class connect_four {
public:
    char grid[7][6];
    void clear(){
        cout<<"Start New Game\n";
        for (int i = 0; i < 7; ++i) {
            for (int j = 0; j < 8; ++j) {
                grid[i][j]=' ';
            }
        }
    }
    bool sample_diagonal_forward(int position_i,int position_j){
        return ((grid[position_i][position_j]==grid[position_i+1][position_j-1])&&(grid[position_i+1][position_j-1]==grid[position_i+2][position_j-2])&&(grid[position_i+2][position_j-2]==grid[position_i+3][position_j-3]) && grid[position_i][position_j]!=' ');
    }
    bool sample_diagonal_backward(int position_i,int position_j){
        return ((grid[position_i][position_j]==grid[position_i-1][position_j+1])&&(grid[position_i-1][position_j+1]==grid[position_i-2][position_j+2])&&(grid[position_i-2][position_j+2]==grid[position_i-3][position_j+3])&&grid[position_i][position_j]!=' ');
    }
    bool diagonal(){
        for (int i = 0; i <7 ; ++i) {
            for (int j = 0; j <6 ; ++j) {
                if(i+3<7 && j-3>-1){
                    if(sample_diagonal_forward(i,j)){
                        return true;
                    }
                }
                if(i-3>-1 && j+3<6){
                    if(sample_diagonal_backward(i,j)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool sample_row(int position_i,int position_j){
        return ((grid[position_i][position_j]==grid[position_i][position_j+1])&&(grid[position_i][position_j+1]==grid[position_i][position_j+2])&&(grid[position_i][position_j+2]==grid[position_i][position_j+3]) && grid[position_i][position_j]!=' ');
    }
    bool row(){
        for (int i = 0; i <7 ; ++i) {
            for (int j = 0; j <3 ; ++j) {
                if(sample_row(i,j)){
                    return true;
                }
            }
        }
        return false;
    }
    bool sample_column(int position_i,int position_j){
        return ((grid[position_i][position_j]==grid[position_i+1][position_j])&&(grid[position_i+1][position_j]==grid[position_i+2][position_j])&&(grid[position_i+2][position_j]==grid[position_i+3][position_j]) && grid[position_i][position_j]!=' ');
    }
    bool column(){
        for (int j = 0; j < 6; ++j) {
            for (int i = 0; i < 4; ++i) {
                if(sample_column(i,j)){
                    return true;
                }
            }
        }
        return false;
    }
    bool win(){
        return (diagonal()|| row()|| column());
    }
    void print(){
        for (int i = 0; i <7 ; ++i) {
            for (int j = 0; j <6 ; ++j) {
                cout<<'['<<grid[i][j]<<']'<<" \n"[j==5];
            }
        }
    }
};

#endif //FOLDERC___CONNECT_FOUR_H
