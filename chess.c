#include <stdio.h>
#include <string.h>

void start_cell(char cell[][9])
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

void display_cell(char cell[8][9])
{
    printf("\n");
    for (int i = 0; i < 8; i++) {
        printf("\t\t%s\n", cell[i]);
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
    char* sym = cell[0];
    start_cell(cell);
    display_cell(cell);
}
