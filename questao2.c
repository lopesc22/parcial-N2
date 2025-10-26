#include <stdio.h>
#include <stdlib.h>

int* cria_vetor(int n) {
    return (int*) malloc(n * sizeof(int));
}

void imprime_vetor(int *vetor, int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

void libera_vetor(int *vetor) {
    free(vetor);
}

int main() {
    int n;
    printf("Informe o tamanho do vetor: ");
    scanf("%d", &n);

    int *vetor = cria_vetor(n);

    for(int i = 0; i < n; i++) {
        printf("Informe o valor da posicao %d: ", i);
        scanf("%d", &vetor[i]);
    }

    imprime_vetor(vetor, n);
    libera_vetor(vetor);

    return 0;
}
