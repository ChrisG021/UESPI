#include<stdio.h>
#include<stdlib.h>

int count_c = 0;//contador de clientes inseridos
int count_p = 0;
int max_c = 0;//inicializa contador para controle do número máximo de clientes
int max_p = 0;
//
typedef struct 
{
    char  nome[100];
    int idade;
    int CPF;
}Cliente;

typedef struct{
    char nome[30];
    int codigo;
    int quantidade;
}Produto;

Cliente cadastrarCliente(){
    Cliente c;
    printf("\n----------Sistema de cadastro de cliente-----------\n");
    printf("Informe o nome:");
    scanf(" %[^\n]", c.nome);

    printf("Informe o idade:");
    scanf("%d",&c.idade);

    printf("Informe o CPF:");
    scanf("%d",&c.CPF);
    max_c++;

    return c;
}

void exibirCliente(Cliente clienteDB[]){
    printf("\nExibicao de dos Clientes cadastrados");
    int j;
    for(j = 0; j < max_c; j++)
    {
        printf("\n   CODIGO   %d",j+1);
        printf("\n Nome............%s",clienteDB[j].nome);
        printf("\n Idade...........%d",clienteDB[j].idade);
        printf("\n CPF.............%d",clienteDB[j].CPF);
    }
}

Produto cadastrarProduto(){
    Produto p;
    printf("\n----------Sistema de cadastro de Produto-----------\n");
    printf("Digite o nome do produto:");
    scanf(" %[^\n]", p.nome);
    printf("Digite o codigo do produto:");
    scanf("%d",&p.codigo);
    printf("Digite a quantidade:");
    scanf("%d",&p.quantidade);
    max_p++;

    return p;
}

void exibirProduto(Produto produtoDB[]){
    printf("\nExibicao de dos Produtos cadastrados\n");
    int j;
    for(j = 0; j < max_p; j++)
    {
        printf("\n   CODIGO   %d",j+1);
        printf("\n Nome............%s",produtoDB[j].nome);
        printf("\n codigo..........%d",produtoDB[j].codigo);
        printf("\n Quantidade......%d\n",produtoDB[j].quantidade);
    }
}


int main(void){

    int op;
    Cliente clienteDB[50];
    Produto produtoDB[50];

    do {
        printf("\n---------------- Livraria Dois Irmaos ----------------");
        printf("\nSistema de Cadastro");
        printf("\n\n1 - Cadastrar Cliente");
        printf("\n2 - Exibir Clientes");
        printf("\n3 - Cadastrar Produto");
        printf("\n4 - Exibir Produtos");
        printf("\n5 - Sair");
        printf("\n\nDigite a opcao: ");

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
                if (count_p < 50) {
                    produtoDB[count_p++] = cadastrarProduto();
                } else {
                    printf("Limite de produtos atingido.\n");
                }
                break;

            case 4:
                exibirProduto(produtoDB);
                break;

            case 5:
                printf("Encerrando o programa...\n");
                break;

            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (op != 5);

    return 0;
}