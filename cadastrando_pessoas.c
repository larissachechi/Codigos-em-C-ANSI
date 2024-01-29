//GUARDANDO IDENTIFICAÇÃO DE PESSOAS
#include <stdio.h>
#define MAX 3
#define NOME 30

typedef struct {
    int codigo;
    int idade;
    char nome[NOME];
} pessoas;

int main() {
    pessoas pessoa[MAX] = {0}; // vetor de pessoas
    int i, j;

    for (i = 0; i < MAX; i++) {
        printf("Informe o codigo da pessoa %d:", i + 1);
        scanf("%d", &pessoa[i].codigo);

        // percorre o vetor para ver se nao ha codigos iguais
        for (j = -1; j < i; j++) {
            if (pessoa[j].codigo == pessoa[i].codigo) {
                printf("Informe outro codigo:");
                scanf("%d", &pessoa[i].codigo);
            }
        }
        // Limpa o buffer de entrada antes de usar fgets
        while (getchar() != '\n');

        printf("Informe o nome da pessoa %d:", i + 1);
        fgets(pessoa[i].nome, NOME, stdin);
        pessoa[i].nome[strcspn(pessoa[i].nome, "\n")] = '\0';  // Remove a quebra de linha do final do nome

        printf("Informe a idade da pessoa %d:", i + 1);
        scanf("%d", &pessoa[i].idade);
        printf("\n");
    }

    for (i = 0; i < MAX; i++) {
        printf("A pessoa %d tem o codigo %d e idade %d.\n", i + 1, pessoa[i].codigo, pessoa[i].idade);
    }

    return 0;
}
