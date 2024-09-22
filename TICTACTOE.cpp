#include <stdio.h>

char board[3][3];

void initializeBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
    int count = 1;
    printf("\n\n\t  ");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d", count++);
            if (j < 2) {
                printf("  |  ");
            }
        }
        if (i < 2) printf("\n\t----------------\n\t  ");
    }
    printf("\n\n\n");
}

void showBoard() {
    printf("\n\n\t  ");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c", board[i][j]);
            if (j < 2) {
                printf("  |  ");
            }
        }
        if (i < 2) printf("\n\t----------------\n\t  ");
    }
    printf("\n\n\n");
}

int updateBoard(int cell, char playerSign) {
    int row = (cell - 1) / 3;
    int col = (cell - 1) % 3;
    int isValid = 1;
    if (board[row][col] != ' ') {
        printf("\nInvalid: Cell is already Filled!\n");
        isValid = 0;
    } else {
        board[row][col] = playerSign;
    }
    showBoard();
    return isValid;
}

int checkWinner(char sg) {
    if (board[0][0] == sg && board[0][1] == sg && board[0][2] == sg ||
        board[1][0] == sg && board[1][1] == sg && board[1][2] == sg ||
        board[2][0] == sg && board[2][1] == sg && board[2][2] == sg) {
        return 1;
    } else if (board[0][0] == sg && board[1][0] == sg && board[2][0] == sg ||
               board[0][1] == sg && board[1][1] == sg && board[2][1] == sg ||
               board[0][2] == sg && board[1][2] == sg && board[2][2] == sg) {
        return 1;
    } else if (board[0][0] == sg && board[1][1] == sg && board[2][2] == sg ||
               board[0][2] == sg && board[1][1] == sg && board[2][0] == sg) {
        return 1;
    }
    return 0;
}

void playTicTacToe() {
    int gameResult = 0;
    int cell = 0;
    int playCount = 0;
    char playerSign = ' ';

    initializeBoard();
    while (!gameResult && playCount < 9) {
        if (playCount % 2 == 0) {
            printf("\nPlayer 1 [ X ] : ");
            playerSign = 'X';
        } else {
            printf("\nPlayer 2 [ O ] : ");
            playerSign = 'O';
        }
        scanf("%d", &cell);
        if (cell > 0 && cell < 10) {
            if (updateBoard(cell, playerSign)) {
                gameResult = checkWinner(playerSign);
                if (gameResult) {
                    printf("\t *** Player %d Won!! ***\n", playerSign == 'X' ? 1 : 2);
                }
                playCount++;
            }
        } else {
            printf("\nInvalid cell value\n");
        }
    }
    if (!gameResult && playCount == 9) {
        printf("\n\t *** Draw... ***\n");
    }
    printf("\n\t --- Game Over --- \n");
}

int main() {  // Entry point of the program
    printf("--------- Tic Tac Toe ----------\n\n");
    printf("\n* Instructions: Player 1 sign = X, Player 2 sign = O\n");

    playTicTacToe();  // Start the Tic Tac Toe game

    printf("\n :: Thanks for playing Tic Tac Toe game! :: \n");
    return 0;
}

