#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 10

typedef struct {
    char cpf[12];
    char senha[20];
    float saldo_reais;
    float saldo_bitcoin;
    float saldo_ethereum;
    float saldo_ripple;
} Usuario;

Usuario usuarios[MAX_USERS];
int total_usuarios = 0;

int login(char cpf[], char senha[]) {
    for (int i = 0; i < total_usuarios; i++) {
        if (strcmp(usuarios[i].cpf, cpf) == 0 && strcmp(usuarios[i].senha, senha) == 0) {
            return i;
        }
    }
    return -1;
}

void cadastrar_usuario() {
    if (total_usuarios >= MAX_USERS) {
        printf("Limite de usuários cadastrados atingido.\n");
        return;
    }

    Usuario novo_usuario;
    printf("Digite o CPF (11 dígitos): ");
    scanf("%s", novo_usuario.cpf);
    
    printf("Digite a senha: ");
    scanf("%s", novo_usuario.senha);

    novo_usuario.saldo_reais = 0.0;
    novo_usuario.saldo_bitcoin = 0.0;
    novo_usuario.saldo_ethereum = 0.0;
    novo_usuario.saldo_ripple = 0.0;

    usuarios[total_usuarios++] = novo_usuario;
    printf("Usuário cadastrado com sucesso!\n");
}

void consultar_saldo(Usuario *user) {
    printf("Saldo de Reais: %.2f\n", user->saldo_reais);
    printf("Saldo de Bitcoin: %.4f BTC\n", user->saldo_bitcoin);
    printf("Saldo de Ethereum: %.4f ETH\n", user->saldo_ethereum);
    printf("Saldo de Ripple: %.4f XRP\n", user->saldo_ripple);
}

void depositar_reais(Usuario *user, float valor) {
    user->saldo_reais += valor;
    printf("Depósito realizado! Novo saldo de reais: %.2f\n", user->saldo_reais);
}

void sacar_reais(Usuario *user, float valor, char senha[]) {
    if (strcmp(senha, user->senha) == 0 && valor <= user->saldo_reais) {
        user->saldo_reais -= valor;
        printf("Saque de %.2f realizado! Novo saldo de reais: %.2f\n", valor, user->saldo_reais);
    } else {
        printf("Erro ao sacar. Senha incorreta ou saldo insuficiente.\n");
    }
}

void exibir_menu(Usuario *user) {
    int opcao;
    do {
        printf("\n--- Menu Principal ---\n");
        printf("1. Consultar Saldo\n");
        printf("2. Depositar Reais\n");
        printf("3. Sacar Reais\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                consultar_saldo(user);
                break;
            case 2: {
                float valor;
                printf("Informe o valor para depósito: ");
                scanf("%f", &valor);
                depositar_reais(user, valor);
                break;
            }
            case 3: {
                float valor;
                char senha[20];
                printf("Informe o valor para saque: ");
                scanf("%f", &valor);
                printf("Digite sua senha: ");
                scanf("%s", senha);
                sacar_reais(user, valor, senha);
                break;
            }
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while(opcao != 4);
}

int main() {
    int opcao;
    char cpf[12];
    char senha[20];

    do {
        printf("\n--- Sistema de Carteira de Investimentos ---\n");
        printf("1. Cadastrar Usuário\n");
        printf("2. Fazer Login\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                cadastrar_usuario();
                break;
            case 2:
                printf("CPF: ");
                scanf("%s", cpf);
                printf("Senha: ");
                scanf("%s", senha);
                int indice = login(cpf, senha);
                if (indice != -1) {
                    printf("Login realizado com sucesso!\n");
                    exibir_menu(&usuarios[indice]);
                } else {
                    printf("CPF ou senha incorretos!\n");
                }
                break;
            case 3:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while(opcao != 3);

    return 0;
}

    return 0;
}
