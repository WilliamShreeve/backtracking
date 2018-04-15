#include <iostream>
#include "../include/sudoku.h"

Sudoku::Sudoku(){

}
bool Sudoku::solve(int board[9][9]){
	
	int row, col;
	
	//If there is no empty spots, return true
	//This ends the recursive backtracking process
	if(nextEmpty(board, row, col)){
		//If true, then return true to end process:
		//AKA board is full, board is solved
		return true;
	}

	//Loop through possible values to place
	for(int i = 1; i <= 9; i++){
		//If the number isn't in row, column, or square
		if(notInRow(board, i, row) &&
		   notInCol(board, i, col) &&
		   notInSquare(board, i, row, col)){
			//Try the current value of i in the spot
			board[row][col] = i;

			//Call solve once more to recursively solve
			if(solve(board))
				return true;
			//If no solution is found, reset board's spot
			else
				board[row][col] = 0;
		}
	}
	//Enable backtracking
	return false;
}

//Examined some code to see what the best way of dealing with row and col params
//were. Tried using structs as a return type, with no luck.
//Got the reference passing idea from:
//https://stackoverflow.com/questions/40702099/solve-sudoku-with-backtracking-c
bool Sudoku::nextEmpty(int board[9][9], int &row, int &col){
	//Checks if spot is empty (0 is our empty variable)
	for(row = 0; row < 9; row++){
		for(col = 0; col < 9; col++){
			if(board[row][col] == 0)
				return false;
		}
	}
	return true;
}

bool Sudoku::notInRow(int board[9][9], int n, int r){
	//Iterate through column to check if num is already there.
	//std::cout << "inRow" << std::endl;
	for(int i = 0; i < 9; i++){
		if(board[r][i] == n)
			return false;
	}
	return true;
}

bool Sudoku::notInCol(int board[9][9], int n, int c){

	//Iterate through column to check if num is already there.
	for(int i = 0; i < 9; i++){
		if(board[i][c] == n)
			return false;
	}
	return true;
}

bool Sudoku::notInSquare(int board[9][9], int n, int r, int c){
	//Get starting square index
	int row = (r - r%3);
	int col = (c - c%3);
	
	for(int i = 0; i < 3 ; i++){
		for(int j = 0; j < 3; j++){
			if(board[i+row][j+col] == n)
				return false;
		}
	}
	return true;	
}

void Sudoku::print(int board[9][9]){
	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 9; j++){
			std::cout << board[i][j] << " ";
		}
		std::cout << std::endl;
	}		
}



