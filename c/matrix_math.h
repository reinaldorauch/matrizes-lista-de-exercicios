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
void soma_matrizes_int(int *matriz1, int *matriz2, int *destino, int x, int y) {
	// Variáveis normais
	int i, j;
	// Ponteiros
	int *val_des = NULL, *val_1, *val_2;

	for (j = 0; j < x; j++)
		for(i = 0; i < y; i++)
		{

			// Ponteiro para a célula de destino
			val_des = (destino + i + j * y);

			// Ponteiro para a célula da primeira matriz
			val_1 = (matriz1 + i + j * y);

			// Ponteiro para a célula da segunda matriz
			val_2 = (matriz2 + i + j * y);

			// Realizando a soma com as células correspondentes das duas primeiras matrizes
			// e passando o resultado para a célula correspondente na matriz de destino
			*val_des = *val_1 + *val_2;

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
void imprime_matriz_int(int *matriz, int x, int y) {
	int i, j;

	// itera sobre as colunas da matriz
	for (i = 0; i < y; i++) {

		/*printf("i: %d\n", i);*/

		// Imprime a linha de separação entre as linhas
		imprime_linha_variavel(x);

		// Imprime a linha propriamente dita da matriz
		for (j = 0; j < x; j++) {
			printf("| %7d ", *(matriz + i + j * y));
		}
		puts("|");

	}
	imprime_linha_variavel(x);

}

#endif /* MATRIX_MATH_H */