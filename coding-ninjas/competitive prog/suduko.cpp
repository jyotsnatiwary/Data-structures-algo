#include<bits/stdc++.h>
using namespace std;

bool isPossible(int sudoku[9][9], int row, int col, int i){
    for(int j = 0; j<9; j++){
        if(sudoku[row][j] == i)
        return false;
    }

    for(int j=0; j<9; j++){
        if(sudoku[j][col]==i)
            return false;}
    
    int box_row = row/3;
    int box_col = col/3;
    for(int k=3*box_row; k<3*(box_row+1); k++){
        for(int j=3*box_col; j<3*(box_col+1); j++){
            if(sudoku[k][j] == i) 
                return false;
        }
    }
    return true;
}

void Sudoku_solver_helper(int sudoku[9][9], int row, int col, int flop){
    if(flop == true) return;
    if(row == 8 && col == 9){
        flop = true;
        for(int i=0; i<9;i++)
            {for(int j = 0; j<9; j++)
                cout<<sudoku[i][j]<<" ";
            cout<<endl;}
        return;
    }

    if(row<8 && col>8){
        Sudoku_solver_helper(sudoku, row+1, 0, flop);
        return;
    }

    if(sudoku[row][col] == 0){
        for(int i = 1; i<=9; i++){
            if(isPossible(sudoku, row, col, i)){
                sudoku[row][col] = i;
                Sudoku_solver_helper(sudoku, row, col+1, flop);
                sudoku[row][col] = 0;
            }
        }
    }
    else{
        Sudoku_solver_helper(sudoku, row, col+1, flop);
    }
    return;
}


void Sudoku_solver(int sudoku[9][9]){

    Sudoku_solver_helper(sudoku, 0, 0, false);

}
int main(){
    int sudoku[9][9];
    for(int i = 0; i<9; i++)
        for(int j = 0; j<9; j++)
            cin>>sudoku[i][j];
        
    Sudoku_solver(sudoku);

    
}
/*
0 2 3 4 5 6 7 8 9
4 0 6 7 8 9 1 2 3
7 8 0 1 2 3 4 5 6
2 3 4 0 5 6 7 8 9
5 6 7 8 0 1 2 3 4
8 9 1 2 3 0 5 6 7
3 4 5 6 7 8 0 1 2 
6 7 8 9 1 2 3 0 5
9 1 2 3 4 5 6 7 0
*/
