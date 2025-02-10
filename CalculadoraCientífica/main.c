#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float pegarNumero();
int calculoFatorial(int num);
void somar();
void subtrair();
void multiplicar();
void dividir();
void seno();
void cosseno();
void tangente();
void logaritmo();
void potencia();
void fatorial();

int main() {
    int resposta;
    printf("----Calculadora Científica---\n\n\n");
    printf("[1] soma [2] subtr [3] mult\n"); 
    printf("[4] div  [5] sen   [6] cos\n");
    printf("[7] tg   [8] log   [9] pot\n");
    printf("         [0] fat\n\n\nEscolha uma opção: ");
    if (scanf("%d", &resposta) != 1) {
        while (getchar() != '\n');
        printf("Entrada inválida!\nFim do Programa!\n");
        return 1;
    }

    switch (resposta)
    {
    case 1:
        somar();
        break;
    case 2:
        subtrair();
        break;
    case 3:
        multiplicar();
        break;
    case 4:
        dividir();
        break;
    case 5: 
        seno();
        break;
    case 6:
        cosseno();
        break;
    case 7:
        tangente();
        break;
    case 8:
        logaritmo();
        break;
    case 9:
        potencia();
        break;
    case 0:
        fatorial();
        break;
    default:
        printf("Número não especificado na calculadora.\nFim do Programa.\n");
        break;
    }
    return 0;
}

float pegarNumero() {
    float num;
    printf("Número: ");
    if (scanf("%f", &num) != 1) {
        while (getchar() != '\n');
        printf("Entrada inválida!\nFim do Programa!\n");
        exit(1);
    } else {
        return num;
    }
}

int calculoFatorial(int num) {
    if (num == 1 || num == 0) {
        return 1;
    }
    else {
        return (num * calculoFatorial(num - 1));
    }
}

void somar() {
    float a = pegarNumero();
    float b = pegarNumero();
    printf("%.2f + %.2f = %.2f\n", a, b, a + b);
}
void subtrair() {
    float a = pegarNumero();
    float b = pegarNumero();
    printf("%.2f - %.2f = %.2f\n", a, b, a - b);
}
void multiplicar() {
    float a = pegarNumero();
    float b = pegarNumero();
    printf("%.2f * %.2f = %.2f\n", a, b, a * b);
}
void dividir() {
    float a = pegarNumero();
    float b = pegarNumero();
    if (b == 0) {
        printf("A divisão por 0 não é definida na matemática.\nFim do Programa.\n");
        exit(1);
    }
    printf("%.2f / %.2f = %.2f\n", a, b, a / b);
}
void seno() {
    float a = pegarNumero();
    printf("sen(%.2f rad) = %.2f\n", a, sin(a));
}
void cosseno() {
    float a = pegarNumero();
    printf("cos(%.2f rad) = %.2f\n", a, cos(a));
}
void tangente() {
    float a = pegarNumero();
    printf("tg(%.2f rad) = %.2f\n", a, tan(a));
}
void logaritmo() {
    float a = pegarNumero();
    printf("log10(%.2f) = %.2f\n", a, log10(a));
}
void potencia() {
    float a = pegarNumero();
    float b = pegarNumero();
    printf("%.2f ** %.2f = %.2f\n", a, b, pow(a, b));
}
void fatorial() {
    int a = (int)pegarNumero();
    if (a < 0) {
        printf("O fatorial de números negativos não é definid ona matemática.");
        exit(1);
    }
    printf("%d! = %d\n", a, calculoFatorial(a));
}