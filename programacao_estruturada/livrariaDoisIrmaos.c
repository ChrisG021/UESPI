#include<stdio.h>
#include<stdlib.h>

int count_c = 0; // contador de clientes inseridos
int max_c = 0;   // inicializa contador para controle do numero maximo de clientes
int count_e = 0; // contador de editoras inseridas
int max_e = 0;   // inicializa contador para controle do numero maximo de editoras
int count_g = 0; 
int max_g = 0; 
typedef struct {
    char nome[30];
} Editora;

typedef struct {
    char nome[30];
} Genero;

typedef struct {
    char nome[100];
    int data_nasc;
    int CPF;
    int telefone;
} Cliente;

Genero cadastrarGenero(){
    Genero g;
    printf("\n---------- Sistema de cadastro de genero -----------\n");
    printf("Informe o nome da genero: ");
    scanf(" %[^\n]", g.nome);
    
    max_g++; // Incrementa o contador de editoras

    return g;
}

void exibirGenero(Genero generoDB[]) {
    printf("\nExibicao dos generos cadastrados:\n");
    int j;
    for (j = 0; j < max_g; j++) {
        printf("\n   CODIGO: %d", j + 1);
        printf("\n Nome: %s", generoDB[j].nome);
        printf("\n--------------------------------------------");
    }
}

Editora cadastrarEditora() {
    Editora e;
    printf("\n---------- Sistema de cadastro de editora -----------\n");
    printf("Informe o nome da editora: ");
    scanf(" %[^\n]", e.nome);
    
    max_e++; // Incrementa o contador de editoras

    return e;
}

void exibirEditora(Editora editoraDB[]) {
    printf("\nExibicao das Editoras cadastradas:\n");
    int j;
    for (j = 0; j < max_e; j++) {
        printf("\n   CODIGO: %d", j + 1);
        printf("\n Nome: %s", editoraDB[j].nome);
        printf("\n--------------------------------------------");
    }
}

Cliente cadastrarCliente() {
    Cliente c;
    printf("\n---------- Sistema de cadastro de cliente -----------\n");
    printf("Informe o nome: ");
    scanf(" %[^\n]", c.nome);

    printf("Informe a data de nascimento (sem barras e digitos unidos): ");
    scanf("%d", &c.data_nasc);

    printf("Informe o CPF: ");
    scanf("%d", &c.CPF);

    printf("Informe o telefone: ");
    scanf("%d", &c.telefone);

    max_c++; // Incrementa o contador de clientes

    return c;
}

void exibirCliente(Cliente clienteDB[]) {
    printf("\nExibicao dos Clientes cadastrados:\n");
    int j;
    for (j = 0; j < max_c; j++) {
        printf("\n   CODIGO: %d", j + 1);
        printf("\n Nome: %s", clienteDB[j].nome);
        printf("\n Data de Nascimento: %d", clienteDB[j].data_nasc);
        printf("\n Telefone: %d", clienteDB[j].telefone);
        printf("\n CPF: %d", clienteDB[j].CPF);
        printf("\n--------------------------------------------");
    }
}

int main(void) {
    int op;
    Cliente clienteDB[50];
    Editora editoraDB[30];
    Genero generoDB[30];

    do {
        printf("\n---------------- Livraria Dois Irmaos ----------------");
        printf("\nSistema de Cadastro");
        printf("\n\n1 - Gerenciar Clientes");
        printf("\n2 - Gerenciar Editoras");
        printf("\n3 - Gerenciar Generos");
        printf("\n0 - Sair");
        printf("\n\nDigite a opcao: ");
        scanf("%d", &op);

        switch (op) {
            case 1: // Gerenciamento de Clientes
                do {
                    printf("\n------ Menu de Gerenciamento de Clientes ------");
                    printf("\n1 - Cadastrar Cliente");
                    printf("\n2 - Exibir Clientes");
                    printf("\n3 - Voltar ao menu principal");
                    printf("\nDigite a opcao: ");
                    scanf("%d", &op);

                    switch (op) {
                        case 1:
                            if (count_c < 50) {
                                clienteDB[count_c++] = cadastrarCliente();
                            } else {
                                printf("Limite de clientes atingido.\n");
                            }
                            break;

                        case 2:
                            exibirCliente(clienteDB);
                            break;

                        case 3:
                            printf("Voltando ao menu principal...\n");
                            break;

                        default:
                            printf("Opcao invalida. Tente novamente.\n");
                    }
                } while (op != 3); // Voltar ao menu principal

                break;

            case 2: // Gerenciamento de Editoras
                do {
                    printf("\n------ Menu de Gerenciamento de Editoras ------");
                    printf("\n1 - Cadastrar Editora");
                    printf("\n2 - Exibir Editoras");
                    printf("\n3 - Voltar ao menu principal");
                    printf("\nDigite a opcao: ");
                    scanf("%d", &op);

                    switch (op) {
                        case 1:
                            if (count_e < 50) {
                                editoraDB[count_e++] = cadastrarEditora();
                            } else {
                                printf("Limite de editoras atingido.\n");
                            }
                            break;

                        case 2:
                            exibirEditora(editoraDB);
                            break;

                        case 3:
                            printf("Voltando ao menu principal...\n");
                            break;

                        default:
                            printf("Opcao invalida. Tente novamente.\n");
                    }
                } while (op != 3); // Voltar ao menu principal

                break;

            case 3:
            do {
                printf("\n------ Menu de Gerenciamento de Generos ------");
                printf("\n1 - Cadastrar Genero");
                printf("\n2 - Exibir Generos");
                printf("\n3 - Voltar ao menu principal");
                printf("\nDigite a opcao: ");
                scanf("%d", &op);

                switch (op) {
                    case 1:
                        if (count_e < 50) {
                            generoDB[count_g++] = cadastrarGenero();
                        } else {
                            printf("Limite de generos atingido.\n");
                        }
                        break;

                    case 2:
                        exibirGenero(generoDB);
                        break;

                    case 3:
                        printf("Voltando ao menu principal...\n");
                        break;

                    default:
                        printf("Opcao invalida. Tente novamente.\n");
                }
            } while (op != 3); // Voltar ao menu principal

            break;
            case 0:
                printf("Encerrando o programa...\n");
                break;

            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (op != 0);

    return 0;
}
