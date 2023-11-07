#include <stdio.h>

int main() {
    int numeros[10];  // Declara um array de 10 inteiros

    for (int i = 0; i < 10; i++) {
        scanf("%d", &numeros[i]);
    }

    // Imprime os 10 números, separados por um espaço
    for (int i = 0; i < 10; i++) {
        printf("%d", numeros[i]);
        if (i < 9) {  // Não imprime um espaço após o último número
            printf(" ");
        }
    }
    printf("\n"); 

    for (int currentNum = 10; currentNum > 1; currentNum--) {
        int novoNumero[currentNum - 1];  

        for (int i = 0; i < currentNum - 1; i++) {
            novoNumero[i] = numeros[i] + numeros[i + 1];
        }

        for (int i = 0; i < currentNum - 1; i++) {
            numeros[i] = novoNumero[i];  

            printf("%d", numeros[i]);
            if (i < currentNum - 2) {  // Não imprime um espaço após o último número
                printf(" ");
            }
        }
        printf("\n"); 
    }

    return 0;  
}