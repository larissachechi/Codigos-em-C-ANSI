#include <stdio.h>
#define MAX 2
typedef struct {
    int codigo;
    int pendentes;
    float salario;
} FUNCIONARIO;

void reajuste(FUNCIONARIO vetor[], float referencia);

int main() {
    FUNCIONARIO vetor[MAX];
    float referencia;
    int i;

    printf("Informe um valor de referencia salarial:");
    scanf("%f", &referencia);

    for (i = 0; i < MAX; i++) {
        printf("Informe o codigo, salario e pendencias do funcionario %d:", i + 1);
        scanf("%d %f %d", &vetor[i].codigo, &vetor[i].salario, &vetor[i].pendentes);
    }
    reajuste(vetor, referencia);

    return 0;
}

void reajuste(FUNCIONARIO vetor[], float referencia) {
    int i;
    float novo_salario;
    float salario_antigo;

    for (i = 0; i < MAX; i++) {
        salario_antigo = vetor[i].salario;  // Salva o salário atual

        if (vetor[i].pendentes <= 2) {
            novo_salario = ((3.0 / 100) * salario_antigo) + salario_antigo;
        } else if (vetor[i].pendentes > 2 && vetor[i].pendentes <= 5 && vetor[i].salario < referencia) {
            novo_salario = ((10.0 / 100) * salario_antigo) + salario_antigo;
        } else if (vetor[i].pendentes > 2 && vetor[i].pendentes < 5 && vetor[i].salario > referencia) {
            novo_salario = ((5.0 / 100) * salario_antigo) + salario_antigo;
        } else if (vetor[i].pendentes >= 5) {
            novo_salario = ((15.0 / 100) * salario_antigo) + salario_antigo;
        }

        printf("Funcionario %d tem %d pendencia e seu antigo salario era: %.2f \n foi reajustado para: %2.3f\n", i + 1, vetor[i].pendentes, salario_antigo, novo_salario);

    }
}
