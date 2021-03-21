
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    int lit;
    int num;
} cord;

void swap(char* a, char* b)
{
    char c = *a;
    *a = *b;
    *b = c;
}
int lit_to_int(char lit)
{
    char abc[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    for (int i = 0; i < 8; i++) {
        if (lit == abc[i]) {
            return i;
            break;
        }
    }
    return -1;
}
void parse(char str[], int n, cord* start, cord* end)
{
    int i = 0;
    if (isalpha(str[i])) {
        if (lit_to_int(str[i]) != -1) {
            start->lit = lit_to_int(str[i]);
        };
    }
    i++;
    if (isalnum(str[i])) {
        start->num = atoi(&str[i]) - 1;
    }
    i++;
    if (ispunct(str[i])) {
        i++;
    }
    if (isalpha(str[i])) {
        if (lit_to_int(str[i]) != -1) {
            end->lit = lit_to_int(str[i]);
        };
    }
    i++;
    if (isalnum(str[i])) {
        end->num = atoi(&str[i]) - 1;
    }
}
void display_cell(char cell[8][9])
{
    printf("\n");
    for (int i = 0; i < 8; i++) {
        printf("\t\t%s\n", cell[i]);
    }
}
void move(char turn[], int n, char* cell)
{
    cord start;
    cord end;
    parse(turn, n, &start, &end);
    printf("Start:%d %d", start.lit, start.num);
    printf("End:%d %d", end.lit, end.num);
    char figure = *(cell + start.num * 9 + start.lit);
    *(cell + start.num * 9 + start.lit) = ' ';
    *(cell + end.num * 9 + end.lit) = figure;
    //*(cell[start.num] + start.lit) = *figure;
    // printf("%c", *(cell[start.num] + start.lit));
    // display_cell(cell);

    // figure = (cell[end.num] + end.lit);
    //*figure = 'p';
}
int main()
{
    char cell[8][9]
            = {"rnbqkbnr\0",
               "pppppppp\0",
               "        \0",
               "        \0",
               "        \0",
               "        \0",
               "PPPPPPPP\0",
               "RNBQKBNR\0"};

    char* sym = cell[0];
    display_cell(cell);
    char turn[255] = {'\0'};
    fgets(turn, 6, stdin);
    printf("%s\n", turn);
    move(turn, 5, sym);
    display_cell(cell);
}