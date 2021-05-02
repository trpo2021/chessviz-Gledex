#pragma once
typedef struct {
    int lit;
    int num;
} cord;
void swap(char* a, char* b);
int lit_to_int(char lit);
void parse(char str[], int n, cord* start, cord* end);
void move(char turn[], int n, char* cell);
