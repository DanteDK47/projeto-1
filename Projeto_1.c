#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char cpf[12];
    char senha[20];
    float saldo_reais;
    float saldo_bitcoin;
    float saldo_ethereum;
    float saldo_ripple;
} Usuario;

typedef struct {
    float bitcoin;
    float ethereum;
    float ripple;
} Cotacao;

Usuario usuario = {"12345678900", "senha123", 1000.0, 0.1, 2.5, 100.0};
Cotacao cotacao = {50000.0, 3000.0, 1.5};

int login(char cpf[], char senha[]) {
    if (strcmp(cpf, usuario.cpf) == 0 && strcmp(senha, usuario.senha) == 0) {
        return 1;
    }
    return 0;
}

void consultar_saldo() {
    printf("Saldo de Reais: %.2f\n", usuario.saldo_reais);
    printf("Saldo de Bitcoin: %.4f BTC\n", usuario.saldo_bitcoin);
    printf("Saldo de Ethereum: %.4f ETH\n", usuario.saldo_ethereum);
    printf("Saldo de Ripple: %.4f XRP\n", usuario.saldo_ripple);
}

void depositar_reais(float valor) {
    usuario.saldo_reais += valor;
    printf("Depósito realizado! Novo saldo de reais: %.2f\n", usuario.saldo_reais);
}

void sacar_reais(float valor, char senha[]) {
    if (strcmp(senha, usuario.senha) == 0 && valor <= usuario.saldo_reais) {
        usuario.saldo_reais -= valor;
        printf("Saque de %.2f realizado! Novo saldo de reais: %.2f\n", valor, usuario.saldo_reais);
    } else {
        printf("Erro ao sacar. Senha incorreta ou saldo insuficiente.\n");
    }
}

void atualizar_cotacao() {
    srand(time(0));
    cotacao.bitcoin *= (1 + (rand() % 10 - 5) / 100.0);
    cotacao.ethereum *= (1 + (rand() % 10 - 5) / 100.0);
    cotacao.ripple *= (1 + (rand() % 10 - 5) / 100.0);
    printf("Cotações atualizadas!\n");
    printf("Bitcoin: %.2f\n", cotacao.bitcoin);
    printf("Ethereum: %.2f\n", cotacao.ethereum);
    printf("Ripple: %.2f\n", cotacao.ripple);
}

void exibir_menu() {
    int opcao;
    do {
        printf("\n--- Menu Principal ---\n");
        printf("1. Consultar Saldo\n");
        printf("2. Depositar Reais\n");
        printf("3. Sacar Reais\n");
        printf("4. Atualizar Cotações\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                consultar_saldo();
                break;
            case 2: {
                float valor;
                printf("Informe o valor para depósito: ");
                scanf("%f", &valor);
                depositar_reais(valor);
                break;
            }
            case 3: {
                float valor;
                char senha[20];
                printf("Informe o valor para saque: ");
                scanf("%f", &valor);
                printf("Digite sua senha: ");
                scanf("%s", senha);
                sacar_reais(valor, senha);
                break;
            }
            case 4:
                atualizar_cotacao();
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while(opcao != 5);
}

int main() {
    char cpf[12];
    char senha[20];

    printf("CPF: ");
    scanf("%s", cpf);
    printf("Senha: ");
    scanf("%s", senha);

    if (login(cpf, senha)) {
        printf("Login realizado com sucesso!\n");
        exibir_menu();
    } else {
        printf("CPF ou senha incorretos!\n");
    }

    return 0;
}
