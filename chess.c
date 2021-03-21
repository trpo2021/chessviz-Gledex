#include <stdio.h>
#include <string.h>

void start_cell(char* cell[8])
{
    *(cell) = "rnbqkbnr";
    *(cell + 1) = "pppppppp";
    *(cell + 6) = "PPPPPPPP";
    *(cell + 7) = "RNBQKBNR";
}

void display_cell(char* cell[])
{
    for (int i = 0; i < 8; ++i) {
        printf("\t\t %s\n", *(cell + i));
    }
}

int main()
{
    char* cell[8]
            = {"        ",
               "        ",
               "        ",
               "        ",
               "        ",
               "        ",
               "        ",
               "        "};
    start_cell(cell);
    display_cell(cell);
}
