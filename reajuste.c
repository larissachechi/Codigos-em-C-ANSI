//O reajuste do salário deve ser calculado pelo programa, da seguinte forma:
//* Se o funcionário tem menos de 2 dependentes, ele recebe reajuste de
//3% do salário.
//* Se ele tem entre 2 e 5 e tiver salário menor que o valor de referência,
//sele recebe um reajuste de 10% do salário.
//* Se ele tem entre 2 e 5 e tiver salário maior que o valor de referência,
//sele recebe um reajuste de 5% do salário.
//* Se ele tem mais de 5 dependentes, ele recebe reajuste de 15% do
//salário. 

#include <stdio.h>
#define MAX 10
typedef struct {
    int codigo;
    int dependentes;
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
        printf("Informe o codigo, salario e dependentes do funcionario %d:", i + 1);
        scanf("%d %f %d", &vetor[i].codigo, &vetor[i].salario, &vetor[i].dependentes);
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

        if (vetor[i].dependentes <= 2) {
            novo_salario = ((3.0 / 100) * salario_antigo) + salario_antigo;
        } else if (vetor[i].dependentes > 2 && vetor[i].dependentes <= 5 && vetor[i].salario < referencia) {
            novo_salario = ((10.0 / 100) * salario_antigo) + salario_antigo;
        } else if (vetor[i].dependentes > 2 && vetor[i].dependentes < 5 && vetor[i].salario > referencia) {
            novo_salario = ((5.0 / 100) * salario_antigo) + salario_antigo;
        } else if (vetor[i].dependentes >= 5) {
            novo_salario = ((15.0 / 100) * salario_antigo) + salario_antigo;
        }

        printf("Funcionario %d tem %d dependentes e seu antigo salario era: %.2f \n foi reajustado para: %2.3f\n", i + 1, vetor[i].dependentes, salario_antigo, novo_salario);

    }
}
