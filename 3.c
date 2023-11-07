#include <stdio.h>
#include <locale.h>
#include <string.h>

#define size 4 //Tamanho das matrizes

//Função: leitura da matriz
void readMatrix(int matrix[size][size]) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            scanf("%d", &matrix[i][j]); 
}

//Função: adição das duas matrizes
void add(int m1[size][size], int m2[size][size], int res[size][size]) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            res[i][j] = m1[i][j] + m2[i][j]; 
}

//Função: subtração das duas matrizes
void subtract(int m1[size][size], int m2[size][size], int res[size][size]) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            res[i][j] = m1[i][j] - m2[i][j]; 
}

//Função: multiplicação das duas matrizes
void multiply(int m1[size][size], int m2[size][size], int res[size][size]) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            res[i][j] = 0;
            for (int k = 0; k < size; k++)
                res[i][j] += m1[i][k] * m2[k][j]; 
        }
    }
}

//Função: impressão da matriz
void printMatrix(int matrix[size][size]) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            printf("%4d", matrix[i][j]);
        printf("\n");
    }
}

int main() {
    int m1[size][size]; //Primeira matriz
    int m2[size][size]; //Segunda matriz
    int res[size][size]; //Matriz do resultado
    char operation[5];  //String para armazenar a operação

    setlocale (LC_ALL,"Portuguese"); 
    readMatrix(m1); 

    readMatrix(m2); 


    scanf("%s", operation); 

   //Comandos das operações
    if (strcmp(operation, "soma") == 0) {
        add(m1, m2, res);

    } else if (strcmp(operation, "sub") == 0) {
        subtract(m1, m2, res);

    } else if (strcmp(operation, "mult") == 0) {
        multiply(m1, m2, res);
    } else {
        printf("\nOperação desconhecida.\n"); //Caso a operação não seja reconhecida
        return 1; 
    }

    printMatrix(res); //Imprime a matriz resultante

    return 0;
}