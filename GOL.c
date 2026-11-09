#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h> 
#include <windows.h>

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
    bool state;
    COLOR color;
};

int count_neighbours(struct cell table[H][L], int i, int j){
    int count = 0;
    for (int h = -1; h <= 1; h++){
        for (int l = -1; l <= 1; l++){
            if(h == 0 && l == 0){
                continue;
            }
            if (i + h >= 0 && i + h < H && j + l >= 0 && j + l < L && table[i+h][j+l].state == ALIVE){
                count++;
            }
        }
    }
    return count;
}

void update(struct cell table[H][L]){
    struct cell next[H][L];
    for (int i = 0; i < H; i++){
        for(int j = 0; j < L; j++){
            next[i][j] = table[i][j];            
            int neighbours = count_neighbours(table, i, j);
            if(table[i][j].state == DEAD){              
              if(neighbours == 3){
                next[i][j].state = ALIVE;
                next[i][j].color = rand()%3;
              }
            }
            else{
                if(neighbours < 2 || neighbours > 3){
                    next[i][j].state = DEAD;
                    next[i][j].color = COLOR_WHITE;
                }
            }
        }
    }
    for (int i = 0; i < H; i++){
        for (int j = 0; j < L; j++){
            table[i][j] = next[i][j];
        }
    }
    return;
}

void init(struct cell table[H][L]){
    for (int i = 0; i < H; i++){
        for (int j = 0; j < L; j++){
            table[i][j].state = DEAD;
            table[i][j].color = COLOR_WHITE;    
        }
    }

    srand(time(NULL));
    int cell_counter = 0;
    while(cell_counter < 600){
        int i = rand() % L;
        int j = rand() % H;
        if (table[i][j].state == DEAD){
            table[i][j].state = ALIVE;
            table[i][j].color = rand() % 3;

            cell_counter++;
        }
    }
    return;
}

void render(struct cell table[H][L]){
    for (int i = 0; i < H; i++){
        for (int j = 0; j < L; j++){
            if (table[i][j].color == COLOR_RED){
                printf(RED "\u2588");
            }
            else if (table[i][j].color == COLOR_BLUE){
                printf(BLU "\u2588");
            }
            else if (table[i][j].color == COLOR_GREEN){
                printf(GRN "\u2588");
            }
            else {
                printf(WHT "\u2588");
            }
        }
        printf("\n");
    }
}

void clear_term(void){
    Sleep(1000);
    system("cls");
}

int main(void){
    SetConsoleOutputCP(CP_UTF8);
    struct cell table[H][L];
    init(table);
    while(1){
        clear_term();
        render(table);
        update(table);
    }
}