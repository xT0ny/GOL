#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h> 

#define ALIVE true
#define DEAD false
#define RED "\x1b[31m"
#define BLUE "\x1b[34m"
#define GREEN "\x1b[32m"

const int H = 50;
const int L = 50;

typedef enum colors{
    COLOR_RED,
    COLOR_BLUE,
    COLOR_GREEN,
}COLOR;

struct cell{
    int neighbours;
    bool state;
    char *color;
};

char *set_random_color(){
    COLOR cell_color = rand()%3;
    char *final_cell_color;
        switch(cell_color){
            case 1:
                final_cell_color = RED;
                break;

            case 2:
                final_cell_color = BLUE;
                break;
            
            case 3:
                final_cell_color = GREEN;
                break;
        }
    return final_cell_color;
}

void init(struct cell table[H][L]){
    for (int i = 0; i < H; i++){
        for (int j = 0; j < L; j++){
            table[i][j].state = DEAD;
            table[i][j].neighbours = 0;
            table[i][j].color = " ";    
        }
    }
    
    srand(time(NULL));
    int i = rand() %51;
    int j = rand() %51;
    if (table[i][j].state == DEAD){
        table[i][j].state = ALIVE;
        table[i][j].color = set_random_color();
    }

}

void main(){
    struct cell table[H][L];
    init(table);
    return;
}