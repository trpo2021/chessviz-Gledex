#include "/home/pavel/Документы/TRPO/chessviz-Gledex/src/libchess/move.h"

#include <stdio.h>

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
    char turn[255] = {'\0'};
    fgets(turn, 6, stdin);
    move(turn, 5, cell[0]);
    display_cell(cell);
}
