/**
 * Exercício 2 da lista de exercícios de matrizes
 */
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "matrix_math.h"
#include "menu.h"

// X é o nº de colunas
#define X_TAM_2 4
// Y é o nº de linhas
#define Y_TAM_2 3

// Início da sequência
#define INIT_2 1


// Exercício 2
void exercicio_2() {

	// Inicializa as matrizes
	int matriz1[X_TAM_2][Y_TAM_2], matriz2[X_TAM_2][Y_TAM_2], destino[X_TAM_2][Y_TAM_2];

	// Inicializa as outras variáveis
	int i, j, k = INIT_2;

	// Inicializa as matrizes com os valores designados
	for (j = 0; j < Y_TAM_2; j++) // Itera sobre as linhas
		for (i = 0; i < X_TAM_2; i++) // Itera sobre as colunas
			printf("Valor --> %d, i --> %d, j --> %d\n", matriz1[i][j] = matriz2[i][j] = k++, i, j);


	// Tentando imprimir a matriz
	imprime_matriz_int((int *)matriz1, X_TAM_2, Y_TAM_2);

}


// Exercício 3
void exercicio_3() {
	puts("IÈ IÈ PEGADINHA DO MALANDRO");                    
}

int main() {

	char op = '0';

	while(op = get_option()) {

		switch (op) {
		case '1':
			exercicio_2();
			break;
		case '2':
			exercicio_3();
			break;
		case '0':
			encerra_programa();
			break;
		}

		limpa_stdin();
		para_menu();

	}

	return 0;

}