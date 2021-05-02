#include "move.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static void start_cell(char cell[][9])
{
    char first_row[9] = {"rnbqkbnr\0"};
    char sec_row[9] = {"pppppppp\0"};
    char sev_row[9] = {"PPPPPPPP\0"};
    char ei_row[9] = {"RNBQKBNR\0"};
    for (int i = 0; i < 9; i++) {
        cell[0][i] = first_row[i];
    }
    for (int i = 0; i < 9; i++) {
        cell[1][i] = sec_row[i];
    }
    for (int i = 0; i < 9; i++) {
        cell[6][i] = sev_row[i];
    }
    for (int i = 0; i < 9; i++) {
        cell[7][i] = ei_row[i];
    }
}
static void display_cell(char cell[8][9])
{
    char digits[] = "12345678";
    printf("\n\t\t  ABCDEFGH\n");
    for (int i = 0; i < 8; i++) {
        printf("\t\t%c %s\n", digits[i], cell[i]);
    }
}

int main()
{
    char cell[8][9]
            = {"        \0",
               "        \0",
               "        \0",
               "        \0",
               "        \0",
               "        \0",
               "        \0",
               "        \0"};
    start_cell(cell);
    display_cell(cell);
    char turn[8];
    int game_state = 1;

    while (game_state != 0) {
        scanf("%s", turn);
        if (turn[0] == '-') {
            printf("Second player,type '-' if u agree with finishing the "
                   "game\n");
            scanf("%s", turn);
            if (turn[0] == '-') {
                game_state = 0;
                printf("end\n");
                break;
            }
        }
        move(turn, 7, cell[0]);
        display_cell(cell);
    }
}
