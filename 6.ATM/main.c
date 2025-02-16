#include <stdio.h>
#include <stdlib.h>

struct Conta {
    int numero;
    char nome[50];
    float saldo;
};

int outraOperacao();
void operacao(int tipo, struct Conta *conta);
void sacar(struct Conta *conta);
void depositar(struct Conta *conta);
void transferir(struct Conta *conta);
void consultarSaldo(struct Conta *conta);

int main() {
    int cod;
    
    struct Conta cadastro1 = {100, "Milton Nascimento", 1400.9};
    struct Conta cadastro2 = {101, "Beyoncé Giselle knowles-Carter", 1000};
    struct Conta cadastro3 = {102, "Solana Imani Rowe", 403.5};
    struct Conta cadastro4 = {103, "Gilberto Gil", 3400.10};

    printf("Digite o código da sua conta: ");
    if(scanf(" %d", &cod) != 1) {
        while(getchar() != '\n');
        printf("Este código não pertence a nenhuma conta.\n Fim do Programa.\n");
        exit(0);
    }
    while(getchar() != '\n');

    struct Conta *contaSelecionada = NULL;

    switch(cod) {
        case 100:
            contaSelecionada = &cadastro1;
            break;
        case 101:
            contaSelecionada = &cadastro2;
            break;
        case 102:
            contaSelecionada = &cadastro3;
            break;
        case 103:
            contaSelecionada = &cadastro4;
            break;
        default:
            printf("Este código não pertence a nenhuma conta.\nFim do Programa.\n");
            exit(0);
    }
    do {
        int escolha;
        printf("-----ATM----\n");
        printf("[1] Saque\n");
        printf("[2] Depósito\n");
        printf("[3] Transferência\n");
        printf("[4] Consultar Saldo\n");
        printf("[0] Sair\n");
        printf("\nEscolha: ");
        
        if(scanf(" %d", &escolha) != 1 || escolha < 0 || escolha > 4) {
            while(getchar() != '\n');
            printf("Digite um número inteiro entre 0 e 4. Tente novamente");
            continue;
        }
        while(getchar() != '\n');
        operacao(escolha, contaSelecionada);

    } while(outraOperacao());

    return 0;
}

int outraOperacao() {
    int operacao;
    printf("Você deseja realizar outra operação? (O) Não (1) Sim: ");
    if(scanf(" %d", &operacao) != 1 || operacao != 1) {
        while(getchar() != '\n');
        return 0;
    }
    while(getchar() != '\n');
    printf("\n\n");
    return 1;
}

void operacao(int tipo, struct Conta *conta) {
    switch (tipo)
    {
    case 1:
        sacar(conta);
        break;
    case 2:
        depositar(conta);
        break;
    case 3:
        transferir(conta);
        break;
    case 4:
        consultarSaldo(conta);
        break;
    default:
        printf("Fim do Programa.\n");
        exit(0);
    }
    return;
}

void sacar(struct Conta *conta);
void depositar(struct Conta *conta);
void transferir(struct Conta *conta);
void consultarSaldo(struct Conta *conta);