#include <stdio.h>
#include <stdlib.h>

void criarJogo(char vetor[3][3]);
int resultado(char vetor[3][3]);
void jogada(char vetor[3][3], char tipo);

int main() {

    char dados[3][3];
    for(int a = 0; a < 3; a++) {
        for(int b = 0; b < 3; b++) {
            dados[a][b] = ' ';
        }
    }
    
    do {
        criarJogo(dados);
        jogada(dados, 'x');
        criarJogo(dados);
        resultado(dados);
        jogada(dados, 'o');
        criarJogo(dados);
        resultado(dados);
        
    } while (!resultado(dados));



    return 0;
}




void criarJogo(char vetor[3][3]) {
    system("clear");
    printf("  0 1 2\n");
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(j == 0) {
                printf("%d %c", i, vetor[i][j]);
            }
            else {
                printf("|%c", vetor[i][j]);
            }
        }
        if (i != 2) {
            printf("\n--------\n");
        }
    }
}

void jogada(char vetor[3][3], char tipo) {
    int linha, coluna;
    do {
        if (tipo == 'x') {
            printf("\nJogador 1: Marque onde você vai colocar o x:\n linha: ");
            scanf("%d", &linha);
            printf("coluna: ");
            scanf("%d", &coluna);
    
            if(vetor[linha][coluna] == ' ') {
                vetor[linha][coluna] = 'x';
                break;
            } else {
                printf("Coluna e linha já preenchidas. Tente novamente.\n");
                continue;
            }
        
        } else {
            printf("\nJogador 2: Marque onde você vai colocar o x:\n linha: ");
            scanf("%d", &linha);
            printf("coluna: ");
            scanf("%d", &coluna);

            if(vetor[linha][coluna] == ' ') {
                vetor[linha][coluna] = 'o';
                break;
            } else {
                printf("Coluna e linha já preenchidas. Tente novamente.\n");
                continue;
            }
        
        }
    } while(1);
}




int resultado(char vetor[3][3]) {
    for( int i = 0; i < 3; i++) {
        if(vetor[i][0] != ' ' && vetor[i][0] == vetor[i][1] == vetor[i][2]) {
            if (vetor[i][0] == 'x') {
                printf("O Jogador 1 é o vencedor.\n");
            }
            else {
                printf("O Jogador 2 é o vencedor.\n");
            }
            return 1;
        }
    }
    for(int j = 0; j < 3; j++) {
        if(vetor[0][j] != ' ' && vetor[0][j] == vetor[1][j] == vetor[2][j]) {
            if (vetor[0][j] == 'x') {
                printf("O Jogador 1 é o vencedor.\n");
            }
            else {
                printf("O Jogador 2 é o vencedor.\n");
            }
            return 1;
        }
    }
    if(vetor[0][0] != ' ' && vetor[0][0] == vetor[1][1] == vetor[2][2]) {
        if (vetor[0][0] == 'x') {
            printf("O Jogador 1 é o vencedor.\n");
        }
        else {
            printf("O Jogador 2 é o vencedor.\n");
        }
        return 1;
    }
    if(vetor[0][2] != ' ' && vetor[0][2] == vetor[1][1] == vetor[2][0]) {
        if (vetor[0][2] == 'x') {
            printf("O Jogador 1 é o vencedor.\n");
        }
        else {
            printf("O Jogador 2 é o vencedor.\n");
        }
        return 1;
    }
    for( int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if(vetor[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}