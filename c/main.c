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
	inicializa_matriz_sequencia_int((int *)matriz, INIT_2, X_TAM_3, X_TAM_3);

	for (int i = 0; i < Y_TAM_3; i++)
		vetor[i] = 0;


	// Exibições
	system("clear");
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


// Exercício 4
void exercicio_4() {
	// Declaração da matriz e dos vetores
	int matriz[X_TAM_3][X_TAM_3], soma_linhas[X_TAM_3], soma_colunas[X_TAM_3];

	// Inicialização
	inicializa_matriz_sequencia_int((int *)matriz, INIT_2, X_TAM_3, X_TAM_3);
	inicializa_vetor_zero(soma_linhas, X_TAM_3);
	inicializa_vetor_zero(soma_colunas, X_TAM_3);

	reduz_matriz_soma_colunas((int *)matriz, X_TAM_3, X_TAM_3, soma_colunas, X_TAM_3);
	reduz_matriz_soma_linhas((int *)matriz, X_TAM_3, X_TAM_3, soma_linhas, X_TAM_3);

	// Impressão
	system("clear");
	cabecalho();

	// Matriz original
	puts("\nMatriz original:");
	imprime_matriz_int((int *)matriz, X_TAM_3, X_TAM_3);

	// Soma de colunas
	puts("\nSoma das colunas:");
	imprime_linha_variavel(X_TAM_3);
	for(int i = 0; i < X_TAM_3; i++)
		printf("| SL#%2d ", i + 1);
	puts("|");
	imprime_vetor_int(soma_colunas, X_TAM_3);

	// Soma de linhas
	puts("\nSoma das linhas");
	imprime_linha_variavel(X_TAM_3);
	for (int i = 0; i < X_TAM_3; i++)
		printf("| SC#%2d ", i + 1);
	puts("|");
	imprime_vetor_int(soma_linhas, X_TAM_3);

}

// Exercício 5
void exercicio_5() {

	// Declara matriz 4x4
	int matriz[X_TAM_3][X_TAM_3];

	// inicializa a matriz
	inicializa_matriz_sequencia_int((int *)matriz, INIT_2, X_TAM_3, X_TAM_3);

	system("clear");
	cabecalho();

	puts("\nMatriz:");
	imprime_matriz_int((int *)matriz, X_TAM_3, X_TAM_3);

	puts("\nSoma dos elementos da 4º linha:");
	imprime_linha_variavel(1);
	printf("| %5d |\n", soma_coluna_matriz_int((int *)matriz, X_TAM_3, 4));
	imprime_linha_variavel(1);

	puts("\nSoma dos elementos da 2º coluna:");
	imprime_linha_variavel(1);
	printf("| %5d |\n", soma_linha_matriz_int((int *)matriz, X_TAM_3, 2));
	imprime_linha_variavel(1);

	puts("\nSoma dos elementos da diagonal principal:");
	imprime_linha_variavel(1);
	printf("| %5d |\n", soma_diagonal_matriz_int((int *)matriz, X_TAM_3, X_TAM_3, 'P'));
	imprime_linha_variavel(1);

	puts("\nSoma dos elementos da diagonal secundária:");
	imprime_linha_variavel(1);
	printf("| %5d |\n", soma_diagonal_matriz_int((int *)matriz, X_TAM_3, X_TAM_3, 'S'));
	imprime_linha_variavel(1);
	
	puts("\nSoma de todos os elementos da matriz:");
	imprime_linha_variavel(1);
	printf("| %5d |\n", soma_elementos_matriz_int((int *)matriz, X_TAM_3, X_TAM_3));
	imprime_linha_variavel(1);

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
		case '3':
			exercicio_4();
			break;
		case '4':
			exercicio_5();
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