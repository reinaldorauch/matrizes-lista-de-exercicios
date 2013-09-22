#ifndef MATRIX_MATH_H
#define MATRIX_MATH_H

#pragma once

/**
 * Função que recebe 3 matrizes para somar cada valor das duas primeiras e dar o resultado na terceira
 * @param matriz1 1º operando
 * @param matriz2 2º Operando
 * @param destino Matriz de destino
 * @param x       Tamanho x das matrizes
 * @param y       Tamanho y das matrizes
 */
void soma_matrizes_int(int matriz1[][100], int matriz2[][100], int destino[][100], int x, int y) {

	int i, j;

	for(i = 0; i < x; i++)
		for (j = 0; j < y; j++) {
			destino[i][j] = matriz1[i][j] + matriz2[i][j];
		}

}


/**
 * Imprime uma linha de separação entre linhas de tabela
 * @param len tamanho da linha
 */
void imprime_linha_variavel(int len) {
	int j;
	for (j = 0; j < len; j++)
		printf("+---------");
	puts("+");
}

/**
 * Função para imprimir um array de 2 dimensões e de inteiros
 * @param matriz A matriz à ser imprimida
 * @param x      tamanho de colunas da matriz
 * @param y      tamanho de linhas da matriz
 */
void imprime_matriz_int(int **matriz, int x, int y) {
	int i, j;

	// itera sobre as colunas da matriz
	for (i = 0; i < x; i++) {

		printf("i: %d\n", i);

		// Imprime a linha de separação entre as linhas
		imprime_linha_variavel(y);

		// Imprime a linha propriamente dita da matriz
		for (j = 0; j < y; j++) {
			printf("| %7d ", matriz[i][j]);
		}
		puts("|");

	}
	imprime_linha_variavel(y);

}

#endif /* MATRIX_MATH_H */