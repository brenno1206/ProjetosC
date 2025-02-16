#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define tamanhoMax 1000

void mostrarDados(char texto[tamanhoMax], int tamanho);
int contarLetras(char texto[tamanhoMax], int tamanho);
int contarPalavras(char texto[tamanhoMax], int tamanho);
void palavraMaisRepetida(char texto[tamanhoMax], int tamanho);
char letraMaisRepetida(char texto[tamanhoMax]);

int main() {
    char texto[tamanhoMax];
    printf("Insira o seu texto para a análise: \n");
    if (fgets(texto, tamanhoMax, stdin) == NULL) {
        printf("Erro ao ler entrada.\nFim do Programa.\n");
    }
    mostrarDados(texto, strlen(texto));

    return 0;
}

void mostrarDados(char texto[tamanhoMax], int tamanho) {
    printf("O texto tem %d letras.\n", contarLetras(texto,tamanho));
    printf("A letra mais repetida é: %c.\n", letraMaisRepetida(texto));
    printf("O texto tem %d palavras.\n", contarPalavras(texto,tamanho));
    printf("A palavra mais repetida é: ");
    palavraMaisRepetida(texto, tamanho);
    return;
}

int contarLetras(char texto[tamanhoMax], int tamanho) {
    int letras = 0;
    for(int i = 0; i < tamanho; i++) {
        if(isalpha(texto[i])) {
            letras++;
        }
    }
    return letras;
}

int contarPalavras(char texto[tamanhoMax], int tamanho) {
    int palavras = 0;
    for (int i = 0; i < tamanho; i++) {
        if ((isalnum(texto[i]) && isspace(texto[i + 1]))  || (isalnum(texto[i]) && ispunct(texto[i + 1]))) {
            palavras++;
        }
    }
    return palavras;
}

void palavraMaisRepetida(char texto[tamanhoMax], int tamanho) {}

char letraMaisRepetida(char texto[tamanhoMax]) {
    int frequencia[256] = {0}; 
    char letra_frequente = '\0';
    int max_frequencia = 0;

    for (int i = 0; texto[i] != '\0'; i++) {
        if (isalpha(texto[i])) { 
            char c = tolower(texto[i]); 
            frequencia[(unsigned char)c]++;
            
            if (frequencia[(unsigned char)c] > max_frequencia) {
                max_frequencia = frequencia[(unsigned char)c];
                letra_frequente = c;
            }
        }
    }

    return letra_frequente;
}