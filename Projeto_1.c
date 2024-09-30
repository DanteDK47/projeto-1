#include <stdio.h>
#include <string.h>

#define MAX_USUARIOS 100

typedef struct {
    char cpf[12];
    char senha[20];
    float saldo_reais;
    float saldo_btc;
    float saldo_eth;
    float saldo_xrp;
} Usuario;

Usuario usuarios[MAX_USUARIOS];
int total_usuarios = 0;

void cadastrar_usuario() {
    printf("Digite o CPF: ");
    scanf("%s", usuarios[total_usuarios].cpf);
    printf("Digite a senha: ");
    scanf("%s", usuarios[total_usuarios].senha);
    usuarios[total_usuarios].saldo_reais = 0;
    usuarios[total_usuarios].saldo_btc = 0;
    usuarios[total_usuarios].saldo_eth = 0;
    usuarios[total_usuarios].saldo_xrp = 0;
    total_usuarios++;
}

int login(char cpf[], char senha[]) {
    for (int i = 0; i < total_usuarios; i++) {
        if (strcmp(usuarios[i].cpf, cpf) == 0 && strcmp(usuarios[i].senha, senha) == 0) {
            return i;  // Retorna o índice do usuário
        }
    }
    return -1;  // Não encontrou
}

void consultar_saldo(int indice) {
    printf("Saldo em Reais: %.2f\n", usuarios[indice].saldo_reais);
    printf("Saldo em Bitcoin: %.2f\n", usuarios[indice].saldo_btc);
    printf("Saldo em Ethereum: %.2f\n", usuarios[indice].saldo_eth);
    printf("Saldo em Ripple: %.2f\n", usuarios[indice].saldo_xrp);
}

void exibir_menu(int indice) {
    int opcao;
    do {
        printf("\nMenu:\n");
        printf("1. Consultar Saldo\n");
        printf("2. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                consultar_saldo(indice);
                break;
            case 2:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 2);
}

int main() {
    int opcao;
    do {
        printf("\n1. Cadastrar Usuário\n");
        printf("2. Login\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            cadastrar_usuario();
        } else if (opcao == 2) {
            char cpf[12], senha[20];
            printf("Digite o CPF: ");
            scanf("%s", cpf);
            printf("Digite a senha: ");
            scanf("%s", senha);

            int indice = login(cpf, senha);
            if (indice != -1) {
                printf("Login realizado com sucesso!\n");
                exibir_menu(indice);
            } else {
                printf("CPF ou senha incorretos!\n");
            }
        }
    } while (opcao != 3);

    return 0;
}

