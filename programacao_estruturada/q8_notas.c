#include <stdio.h>

int main(void) {
    float n[3], ave = 0.0;

    // Captura as notas do usuário
    for (int i = 0; i < 3; i++) {
        printf("Digite a nota %d: ", i + 1);
        scanf("%f", &n[i]);

        ave += n[i]; // Soma as notas para calcular a média
    }

    ave /= 3; // Calcula a média das notas

    // Exibe a média calculada
    printf("\nMedia das notas: %.2f\n", ave);

    // Verifica a situação do aluno com base na média
    if (ave >= 7) {
        printf("Status: APROVADO\n");
    } else if (ave >= 4) {
        printf("Status: PROVA FINAL\n");
    } else {
        printf("Status: REPROVADO\n");
    }

    return 0;
}
