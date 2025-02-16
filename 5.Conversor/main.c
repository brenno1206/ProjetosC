#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define tamanhoMax 20

int pegarBase();
void pegarNumero(int base, char num1[tamanhoMax]);
void decToBin(char num1[tamanhoMax], char num2[tamanhoMax]);
void decToOct(char num1[tamanhoMax], char num2[tamanhoMax]);
void decToHex(char num1[tamanhoMax], char num2[tamanhoMax]);
void binToDec(char num1[tamanhoMax], char num2[tamanhoMax]);
void binToOct(char num1[tamanhoMax], char num2[tamanhoMax]);
void binToHex(char num1[tamanhoMax], char num2[tamanhoMax]);
void octToDec(char num1[tamanhoMax], char num2[tamanhoMax]);
void octToBin(char num1[tamanhoMax], char num2[tamanhoMax]);
void octToHex(char num1[tamanhoMax], char num2[tamanhoMax]);
void hexToDec(char num1[tamanhoMax], char num2[tamanhoMax]);
void hexToBin(char num1[tamanhoMax], char num2[tamanhoMax]);
void hexToOct(char num1[tamanhoMax], char num2[tamanhoMax]);
void converter(int base1, int base2, char num1[tamanhoMax], char num2[tamanhoMax]);

int main() {
    int baseInicial, baseFinal;
    char numeroInicial[tamanhoMax], numeroFinal[tamanhoMax];

    baseInicial = pegarBase();
    pegarNumero(baseInicial, numeroInicial);

    do {
        baseFinal = pegarBase();
        if (baseInicial == baseFinal) {
            printf("\nAs bases numéricas devem ser diferentes.\n");
        }
    } while(baseInicial == baseFinal);

    converter(baseInicial, baseFinal, numeroInicial, numeroFinal);
    printf("base1: %d \nbase2: %d \nnumero: %s \nnumero final: %s \n", baseInicial, baseFinal, numeroInicial, numeroFinal);
    return 0;
}

int pegarBase() {
    int base;
    while (1) {
        printf("Digite a base numérica que você vai converter: \n");
        printf("[1] Decimal\n[2] Binária\n[3] Octal\n[4] Hexadecimal\nResposta: ");
        
        if (scanf("%d", &base) != 1) {
            while (getchar() != '\n');
            printf("Entrada inválida! Por favor, digite um número inteiro.\n");
            continue;
        }

        while (getchar() != '\n');

        if (base < 1 || base > 4) {
            printf("O número deve estar entre 1 e 4.\n");
            continue;
        }

        return base;
    }
}

void pegarNumero(int base, char num1[tamanhoMax]) {
    while (1) {
        switch (base) {
            case 1: {
                printf("Digite o número em base decimal: ");
                if (fgets(num1, tamanhoMax, stdin) == NULL) {
                    printf("Erro ao ler entrada. Tente novamente.\n");
                    continue;
                }
                num1[strcspn(num1, "\n")] = '\0';

                for (int i = 0; num1[i] != '\0'; i++) {
                    if (!isdigit(num1[i])) {
                        printf("Número não decimal. Tente novamente\n");
                        goto restart;
                    }
                }
                return;
            }

            case 2: {
                printf("Digite o número em base binária: ");
                if (fgets(num1, tamanhoMax, stdin) == NULL) {
                    printf("Erro ao ler entrada. Tente novamente.\n");
                    continue;
                }
                num1[strcspn(num1, "\n")] = '\0';

                for (int i = 0; num1[i] != '\0'; i++) {
                    if (num1[i] != '0' && num1[i] != '1') {
                        printf("Número não binário. Tente novamente\n");
                        goto restart;
                    }
                }
                return;
            }

            case 3: {
                printf("Digite o número em base octal: ");
                if (fgets(num1, tamanhoMax, stdin) == NULL) {
                    printf("Erro ao ler entrada. Tente novamente.\n");
                    continue;
                }
                num1[strcspn(num1, "\n")] = '\0';

                for (int i = 0; num1[i] != '\0'; i++) {
                    if (num1[i] < '0' || num1[i] > '7') {
                        printf("Número não octal. Tente novamente\n");
                        goto restart;
                    }
                }
                return;
            }

            case 4: {
                printf("Digite o número em base hexadecimal: ");
                if (fgets(num1, tamanhoMax, stdin) == NULL) {
                    printf("Erro ao ler entrada. Tente novamente.\n");
                    continue;
                }
                num1[strcspn(num1, "\n")] = '\0';

                for (int i = 0; num1[i] != '\0'; i++) {
                    if (!isxdigit(num1[i])) {
                        printf("Número não hexadecimal. Tente novamente\n");
                        goto restart;
                    }
                }
                return;
            }
        }
    restart:;
    }
}

void decToBin(char num1[tamanhoMax], char num2[tamanhoMax]) {
    unsigned long valor = strtoul(num1, NULL, 10);
    int i = tamanhoMax - 1; 
    num2[i] = '\0'; 

    if (valor == 0) {
        num2[--i] = '0';  
    } else {
        while (valor > 0 && i > 0) {
            num2[--i] = (valor % 2) + '0';
            valor /= 2;
        }
    }

    memmove(num2, &num2[i], tamanhoMax - i + 1);
}

void decToOct(char num1[tamanhoMax], char num2[tamanhoMax]) {
    unsigned long valor = strtoul(num1, NULL, 10);
    int i = tamanhoMax - 1;  
    num2[i] = '\0';  

    if (valor == 0) {
        num2[--i] = '0';  
    } else {
        while (valor > 0 && i > 0) {
            num2[--i] = (valor % 8) + '0';
            valor /= 8;
        }
    }

    memmove(num2, &num2[i], tamanhoMax - i + 1);
}

void decToHex(char num1[tamanhoMax], char num2[tamanhoMax]) {
    unsigned long valor = strtoul(num1, NULL, 10);
    int i = tamanhoMax - 1;  
    num2[i] = '\0';  

    if (valor == 0) {
        num2[--i] = '0';  
    } else {
        while (valor > 0 && i > 0) {
            int resto = valor % 16;
            num2[--i] = (resto < 10) ? (resto + '0') : ('A' + (resto - 10));  
            valor /= 16;
        }
    }
    memmove(num2, &num2[i], tamanhoMax - i + 1);
}

void binToDec(char num1[tamanhoMax], char num2[tamanhoMax]) {
    unsigned long valor = strtoul(num1, NULL, 2);
    sprintf(num2, "%lu", valor);
}


void binToOct(char num1[tamanhoMax], char num2[tamanhoMax]) {
    char intermediário[tamanhoMax];
    binToDec(num1, intermediário);
    decToOct(intermediário,num2);
}

void binToHex(char num1[tamanhoMax], char num2[tamanhoMax]) {
    char intermediário[tamanhoMax];
    binToDec(num1, intermediário);
    decToHex(intermediário,num2);
}

void octToDec(char num1[tamanhoMax], char num2[tamanhoMax]) {
    unsigned long valor = strtoul(num1, NULL, 8);
    sprintf(num2, "%lu", valor);
}

void octToBin(char num1[tamanhoMax], char num2[tamanhoMax]) {
    char intermediário[tamanhoMax];
    octToDec(num1, intermediário);
    decToBin(intermediário,num2);
}

void octToHex(char num1[tamanhoMax], char num2[tamanhoMax]) {
    char intermediário[tamanhoMax];
    octToDec(num1,intermediário);
    decToHex(intermediário,num2);
}

void hexToDec(char num1[tamanhoMax], char num2[tamanhoMax]) {
    unsigned long valor = strtoul(num1, NULL, 16);
    sprintf(num2, "%lu", valor);
}

void hexToBin(char num1[tamanhoMax], char num2[tamanhoMax]) {
    char intermediário[tamanhoMax];
    hexToDec(num1,intermediário);
    decToBin(intermediário,num2);
}

void hexToOct(char num1[tamanhoMax], char num2[tamanhoMax]) {
    char intermediário[tamanhoMax];
    hexToDec(num1,intermediário);
    decToOct(intermediário,num2);
}

void converter(int base1, int base2, char num1[tamanhoMax], char num2[tamanhoMax]) {
    switch (base1) {
    case 1:
        if (base2 == 2) {
            decToBin(num1, num2);
        } else if (base2 == 3) {
            decToOct(num1,num2);
        } else {
            decToHex(num1, num2);
        }
        break;
    case 2:
        if (base2 == 1) {
            binToDec(num1, num2);
        } else if (base2 == 3) {
            binToOct(num1,num2);
        } else {
            binToHex(num1, num2);
        }
        break;
    case 3:
        if (base2 == 1) {
            octToDec(num1, num2);
        } else if (base2 == 2) {
            octToBin(num1,num2);
        } else {
            octToHex(num1, num2);
        }
        break;
    case 4:
        if (base2 == 1) {
            hexToDec(num1, num2);
        } else if (base2 == 2) {
            hexToBin(num1,num2);
        } else {
            hexToOct(num1, num2);
        }
        break;
    
    default:
        return;
    }
    return;
}