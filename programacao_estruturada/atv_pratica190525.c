#include <stdio.h>
#include <string.h>

#define MAX_FUNCIONARIOS 100
#define TAM_NOME 100

typedef struct {
    char nome[TAM_NOME];
    float salario;
} Funcionario;

// Lê a quantidade de funcionários
int lerQuantidadeFuncionarios() {
    int total;
    printf("Quantos funcionarios deseja cadastrar? ");
    scanf("%d", &total);
    return total;
}

// Lê os dados dos funcionários
void cadastrarFuncionarios(Funcionario funcionarios[], int total) {
    for (int i = 0; i < total; i++) {
        printf("\nFuncionario %d\n", i + 1);
        printf("Nome: ");
        scanf(" %[^\n]", funcionarios[i].nome);
        printf("Salario: R$ ");
        scanf("%f", &funcionarios[i].salario);
    }
}

// Lê o salário de referência
float lerSalarioReferencia() {
    float ref;
    printf("\nDigite o valor do salario de referencia: R$ ");
    scanf("%f", &ref);
    return ref;
}

// Exibe funcionários com salário acima da referência e retorna a quantidade
int exibirAcimaReferencia(Funcionario funcionarios[], int total, float referencia) {
    int contador = 0;
    printf("\nFuncionarios com salario acima de R$ %.2f:\n", referencia);
    for (int i = 0; i < total; i++) {
        if (funcionarios[i].salario > referencia) {
            printf("- %s: R$ %.2f\n", funcionarios[i].nome, funcionarios[i].salario);
            contador++;
        }
    }
    return contador;
}

int main() {
    Funcionario funcionarios[MAX_FUNCIONARIOS];
    int total = lerQuantidadeFuncionarios();

    if (total <= 0 || total > MAX_FUNCIONARIOS) {
        printf("Número inválido de funcionários.\n");
        return 1;
    }

    cadastrarFuncionarios(funcionarios, total);
    float referencia = lerSalarioReferencia();
    int acima = exibirAcimaReferencia(funcionarios, total, referencia);//retorna quantidade (int)  que estao acima do ref

    printf("\nTotal: %d funcionario(s) com salario acima de R$ %.2f\n", acima, referencia);

    return 0;
}
