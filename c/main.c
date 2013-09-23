/**
 * Exercício 2 da lista de exercícios de matrizes
 */
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "matrix_math.h"
#include "menu.h"

// X é o nº de colunas, exercício 2
#define X_TAM_2 4
// Y é o nº de linhas, exercício 2
#define Y_TAM_2 3

// Início da sequência,
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
			matriz1[i][j] = matriz2[i][j] = k++;


	// Imprimindo a matriz
	
	system("clear");
	cabecalho();

	puts("\n------------------ Primeira matriz ------------------");

	imprime_matriz_int((int *)matriz1, X_TAM_2, Y_TAM_2);

	puts("\n------------------ Segunda matriz ------------------");

	imprime_matriz_int((int *)matriz2, X_TAM_2, Y_TAM_2);


	// Somando as matrizes
	soma_matrizes_int((int *)matriz1, (int *)matriz2, (int *)destino, X_TAM_2, Y_TAM_2);

	// Imprime matriz de resultado
	puts("\n\n------------------ Resultado ------------------");
	imprime_matriz_int((int *)destino, X_TAM_2, Y_TAM_2);

}

// Tamanho da matriz quadrada 
#define X_TAM_3 4

// Tamanho do array
#define Y_TAM_3 16

// Exercício 3
void exercicio_3() {
	
	// Declaração
	int matriz[X_TAM_3][X_TAM_3], vetor[Y_TAM_3], k = INIT_2;

	// Inicializações
	for (int j = 0; j < X_TAM_3; j++)
		for (int i = 0; i < X_TAM_3; i++)
			matriz[i][j] = k++;

	for (int i = 0; i < Y_TAM_3; i++)
		vetor[i] = 0;


	// Exibições
	cabecalho();

	puts("\n------------------ Matriz original ------------------");
	imprime_matriz_int((int *)matriz, X_TAM_3, X_TAM_3);

	// Multiplicando a matriz por 5
	mult_matriz_num_self_int((int *)matriz, 5, X_TAM_3, X_TAM_3);

	puts("\n------------------ Matriz após multiplicação por 5 ------------------");
	imprime_matriz_int((int *)matriz, X_TAM_3, X_TAM_3);

	// lineariza a matriz
	if(lineariza_matriz_int((int *)matriz, X_TAM_3, X_TAM_3, vetor, Y_TAM_3)){
		puts("\n------------------ Matriz linearizada ------------------");
		imprime_vetor_int(vetor, Y_TAM_3);
	}

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