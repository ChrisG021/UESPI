
//CHRISTOPHE GABRIEL S L GUERRA


#include <stdio.h>

#define MAX_CURSOS 3
#define MAX_ALUNOS 5

typedef struct {
    char nome[100];
    int matricula;
    float nota_final;
} Aluno;

typedef struct {
    char nomeCurso[100];
    int codigo;
    Aluno alunos[MAX_ALUNOS];
    int total_alunos;
} Curso;

int main() {
    Curso cursos[MAX_CURSOS];
    int totalCursos = 0;
    int opcao;

    while (1) {
        printf("\nMenu:\n");
        printf("1 - Cadastrar curso\n");
        printf("2 - Cadastrar aluno\n");
        printf("3 - Listar cursos e alunos\n");
        printf("4 - Exibir media de notas de um curso\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (totalCursos >= MAX_CURSOS) {
                    printf("Limite de cursos atingido\n");
                    continue;
                }
                printf("Nome do curso (sem espacos): ");
                scanf("%s", cursos[totalCursos].nomeCurso);
                printf("Codigo do curso: ");
                scanf("%d", &cursos[totalCursos].codigo);
                cursos[totalCursos].total_alunos = 0;
                totalCursos++;
                break;

            case 2: {
                int codigo;
                int encontrado = 0;
                printf("Informe o codigo do curso: ");
                scanf("%d", &codigo);

                for (int i = 0; i < totalCursos; i++) {
                    if (cursos[i].codigo == codigo) {
                        encontrado = 1;
                        if (cursos[i].total_alunos >= MAX_ALUNOS) {
                            printf("Curso cheio\n");
                            break;
                        }
                        Aluno *a = &cursos[i].alunos[cursos[i].total_alunos];
                        printf("Nome do aluno (sem espacos): ");
                        scanf("%s", a->nome);
                        printf("Matricula: ");
                        scanf("%d", &a->matricula);
                        printf("Nota final: ");
                        scanf("%f", &a->nota_final);
                        cursos[i].total_alunos++;
                        break;
                    }
                }

                if (!encontrado) {
                    printf("Curso nao encontrado\n");
                }
                break;
            }

            case 3:
                for (int i = 0; i < totalCursos; i++) {
                    printf("\nCurso: %s | Codigo: %d\n", cursos[i].nomeCurso, cursos[i].codigo);
                    for (int j = 0; j < cursos[i].total_alunos; j++) {
                        Aluno a = cursos[i].alunos[j];
                        printf("  Nome: %s | Matricula: %d | Nota: %.2f\n", a.nome, a.matricula, a.nota_final);
                    }
                }
                break;

            case 4: {
                int codigo;
                int encontrado = 0;
                printf("Informe o codigo do curso: ");
                scanf("%d", &codigo);

                for (int i = 0; i < totalCursos; i++) {
                    if (cursos[i].codigo == codigo) {
                        encontrado = 1;
                        if (cursos[i].total_alunos == 0) {
                            printf("Nenhum aluno neste curso\n");
                            break;
                        }
                        float soma = 0;
                        for (int j = 0; j < cursos[i].total_alunos; j++) {
                            soma += cursos[i].alunos[j].nota_final;
                        }
                        float media = soma / cursos[i].total_alunos;
                        printf("Media das notas: %.2f\n", media);
                        break;
                    }
                }

                if (!encontrado) {
                    printf("Curso nao encontrado\n");
                }
                break;
            }

            case 0:
                printf("Saindo do programa\n");
                return 0;

            default:
                printf("Opcao invalida\n");
                break;
        }
    }

    return 0;
}
