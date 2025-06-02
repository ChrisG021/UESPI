#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int count_c = 0; // contador de clientes inseridos
int max_c = 0;   // inicializa contador para controle do numero maximo de clientes
int count_e = 0; // contador de editoras inseridas
int max_e = 0;   // inicializa contador para controle do numero maximo de editoras
int count_g = 0; 
int max_g = 0; 
int max_p = 0;
int count_p = 0;
int count_v = 0;
int max_v= 0;

//funcao auxiliar
void to_lower(char *str) {
    int j;
    for (j = 0; str[j]; j++) {
        str[j] = tolower((unsigned char) str[j]);
    }
}

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

typedef struct 
{
    char titulo[100];
    char autor[30];
    Genero genero;
    Editora editora;
    int data_lanc;
    int restricao_idade;
    int quantidade;
    double preco;
} Produto;

typedef struct 
{
    int produtoId;
    double precoVenda;
    int clienteCPF;
    char* dataVenda;
}Venda;


void consultarCpf(Cliente clienteDB[]){
    printf(" Digite o cpf a ser consultado:\n");
    int cpf;
    scanf("%d",&cpf);
    for (int j = 0; j < count_c; j++)
    {
        if (clienteDB[j].CPF == cpf)
        {
        printf("\n--------------------------------------------");
        printf("\n Nome: %s", clienteDB[j].nome);
        printf("\n Data de Nascimento: %d", clienteDB[j].data_nasc);
        printf("\n Telefone: %d", clienteDB[j].telefone);
        printf("\n CPF: %d", clienteDB[j].CPF);
        printf("\n--------------------------------------------");
        }
    }
    
}

Genero cadastrarGenero(){
    Genero g;
    printf("\n---------- Sistema de cadastro de genero -----------\n");
    printf("Informe o nome da genero: ");
    scanf(" %[^\n]", g.nome);
    to_lower(g.nome);
    max_g++; 

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
    to_lower(e.nome);
    
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

Produto cadastrarProduto(Genero generoDB[],Editora editoraDB[]){
    int j;
    int findGenero = 0 ;
    int findEditora = 0;
    Genero g;
    Editora e;
    Produto p;
    printf("\n---------- Sistema de cadastro de produto -----------\n");
    printf("Digite o titulo do livro: ");
    scanf(" %[^\n]",p.titulo);
    printf("Digite o autor do livro: ");
    scanf(" %[^\n]",p.autor);
    // ======= GÊNERO =======
    printf("Digite o genero: ");
    scanf(" %[^\n]", g.nome);
    to_lower(g.nome);

    for (j = 0; j < count_g; j++) {
        if (strcmp(g.nome, generoDB[j].nome) == 0) {
            findGenero = 1;
            p.genero = generoDB[j]; // associa ao produto
            break;
        }
    }

    if (!findGenero) {
        printf("Genero não encontrado...indo para o cadastro dele\n");
        if (count_g < 30) {
            p.genero = cadastrarGenero();
            generoDB[count_g++] = p.genero;
        } else {
            printf("Limite de generos atingido. Não é possível cadastrar mais.\n");
        }
    }

    // ======= EDITORA =======
    printf("Digite a editora: ");
    scanf(" %[^\n]", e.nome);
    to_lower(e.nome);

    for (j = 0; j < count_e; j++) {
        if (strcmp(e.nome, editoraDB[j].nome) == 0) {
            findEditora = 1;
            p.editora = editoraDB[j];
            break;
        }
    }

    if (!findEditora) {
        printf("Editora não encontrada...indo para o cadastro dela\n");
        if (count_e < 30) {
            p.editora = cadastrarEditora();
            editoraDB[count_e++] = p.editora;
        } else {
            printf("Limite de editoras atingido. Não é possível cadastrar mais.\n");
        }
    }
    
    
    printf("Digite a data de lancamento do livro: ");
    scanf("%d",&p.data_lanc);
    printf("Digite a restricao de idade: ");
    scanf("%d",&p.restricao_idade);
    printf("Digite a quantidade em estoque: ");
    scanf("%d",&p.quantidade);
    printf("Digite o preco: ");
    scanf("%lf",&p.preco);

    max_p++;//quantidade max de produtos cadastrados
    return p;
}

void exibirProduto(Produto produtoDB[]){
    printf("\nExibicao dos Produtos cadastrados:\n");
    int j;
    for (j = 0; j < max_p; j++) {
        printf("\n   CODIGO: %d", j + 1);
        printf("\n Nome: %s", produtoDB[j].titulo);
        printf("\n Autor: %s", produtoDB[j].autor);
        printf("\n Data de lancamento: %d", produtoDB[j].data_lanc);
        printf("\n restricao de idade: %d", produtoDB[j].restricao_idade);
        printf("\n Genero: %s",produtoDB[j].genero.nome);
        printf("\n Editora: %s:",produtoDB[j].editora.nome);
        printf("\n Quantidade: %d", produtoDB[j].quantidade);
        printf("\n Preco: %lf", produtoDB[j].preco);
        printf("\n--------------------------------------------");
    }
}

Cliente cadastrarCliente(Cliente clienteDB[]) {
    Cliente c;
    printf("\n---------- Sistema de cadastro de cliente -----------\n");
    printf("Informe o nome: ");
    scanf(" %[^\n]", c.nome);

    printf("Informe a data de nascimento (sem barras e digitos unidos): ");
    scanf("%d", &c.data_nasc);

    printf("Informe o CPF: ");
    scanf("%d", &c.CPF);
    int cpfDuplicado = 0;
    // Verifica se já existe cliente com esse CPF
    for (int i = 0; i < max_c; i++) {
        if (clienteDB[i].CPF == c.CPF) {
            cpfDuplicado = 1;
            break;
        }
    }

    if (cpfDuplicado) {
        printf("\n CPF já cadastrado! Cadastro cancelado.\n");
        c.CPF = -1; // ou outro valor sinalizador de erro
        return c;
    }

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

Venda executarVenda(Cliente clienteDB[], Produto produtoDB[],Genero generoDB[],Editora editoraDB[]) {
    Venda v;
    int op, j;

    printf("Digite o codigo do livro: \n");

    // Exibir todos os produtos disponíveis
    for (j = 0; j < count_p; j++) {
        printf("%d - %s \n", j, produtoDB[j].titulo);
    }
    printf("99- para cadastrar novo produto\n");
    printf("\nDigite a opcao: ");

    // Ler o código do produto
    do {
        scanf("%d", &op);
    } while (!(op >= 0 && (op < count_c || op == 99))); // Verificar se o código é válido

    if(op == 99){
        cadastrarProduto(generoDB,editoraDB);
        printf("=======Voltando a venda===========\n");
    }
    else{
        v.produtoId = op;
        v.precoVenda = produtoDB[op].preco;
    }


    // Exibir os clientes cadastrados
    printf("Clientes:");
    for (j = 0; j < count_c; j++) {
        printf("%d - %s\n", j, clienteDB[j].nome);
    }

    // Caso o cliente não esteja cadastrado, permitir cadastro
    printf("99 - Para cadastrar um novo cliente\n");
    printf("\nDigite a opcao: ");

    // Ler a escolha do cliente
    do {
        scanf("%d", &op);
    } while (!(op >= 0 && (op < count_c || op == 99))); 

    if (op == 99) {
        cadastrarCliente(clienteDB);
        printf("=======Voltando a venda===========\n");

    } else {
        v.clienteCPF = clienteDB[op].CPF;
    }

    // Pedir a data da venda
    printf("Digite a data da venda (DD/MM/AAAA): ");
    scanf("%s", v.dataVenda);

    max_v++;
    return v;
}

void buscarVenda(Venda vendaDB[]){
    printf("\nExibicao dos vendas executadas:\n");
    int j;
    for (j = 0; j < max_v; j++) {
        printf("\n   CODIGO: %d", j + 1);
        printf("CPF do cliente -     %d",vendaDB[j].clienteCPF);
        printf("ID do produto  -     %d",vendaDB[j].produtoId);
        printf("preco da compra -    %f",vendaDB[j].precoVenda);
        printf("Data da venda -      %s",vendaDB[j].dataVenda);
        printf("\n--------------------------------------------");
    }
}

int main(void) {
    int op;
    Venda vendaDB[100];
    Cliente clienteDB[50];
    Editora editoraDB[30];
    Genero generoDB[30];
    Produto produtoDB[50];

    do {
        printf("\n---------------- Livraria Dois Irmaos ----------------");
        printf("\n1 - Gerenciamento de dados");
        printf("\n2 - Atendimento ao cliente");
        printf("\n3 - Sair");
        printf("\n\nDigite a opcao: ");
        scanf("%d", &op);

        switch (op) {
        case 1:
            do {
                printf("\n---------------- Livraria Dois Irmaos ----------------");
                printf("\nSistema de Cadastro");
                printf("\n\n1 - Gerenciar Clientes");
                printf("\n2 - Gerenciar Editoras");
                printf("\n3 - Gerenciar Generos");
                printf("\n4 - Gerenciar Produtos");
                printf("\n5 - Sair");
                printf("\n\nDigite a opcao: ");
                scanf("%d", &op);

                switch (op) {
                    case 1: // Gerenciamento de Clientes
                        do {
                            printf("\n------ Menu de Gerenciamento de Clientes ------");
                            printf("\n1 - Cadastrar Cliente");
                            printf("\n2 - Exibir Clientes");
                            printf("\n3 - Consultar CPF");
                            printf("\n4 - Voltar ao menu principal");
                            printf("\nDigite a opcao: ");
                            scanf("%d", &op);

                            switch (op) {
                                case 1:
                                    if (count_c < 50) {
                                        Cliente novo = cadastrarCliente(clienteDB);
                                        if (novo.CPF != -1) {
                                            clienteDB[count_c++] = novo;
                                        }

                                    } else {
                                        printf("Limite de clientes atingido.\n");
                                    }
                                    break;

                                case 2:
                                    exibirCliente(clienteDB);
                                    break;
                                case 3:
                                    consultarCpf(clienteDB);
                                    break;

                                case 4:
                                    printf("Voltando ao menu principal...\n");
                                    break;

                                default:
                                    printf("Opcao invalida. Tente novamente.\n");
                            }
                        } while (op != 4); // Voltar ao menu principal
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
                                    if (count_e < 30) {
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

                    case 3: // Gerenciamento de Generos
                        do {
                            printf("\n------ Menu de Gerenciamento de Generos ------");
                            printf("\n1 - Cadastrar Genero");
                            printf("\n2 - Exibir Generos");
                            printf("\n3 - Voltar ao menu principal");
                            printf("\nDigite a opcao: ");
                            scanf("%d", &op);

                            switch (op) {
                                case 1:
                                    if (count_g < 30) {
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

                    case 4: // Gerenciamento de Produtos
                        do {
                            printf("\n------ Menu de Gerenciamento de Produto ------");
                            printf("\n1 - Cadastrar Produto");
                            printf("\n2 - Exibir Produtos");
                            printf("\n3 - Voltar ao menu principal");
                            printf("\nDigite a opcao: ");
                            scanf("%d", &op);

                            switch (op) {
                                case 1:
                                    if (count_p < 50) {
                                        produtoDB[count_p++] = cadastrarProduto(generoDB, editoraDB);
                                    } else {
                                        printf("Limite de produtos atingido.\n");
                                    }
                                    break;

                                case 2:
                                    exibirProduto(produtoDB);
                                    break;

                                case 3:
                                    printf("Voltando ao menu principal...\n");
                                    break;

                                default:
                                    printf("Opcao invalida. Tente novamente.\n");
                            }
                        } while (op != 3); // Voltar ao menu principal
                        break;

                    case 5:
                        printf("Voltando ao menu geral...\n");
                        break;

                    default:
                        printf("Opcao invalida. Tente novamente.\n");
                }
            } while (op != 5); // Voltar ao menu geral
            break;

        case 2:
            do {
                printf("\n---------------- Livraria Dois Irmaos ----------------");
                printf("\n1 - Realizar venda: ");
                printf("\n2 - Buscar venda: ");
                printf("\n3 - voltar ao menu geral ");

                printf("\n\nDigite a opcao:");
                scanf("%d",&op);
                switch (op)
                    {
                    case 1:
                    if (count_v<100)
                    {
                        vendaDB[count_v++] = executarVenda(clienteDB,produtoDB,generoDB,editoraDB);
                    }else{
                        printf("Maximo de vendas atingido");
                    }
                    
                        break;
                    case 2:
                        buscarVenda(vendaDB);
                    default:
                        printf("Opcao invalida. Tente novamente.\n");
                    }
            }while (op!=3);
            break;

        case 3:
            printf("Encerrando o programa...\n");
            break;

        default:
            printf("Opcao invalida. Tente novamente.\n");
        }
    } while (op != 3); // Loop principal

    return 0;
}
