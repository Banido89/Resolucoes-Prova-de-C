#include <stdio.h>

#define QTD_COLUNAS 3

int removerRepetidos(int v[], int tam) {
    if (tam <= 0) return 0;
    int j = 0;
    for (int i = 1; i < tam; i++) {
        if (v[i] != v[j]) {
            j++;
            v[j] = v[i];
        }
    }
    return j + 1;
}

void ordenar(int v[], int tam) {
    for (int i = 0; i < tam - 1; i++) {
        for (int j = 0; j < tam - 1 - i; j++) {
            if (v[j] > v[j+1]) {
                int aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
        }
    }
}


void preencherPrimos(int v[], int tam) {
    if (tam <= 0) return;
    v[0] = 2;
    int count = 1;
    int candidato = 3;
    
    while (count < tam) {
        int ehPrimo = 1;
        for (int i = 0; i < count; i++) {
            if (candidato % v[i] == 0) {
                ehPrimo = 0;
                break;
            }
        }
        if (ehPrimo) {
            v[count] = candidato;
            count++;
        }
        candidato += 2;
    }
}

void maiorPorLinha(int m[][QTD_COLUNAS], int lin, int col, int v[]) {
    for (int i = 0; i < lin; i++) {
        v[i] = m[i][0];
        for (int j = 1; j < col; j++) {
            if (m[i][j] > v[i]) {
                v[i] = m[i][j];
            }
        }
    }
}
void inverterPalavras(char str[]) {
    int inicio = 0;
    
    for (int i = 0; ; i++) {
        if (str[i] == ' ' || str[i] == '\0') {
            int fim = i - 1;
            while (inicio < fim) {
                char aux = str[inicio];
                str[inicio] = str[fim];
                str[fim] = aux;
                inicio++;
                fim--;
            }
            inicio = i + 1;
        }
        if (str[i] == '\0') {
            break;
        }
    }
}

int main() {
    // Teste A & B: Vetor e Ordenação + Remover Repetidos
    int v[] = { 6, 3, 6, 3, 4, 7, 5, 6 };
    int tam = 8;
    ordenar(v, tam);
    int novoTam = removerRepetidos(v, tam);
    
    printf("Vetor sem repetidos: ");
    for (int i = 0; i < novoTam; i++) printf("%d ", v[i]);
    printf("\n");

   
    int primos[5];
    preencherPrimos(primos, 5);
    printf("Primeiros primos: ");
    for (int i = 0; i < 5; i++) printf("%d ", primos[i]);
    printf("\n");

    int matriz[2][QTD_COLUNAS] = { { 10, 5, 20 }, { 7, 15, 12 } };
    int maiores[2];
    maiorPorLinha(matriz, 2, QTD_COLUNAS, maiores);
    printf("Maiores por linha: %d, %d\n", maiores[0], maiores[1]);

    char frase[] = "o rato roeu";
    printf("Frase original: %s\n", frase);
    inverterPalavras(frase);
    printf("Frase invertida: %s\n", frase);

    return 0;
}
