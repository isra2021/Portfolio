#include "assert.h"
#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"

#define BOARD_SIZE 3
#define CELL_MAX (BOARD_SIZE * BOARD_SIZE - 1)

void print_board(char board[BOARD_SIZE][BOARD_SIZE])
{
    int cell = 0;
    printf("\t .................................................\n");
    for (int row = 0; row < BOARD_SIZE; ++row) {
        for (int column = 0; column < BOARD_SIZE; ++column) {
            printf("\t | %d: %c ", cell, board[row][column]);
            ++cell;
        }
        printf("\t | \n");
        printf("\t .................................................\n");
    }
}

char get_winner(char board[BOARD_SIZE][BOARD_SIZE])
{
    char winner = '-';
    for(unsigned int i = 0; i < BOARD_SIZE; i++)
    {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2])
            winner = board[i][0];
        
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i])
            winner = board[0][i];
    }
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2])
        winner = board[0][0];
    
    if(board[0][2] == board[1][1] && board[1][1] == board[0][2])
        winner = board[0][2];
    
    return winner;
}

unsigned int count_cell(char board[BOARD_SIZE][BOARD_SIZE]){
    unsigned int count = 0;
    for(unsigned int row = 0; row < BOARD_SIZE; ++row){
        for(unsigned int column = 0; column < BOARD_SIZE; ++column){
            if(board[row][column] == '-'){
                ++count;
            }
        }
    }
    return count;
}


bool has_free_cell(char board[BOARD_SIZE][BOARD_SIZE]){
    return count_cell(board) > 0;
}

/*
bool has_free_cell(char board[BOARD_SIZE][BOARD_SIZE])
{
    for (unsigned int i = 0; i < BOARD_SIZE; i++)
    {   
        for (unsigned int j = 0; j < BOARD_SIZE; j++)
        {
            if(board[i][j] == '-')
                return true;
        }   
    }
    return false;
}
*/

int main(void)
{
    printf("TicTacToe [ComPleTo :)]\n");

    char board[BOARD_SIZE][BOARD_SIZE] = {
        { '-', '-', '-' },
        { '-', '-', '-' },
        { '-', '-', '-' }
    };

    char turn = 'X';
    char winner = '-';
    int cell = 0;
    while (winner == '-' && has_free_cell(board)) {
        print_board(board);
        printf("\nTurno %c - Elija posición (número del 0 al 8): ",
               turn);
        int scanf_result = scanf("%d", &cell);
        if (scanf_result <= 0) {
            printf("Error al leer un número desde teclado\n");
            exit(EXIT_FAILURE);
        }
        if (cell >= 0 && cell <= CELL_MAX) {
            int row = cell / BOARD_SIZE;
            int colum = cell % BOARD_SIZE;
            if (board[row][colum] == '-') {
                board[row][colum] = turn;
                turn = turn == 'X' ? 'O' : 'X';
                winner = get_winner(board);
            } else {
                printf("\nCelda ocupada!\n");
            }
        } else {
            printf("\nCelda inválida!\n");
        }
    }
    print_board(board);
    if (winner == '-') {
        printf("Empate!\n");
    } else {
        printf("Ganó %c\n", winner);
    }
    return 0;
}
