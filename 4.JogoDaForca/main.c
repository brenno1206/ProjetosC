#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void limparTela();
int pegarPalavra(char palavra[20], int tamanhoMax);
void construirForca(char palavra[20], char secreto[20], int tamanho);
void palpite(char palavra[20], char secreto[20], char chutes[26], int tamanho);

int tentativa = 0;

int main() {
    char palavra[20]; 
    char chutes[26];
    int comprimento = pegarPalavra(palavra, sizeof(palavra));

    char palavra_secreta[20]; 
    memset(palavra_secreta, '_', comprimento);
    palavra_secreta[comprimento] = '\0';

    while(1) {
        construirForca(palavra, palavra_secreta, comprimento);
        palpite(palavra, palavra_secreta, chutes, comprimento);
    }
    return 0;
}

void limparTela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int pegarPalavra(char palavra[20], int tamanhoMax) {
    int tamanho;

    while (1) {
        printf("Digite uma palavra de 4 a 10 caracteres: ");

        if (fgets(palavra, tamanhoMax, stdin) == NULL) {
            printf("Erro ao ler entrada. Tente novamente.\n");
            continue;
        }

        tamanho = strlen(palavra);
        if (palavra[tamanho - 1] == '\n') {
            palavra[tamanho - 1] = '\0';
            tamanho--;
        }

        if (tamanho >= tamanhoMax - 1) {
            printf("A palavra digitada é muito longa. Tente novamente.\n");
            while (getchar() != '\n' && getchar() != EOF);
            continue;
        }

        if (tamanho < 4 || tamanho > 10) {
            printf("A palavra não está no tamanho descrito. Tente novamente.\n");
            continue;
        }

        for(int i = 0; i < tamanho; i++) {
            if(isalpha(palavra[i]) == 0) {
                printf("Há um caractere que não é uma letra. Tente novamente.\n");
                return pegarPalavra(palavra, tamanhoMax);
            }
        }
        break;
    }
    for(int j = 0; j < tamanho; j++) {
        palavra[j] = tolower(palavra[j]);
    }
    limparTela();
    return tamanho;
}

void construirForca(char palavra[20], char secreto[20], int tamanho) {
    printf("   _\n");
    printf("  / |\n");

    switch (tentativa)
    {
        case 6: {
            printf(" | \\O/\n");
            printf(" |  |\n");
            printf(" | / \\\n");
            
            break;
        }
        case 5: {
            printf(" | \\O/\n");
            printf(" |  |\n");
            printf(" | / \n");
            
            break;
        }
        case 4: {
            printf(" | \\O/\n");
            printf(" |  |\n");
            printf(" |   \n");
            
            break;
        }
        case 3: {
            printf(" | \\O/\n");
            printf(" |  \n");
            printf(" |   \n");
            
            break;
        }
        case 2: {
            printf(" |  O/\n");
            printf(" |  \n");
            printf(" |   \n");
            
            break;
        }
        case 1: {
            printf(" |  O\n");
            printf(" |  \n");
            printf(" |   \n");
            
            break;
        }
        default: {
            printf(" |  \n");
            printf(" |  \n");
            printf(" |   \n");
        
            break;
        }
    }


    printf(" |\n");
    printf("_|_    ");

    for(int i = 0; i < tamanho; i++) {
        printf("%c ", secreto[i]);
    }
    printf("\n");
    if(tentativa  == 6) {
        printf("Você perdeu! A palavra era [%s]", palavra);
        exit(0);
    }
}

void palpite(char palavra[20], char secreto[20], char chutes[26], int tamanho){
    while(1) {
        int escolha;
        char letra;
        char palavra_palpite[20];
        int result = 0;

        printf("\n Você deseja chutar uma letra(0) ou a palavra(1): ");
        if (scanf(" %d", &escolha) != 1 || (escolha != 0 && escolha != 1)) {
            while (getchar() != '\n');
            printf("Entrada inválida! Por favor, digite 0 ou 1.\n");
            continue;

        } else if(escolha == 0) {
            printf("Digite seu palpite: ");
            if (scanf(" %c", &letra) != 1) {
                while (getchar() != '\n');
                printf("palpite inválido. Escolha uma letra.\n");
                continue;
            }
            for(int i = 0; i < 26; i++) {
                if (letra == chutes[i]) {
                    printf("Palpite já feito.\n");
                    return;
                }
            }
            for(int j = 0; j < tamanho; j++) {
                if(palavra[j] == tolower(letra)) {
                    secreto[j] = letra;
                    result = 1;
                    if(strcmp(secreto,palavra) == 0) {
                        printf("Parabéns você acertou, a palavra é %s", secreto);
                        return;
                    }
                }
            }
            if(result == 1) {
                return;
            }
            else {
                chutes[tentativa] = letra;
                tentativa += 1;
                return;
            }

        } else if(escolha == 1) {
            printf("Digite seu palpite: ");
            while (getchar() != '\n');
            if (fgets(palavra_palpite, 20, stdin) == NULL) {
                printf("Erro ao ler entrada. Tente novamente.\n");
                continue;
            }
            palavra_palpite[strcspn(palavra_palpite, "\n")] = '\0'; 
            for(int k = 0; k < tamanho; k++) {
                palavra_palpite[k] = tolower(palavra_palpite[k]);
            }
            if(strcmp(palavra,palavra_palpite) == 0) {
                strcpy(secreto, palavra_palpite);
                printf("\nPARABÉNS! Você acertou a palavra.");
                exit(0);
            }
            tentativa += 1;
            return;
        }
    }
}