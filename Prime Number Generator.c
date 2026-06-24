
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void gerar_primos(int n) {
    // Aloca memória dinamicamente para suportar limites maiores
    bool *eh_primo = malloc((n + 1) * sizeof(bool));
    
    // Inicializa todo o array como verdadeiro
    for (int i = 0; i <= n; i++) {
        eh_primo[i] = true;
    }
    eh_primo[0] = eh_primo[1] = false;

    // Algoritmo do Crivo
    for (int p = 2; p * p <= n; p++) {
        if (eh_primo[p]) {
            for (int i = p * p; i <= n; i += p) {
                eh_primo[i] = false;
            }
        }
    }

    // Imprime os números primos encontrados
    printf("Numeros primos ate %d:\n", n);
    for (int p = 2; p <= n; p++) {
        if (eh_primo[p]) {
            printf("%d ", p);
        }
    }
    printf("\n");

    // Libera a memória alocada
    free(eh_primo);
}

int main() {
    int limite = 100; // Altere este valor para mudar o limite
    gerar_primos(limite);
    return 0;
}

#Gerador de números primos em C
