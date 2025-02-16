#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int numeroSecreto = rand() % 100;
    int palpite = 0;

    do {
        printf("Digite seu palpite: ");
        if (scanf("%d", &palpite) != 1) {
            while (getchar() != '\n');
            printf("Entrada inválida! Por favor, digite um número inteiro.\n");
        } else {
            if (palpite > numeroSecreto) {
                printf("Palpite errado! O número secreto é menor.\n");
            }
            else if (numeroSecreto > palpite) {
                printf("Palpite errado! O número secreto é maior.\n");
            }
            else {
                printf("Acertou! O número secreto é %d\n", numeroSecreto);
            }
        }
    } while (palpite != numeroSecreto);
    printf("Fim do programa");
    return 0;
}