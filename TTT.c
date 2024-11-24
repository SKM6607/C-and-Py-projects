#include <stdio.h>  // Include standard input-output library
// Define the game board
char board[3][3];
// Keep track of the current player ('X' or 'O')
char turn = 'X';
// Variables for row and column input
int row, col;
// Counter for the number of moves
int moves = 0;
int i,j;
// Function to initialize the game board with empty spaces
void initializeBoard() {
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}
// Function to print the game board
void printBoard() {
    printf("  0 1 2\n");
    for ( i = 0; i < 3; i++) {
        printf("%d ", i);
        for (j = 0; j < 3; j++) {
            printf("%c", board[i][j]);
            if (j < 2) printf("|");  // Print column separators
        }
        printf("\n");
        if (i < 2) printf("  -----\n");  // Print row separators
    }
}
// Function to check if the current player has won
int checkWin() {
    // Check rows and columns
    for ( i = 0; i < 3; i++) {
        if (board[i][0] == turn && board[i][1] == turn && board[i][2] == turn) return 1;
        if (board[0][i] == turn && board[1][i] == turn && board[2][i] == turn) return 1;
    }
    // Check diagonals
    if (board[0][0] == turn && board[1][1] == turn && board[2][2] == turn) return 1;
    if (board[0][2] == turn && board[1][1] == turn && board[2][0] == turn) return 1;
    return 0;
}
// Function to handle a player's turn
void playTurn() {
    if (board[row][col] == ' ') {  // Check if the cell is empty
        board[row][col] = turn;  // Place the player's mark
        moves++;  // Increment move counter
    } else {
        printf("Invalid move. Try again.\n");  // Invalid move message
    }
}
// Function to switch the current player
void switchTurn() {
    turn = (turn == 'X') ? 'O' : 'X';
}

int main() {
    initializeBoard();  // Initialize the game board
    while (1) {  // Infinite loop for the game
        printBoard();  // Print the game board
        printf("Player %c, enter row and column: ", turn);
        scanf("%d %d", &row, &col);  // Read player's move
        playTurn();  // Process the move
        if (checkWin()) {  // Check for win
            printBoard();  // Print the final board
            printf("Player %c wins!\n", turn);
            break;  // Exit the loop
        }
        if (moves == 9) {  // Check for a draw
            printBoard();
            printf("It's a draw!\n");
            break;
        }
        switchTurn();  // Switch player turn
    }
    return 0;  // End of the program
}

