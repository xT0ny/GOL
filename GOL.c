#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h> 

#define ALIVE true
#define DEAD false
#define RED "\e[0;31m"
#define BLU "\e[0;34m"
#define GRN "\e[0;32m"
#define WHT "\e[0;37m"

#define H 50
#define L 50

typedef enum colors{
    COLOR_RED,
    COLOR_BLUE,
    COLOR_GREEN,
    COLOR_WHITE,
}COLOR;

struct cell{
    int neighbours;
    bool state;
    COLOR color;
};


void init(struct cell table[H][L]){
    for (int i = 0; i < H; i++){
        for (int j = 0; j < L; j++){
            table[i][j].state = DEAD;
            table[i][j].neighbours = 0;
            table[i][j].color = COLOR_WHITE;    
        }
    }

    srand(time(NULL));
    int cell_counter = 0;
    while(cell_counter < 15){
        int i = rand() % L;
        int j = rand() % H;
        if (table[i][j].state == DEAD){
            table[i][j].state = ALIVE;
            table[i][j].color = rand() % 3;
            cell_counter++;
        }
    }

}

int main(void){
    struct cell table[H][L];
    init(table);
    return 0;
}