#include <iostream>
using namespace std;

// Function to initialize the game board
void initializeBoard(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

// Function to display the board
void displayBoard(char board[3][3]) {
    cout << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << " " << board[i][j] << " ";
            if (j < 2) cout << "|";
        }
        cout << endl;
        if (i < 2) {
            cout << "---|---|---" << endl;
        }
    }
    cout << endl;
}

// Function to check if a player has won
bool checkWin(char board[3][3], char player) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }
    // Check columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            return true;
        }
    }
    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }

    return false;
}

// Function to check if the board is full (i.e., it's a draw)
bool isBoardFull(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false;  // Found an empty space, so the board is not full
            }
        }
    }
    return true;  // Board is full
}

// Function to take player input
bool takeTurn(char board[3][3], char player) {
    int row, col;
    cout << "Player " << player << ", enter row (1-3) and column (1-3): ";
    cin >> row >> col;

    // Adjust for 0-indexed array
    row--;
    col--;

    // Check if the move is valid (inside bounds and the cell is empty)
    if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
        board[row][col] = player;
        return true;
    } else {
        cout << "Invalid move, try again." << endl;
        return false;
    }
}

// Main function to run the Tic Tac Toe game
int main() {
    char board[3][3];
    char currentPlayer = 'X';  // Player 'X' starts
    bool gameOver = false;

    // Initialize the board
    initializeBoard(board);

    // Game loop
    while (!gameOver) {
        displayBoard(board);  // Display the current board

        // Get player input
        bool validMove = false;
        while (!validMove) {
            validMove = takeTurn(board, currentPlayer);
        }

        // Check if the current player has won
        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            cout << "Player " << currentPlayer << " wins!" << endl;
            gameOver = true;
        } 
        // Check if the board is full (draw)
        else if (isBoardFull(board)) {
            displayBoard(board);
            cout << "It's a draw!" << endl;
            gameOver = true;
        } 
        // Switch to the other player
        else {
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }

    return 0;
}
