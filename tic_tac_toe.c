#include <stdio.h>

#define SIZE 3


void displayBoard(char board[SIZE][SIZE]);
int checkWin(char board[SIZE][SIZE]);


int main() {
    char board[SIZE][SIZE] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
    int choice, player = 1, result = 0;
    char mark;


    do {
        displayBoard(board);
        player = (player % 2) ? 1 : 2;
        mark = (player == 1) ? 'X' : 'O';


        printf("Player %d, enter a number: ", player);
        scanf("%d", &choice);


        if (choice == 1 && board[0][0] == '1') board[0][0] = mark;
        else if (choice == 2 && board[0][1] == '2') board[0][1] = mark;
        else if (choice == 3 && board[0][2] == '3') board[0][2] = mark;
        else if (choice == 4 && board[1][0] == '4') board[1][0] = mark;
        else if (choice == 5 && board[1][1] == '5') board[1][1] = mark;
        else if (choice == 6 && board[1][2] == '6') board[1][2] = mark;
        else if (choice == 7 && board[2][0] == '7') board[2][0] = mark;
        else if (choice == 8 && board[2][1] == '8') board[2][1] = mark;
        else if (choice == 9 && board[2][2] == '9') board[2][2] = mark;
        else {
            printf("Invalid move!\n");
            player--;
        }


        result = checkWin(board);
        player++;

    } while (result == 0);

    displayBoard(board);

    if (result == 1) {
        printf("Player %d wins!\n", --player);
    } else {
        printf("It's a draw!\n");
    }

    return 0;
}


void displayBoard(char board[SIZE][SIZE]) {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) printf("---|---|---\n");
    }
    printf("\n");
}


int checkWin(char board[SIZE][SIZE]) {

    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return 1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return 1;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return 1;


    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') return 0;
        }
    }
    return -1;
}
