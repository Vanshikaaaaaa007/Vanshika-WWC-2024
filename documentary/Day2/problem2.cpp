#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
    for (int i = 0; i < 9; ++i) {
        unordered_set<char> rows, cols, box;
        for (int j = 0; j < 9; ++j) {
            // Check the row
            if (board[i][j] != '.' && rows.count(board[i][j])) return false;
            rows.insert(board[i][j]);

            // Check the column
            if (board[j][i] != '.' && cols.count(board[j][i])) return false;
            cols.insert(board[j][i]);

            // Check the 3x3 sub-box
            int boxRow = 3 * (i / 3) + j / 3;
            int boxCol = 3 * (i % 3) + j % 3;
            if (board[boxRow][boxCol] != '.' && box.count(board[boxRow][boxCol])) return false;
            box.insert(board[boxRow][boxCol]);
        }
    }
    return true;
}

int main() {
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    cout << "Is the Sudoku board valid? " << (isValidSudoku(board) ? "Yes" : "No") << endl;
    return 0;
}
