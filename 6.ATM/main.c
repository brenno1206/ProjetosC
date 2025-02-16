#include <stdio.h>
#include <stdlib.h>

struct Conta {
    int numero;
    char nome[50];
    float saldo;
};

int outraOperacao();
void operacao(int tipo, struct Conta *conta, struct Conta contas[] , int num_contas);
void sacar(struct Conta *conta);
void depositar(struct Conta *conta);
void transferir(struct Conta *conta, struct Conta contas[] , int num_contas);
void consultarSaldo(struct Conta *conta);

int main() {
    int cod;
    
    struct Conta contas[] = {
        {100, "Milton Nascimento", 1400.9},
        {101, "Beyoncé Giselle knowles-Carter", 1000},
        {102, "Solana Imani Rowe", 403.5},
        {103, "Gilberto Gil", 3400.10}
    };
    int num_contas = sizeof(contas) / sizeof(contas[0]);
    

    printf("Digite o código da sua conta: ");
    if(scanf(" %d", &cod) != 1) {
        while(getchar() != '\n');
        printf("Este código não pertence a nenhuma conta.\n Fim do Programa.\n");
        exit(0);
    }
    while(getchar() != '\n');

    struct Conta *contaSelecionada = NULL;

    for (int i = 0; i < num_contas; i++) {
        if (contas[i].numero == cod) {
            contaSelecionada = &contas[i];
            break;
        }
    }

    if(contaSelecionada == NULL) {
        printf("Este código não pertence a nenhuma conta.\nFim do Programa.\n");
        exit(0);
    }
            
    do {
        int escolha;
        printf("\n===== MENU ATM =====\n");
        printf(" [1] Sacar\n");
        printf(" [2] Depositar\n");
        printf(" [3] Transferir\n");
        printf(" [4] Consultar Saldo\n");
        printf(" [0] Sair\n");
        printf("====================\n");
        printf("Escolha uma opção: ");
        
        
        if(scanf(" %d", &escolha) != 1 || escolha < 0 || escolha > 4) {
            while(getchar() != '\n');
            printf("Digite um número inteiro entre 0 e 4. Tente novamente");
            continue;
        }
        while(getchar() != '\n');
        operacao(escolha, contaSelecionada, contas, num_contas);

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

void operacao(int tipo, struct Conta *conta, struct Conta contas[] , int num_contas) {
    switch (tipo)
    {
    case 1:
        sacar(conta);
        break;
    case 2:
        depositar(conta);
        break;
    case 3:
        transferir(conta, contas, num_contas);
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

void sacar(struct Conta *conta) {
    float saque;
    printf("Quanto você quer sacar: ");
    if(scanf(" %f", &saque) != 1) {
        while(getchar() != '\n');
        printf("valor inválido.\n");
        exit(0);
    }
    while(getchar() != '\n');
    if(conta->saldo < saque) {
        printf("Valor do saque maior que o da conta.\n");
        return;
    }
    conta->saldo -= saque;
    printf("\nValor do saque: %.2f\nValor do Saldo Final: %.2f\n\n", saque, conta->saldo);
    return;
}

void depositar(struct Conta *conta) {
    float deposito;
    printf("Quanto você deseja depositar: ");
    if(scanf(" %f", &deposito) != 1) {
        while(getchar() != '\n');
        printf("valor inválido.\n");
        exit(0);
    }
    while(getchar() != '\n');

    conta->saldo += deposito;
    printf("\nValor do depósito: %.2f\nValor do Saldo Final: %.2f\n\n", deposito, conta->saldo);
    return;
}

void transferir(struct Conta *conta, struct Conta contas[], int tamanho) {
    float transferencia;
    int conta2;
    struct Conta *destino = NULL;

    printf("Quanto você quer transferir? ");
    if (scanf(" %f", &transferencia) != 1) {
        while (getchar() != '\n');
        printf("Valor inválido.\n");
        return;
    }
    while (getchar() != '\n');

    if (conta->saldo < transferencia) {
        printf("Saldo insuficiente para transferência.\n");
        return;
    }

    printf("Para qual conta deseja transferir? ");
    if (scanf(" %d", &conta2) != 1) {
        while (getchar() != '\n');
        printf("Conta não cadastrada.\n");
        return;
    }
    while (getchar() != '\n');

    for (int i = 0; i < tamanho; i++) {
        if (contas[i].numero == conta2) {
            destino = &contas[i];
            break;
        }
    }

    if (destino == NULL || destino == conta) {
        printf("Conta inválida para transferência.\n");
        return;
    }

    conta->saldo -= transferencia;
    destino->saldo += transferencia;

    printf("\nTransferência realizada!\n");
    printf("Novo saldo da sua conta: %.2f\n", conta->saldo);
}

void consultarSaldo(struct Conta *conta) {
    printf("\nSALDO: %.2f\n", conta->saldo);
    return;
}