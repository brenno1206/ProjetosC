#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

char game[SIZE][SIZE];

void clearScreen();
void clearGame();
void makeGame();
void getMove(char player);
void verifyGame();

int main() {

    clearGame();

    while(1) {
        getMove('x');
        getMove('o');
    }
    return 0;
}

void verifyGame() {
    /** Possibilities of win
     *  00 11 22 OK
     *  02 11 20 OK
     *  00 01 02 OK
     *  10 11 12 OK
     *  20 21 22 OK
     *  00 10 20 OK
     *  01 11 21 OK
     *  02 21 22 OK
     */

    if((game[0][0] == game[1][1] && game[1][1] == game[2][2] && game[2][2] != ' '))
        printf("O jogador %c ganhou\nFim do Programa\n", game[0][0]);
    else if((game[0][2] == game[1][1] && game[1][1] == game[2][0] && game[2][0] != ' '))
        printf("O jogador %c ganhou\nFim do Programa\n", game[0][2]);
    else if((game[0][0] == game[0][1] && game[0][1] == game[0][2] && game[0][2] != ' '))
        printf("O jogador %c ganhou\nFim do Programa\n", game[0][0]);
    else if((game[1][0] == game[1][1] && game[1][1] == game[1][2] && game[1][2] != ' '))
        printf("O jogador %c ganhou\nFim do Programa\n", game[1][0]);
    else if((game[2][0] == game[2][1] && game[2][1] == game[2][2] && game[2][2] != ' '))
        printf("O jogador %c ganhou\nFim do Programa\n", game[2][0]);
    else if((game[0][0] == game[1][0] && game[1][0] == game[2][0] && game[2][0] != ' '))
        printf("O jogador %c ganhou\nFim do Programa\n", game[0][0]);
    else if((game[0][1] == game[1][1] && game[1][1] == game[2][1] && game[2][1] != ' '))
        printf("O jogador %c ganhou\nFim do Programa\n", game[0][1]);
    else if((game[0][2] == game[2][1] && game[2][1] == game[2][2] && game[2][2] != ' '))
        printf("O jogador %c ganhou\nFim do Programa\n", game[0][2]);
    else {
        for(int line = 0; line < SIZE; line++) {
            for(int column = 0; column < SIZE; column++) {
                if(game[line][column] == ' ')
                    return;
            }
        }
        printf("Deu Velha! Nenhum jogador ganhou\nFim do Programa\n");
    }
    exit(0);


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
    } else {
        printf("Digite a linha da jogada: ");
        if(scanf("%d", &line) != 1) {
            printf("ERRO! O número deve ser inteiro.\nFim do programa");
            exit(1);
        } else if(line < 0 || line > 2) {
            printf("ERRO! linha não existente.\nFim do Programa");
            exit(1);
        }
        if(game[line][column] == ' ') {
            game[line][column] = player;
        } else {
            printf("Essa coluna já foi preenchida!\nPreste mais atenção da próxima vez!\nFim do Programa");
            exit(1);
        }
    }
    makeGame();
    verifyGame();
}

void makeGame() {
    clearScreen();
    printf("   0    1    2\n");
    printf("0  %c  | %c   | %c\n", game[0][0], game[0][1], game[0][2]);
    printf("  ----+----+----\n");
    printf("1  %c  | %c   | %c\n", game[1][0], game[1][1], game[1][2]);
    printf("  ----+----+----\n");
    printf("2  %c  | %c   | %c\n", game[2][0], game[2][1], game[2][2]);

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
