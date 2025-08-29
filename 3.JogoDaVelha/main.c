#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

char game[SIZE][SIZE];

void clearScreen();
void clearGame();
void makeGame();
void getMove(char player);

int main() {

    return 0;
}

void getMove(char player) {
    makeGame();
    printf("\nVez do Jogador %c\n", player);

    int column;
    int line;
    printf("Digite a coluna da jogada: ");
    if(scanf("%d", &column) != 1) {
        printf("ERRO! O número deve ser inteiro.\nFim do programa");
        exit(1);
    } else if(column < 0 || column > 2) {
        printf("ERRO! Coluna não existente.\nFim do Programa");
        exit(1);
    }
}

void makeGame() {
    printf("   0    1    2\n");
    printf("0  %c  | %c  | %c\n", game[0][0], game[0][1], game[0][2]);
    printf("  ----+----+----\n");
    printf("1  %c  | %c  | %c\n", game[1][0], game[1][1], game[1][2]);
    printf("  ----+----+----\n");
    printf("2  %c  | %c  | %c\n", game[2][0], game[2][1], game[2][2]);

}

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void clearGame() {
    for(int line = 0; line < SIZE; line++) {
        for(int column = 0; column < SIZE; column++) {
            game[line][column] = ' ';
        }
    }
}
