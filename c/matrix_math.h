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
 * Função que multiplica uma matriz por um número, não importando suas dimensões
 * @param matriz  matriz de origem
 * @param destino matriz de destino
 * @param fator   número para a multiplicação
 * @param linha   nº de linhas da matriz
 * @param coluna  nº de colunas da matriz
 */
void multiplica_matriz_num_int(int *matriz, int *destino, int fator, int linha, int coluna) {

	int *orig, *dest;

	for (int i = 0; i < linha; i++) {
	    for (int j = 0; j < coluna; j++) {
	        orig = (matriz + j + i * coluna);
	        dest = (destino + j + i * coluna);

	        *dest = ((*orig) * fator);
	    }
	}

}

/**
 * Função alias para se multiplicar uma matriz por um número em seus próprios valores
 * @param matriz Matriz para a multiplicação
 * @param fator  Número para se multiplicar a matriz
 * @param linha  Nº de linhas da matriz
 * @param coluna N° de colunas da matriz
 */
void mult_matriz_num_self_int(int *matriz, int fator, int linha, int coluna) {
	multiplica_matriz_num_int((int *)matriz, (int *)matriz, fator, linha, coluna);
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

/**
 * Função que lineariza uma matriz de 2D em um vetor
 * @param  matriz matriz a ser linearizada
 * @param  linha  linhas da matriz
 * @param  coluna colunas da matriz
 * @param  vetor  vetor onde a matriz será linearizada
 * @param  len    dimensão do vetor
 * @return        Retorna 1 em caso de sucesso e 0 em caso de fracasso
 */
int lineariza_matriz_int(int *matriz, int linha, int coluna, int vetor[], int len) {
	if((linha * coluna) != len)
		return 0;

	int k = 0;

	for (int j = 0; j < coluna; j++)
	{
		for (int i = 0; i < linha; i++)
		{
			if(k <= len)
				vetor[k++] = *(matriz + j + i * coluna);
			else
				return 0;
		}
	}

	return 1;

}

/**
 * Imprime um vetor passado como parâmetro, tabulado na tela
 * @param vetor Vetor à ser impresso
 * @param len   Tamanho deste vetor
 */
void imprime_vetor_int(int vetor[], int len) {
	imprime_linha_variavel(len);
	for (int i = 0; i < len; i++)
		printf("| %7d ", vetor[i]);
	puts("");
	imprime_linha_variavel(len);
}

#endif /* MATRIX_MATH_H */