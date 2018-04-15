

class Sudoku{


	private:
		bool nextEmpty(int board[9][9], int &row, int &col);
		bool notInRow(int board[9][9], int n, int r);
		bool notInCol(int board[9][9], int n, int c);
		bool notInSquare(int board[9][9], int n, int r, int c);
	public:
		void print(int board[9][9]);
		bool solve(int board[9][9]);
		Sudoku();

};
