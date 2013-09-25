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
		printf("+-------");
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
			printf("| %5d ", *(matriz + i + j * y));
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
		printf("| %5d ", vetor[i]);
	puts("|");
	imprime_linha_variavel(len);
}

/**
 * Inicializa uma matriz de tamanho definido nos parâmetros dado um valor inicial
 * @param matriz  Matriz a ser inicializada
 * @param inicio  início da sequência
 * @param linhas  nº de linhas da matriz
 * @param colunas nº de colunas da matriz
 */
void inicializa_matriz_sequencia_int(int *matriz, int inicio, int linhas, int colunas) {
	int *celula;

	for (int j = 0; j < linhas; j++)
		for (int i = 0; i < colunas; i++)
		{
			celula = (matriz + j + i * colunas);
			*celula = inicio++;			
		}
			
}

/**
 * Inicializa um vetor com valores pré-definidos
 * @param vetor Vetor à ser inicializado
 * @param valor Valor para inicializar o vetor
 * @param len   tamanho do vetor
 */
void inicializa_vetor_mesmo_valor(int vetor[], int valor, int len) {
	for (int i = 0; i < len; i++)
		vetor[i] = valor;	
}

/**
 * Inicializa um vetor com zeros
 * @param vetor Vetor à ser inicializado
 * @param len   Tamanho do vetor
 */
void inicializa_vetor_zero(int vetor[], int len) {
	inicializa_vetor_mesmo_valor(vetor, 0, len);
}

/**
 * Passa a soma de linhas para um vetor
 * @param  matriz  Matriz para se somar as linhas
 * @param  linhas  nº de linhas da matriz
 * @param  colunas nº de colunas da matriz
 * @param  soma    vetor para guardar a soma das linhas
 * @param  len     tamanho do vetor
 * @return         Retorna 0 se não validar os parâmetros e retorna 1 se sim
 */
int reduz_matriz_soma_linhas(int *matriz, int linhas, int colunas, int soma[], int len) {
	if(linhas != len && colunas != len)
		return 0;

	int *celula;

	for (int j = 0; j < linhas; j++) // Linhas
		for (int i = 0; i < colunas; i++) // Colunas
		{
			celula = (matriz + i + j * colunas);
			soma[j] += *celula;
		}

	return 1;
}

/**
 * Passa a soma de colunas para um vetor
 * @param  matriz  Matriz para se somar as colunas
 * @param  linhas  nº de linhas da matriz
 * @param  colunas nº de colunas da matriz
 * @param  soma    vetor para guardar a soma das colunas
 * @param  len     tamanho do vetor
 * @return         Retorna 0 se não validar os parâmetros e retorna 1 se sim
 */
int reduz_matriz_soma_colunas(int *matriz, int linhas, int colunas, int soma[], int len) {
	if(linhas != len && colunas != len)
		return 0;

	int *celula;

	for (int i = 0; i < colunas; i++) // Colunas
		for (int j = 0; j < linhas; j++) // Linhas
		{
			celula = (matriz + j + i * colunas);
			soma[j] += *celula;
		}

	return 1;
}

/**
 * Calcula a soma de elementos de uma determinada coluna de uma matriz
 * @param  matriz Matriz para o cálculo
 * @param  linhas número de linhas da matriz
 * @param  col    coluna à ser calculada
 * @return        soma dos elementos da coluna da matriz
 */
int soma_coluna_matriz_int(int *matriz, int linhas, int col) {
	int soma = 0, i, *celula;

	col--;

	for (i = 0; i < linhas; i++) {
		celula = (matriz + col + i * linhas);
		soma += *celula;
	}

	return soma;
}

/**
 * Calcula a soma de elementos de uma determinada linha de uma matriz
 * @param  matriz Matriz para o cálculo
 * @param  colunas número de colunas da matriz
 * @param  lin    linha à ser calculada
 * @return        soma dos elementos da .linha da matriz
 */
int soma_linha_matriz_int(int *matriz, int colunas, int lin) {
	int soma = 0, i, *celula;

	lin--;

	for (i = 0; i < colunas; i++) {
		celula = (matriz + i + lin * colunas);
		soma += *celula;
	}

	return soma;
}

/**
 * Calcula a soma da diagonal especificada de determinada matriz, de determinados tamanhos
 * @param  matriz Matriz sobre a qual serão efetuados os cálculos
 * @param  lin    Nº de linhas da matriz
 * @param  col    Nº de colunas da matriz
 * @param  dig    Diagonal à ser calculada a soma
 * @return        retorna a soma dos elementos da diagonal da matriz, ou zero se for encontrado erros ou
 *                        se a soma for zero mesmo
 */
int soma_diagonal_matriz_int(int *matriz, int lin, int col, char dig) {

	if(lin != col)
		return 0;

	int soma = 0, i, k = (lin - 1), *celula;

	if(dig == 'P')
		for (i = 0; i < lin; i++) {
			celula = (matriz + i + i * lin);
			soma += *celula;
		}
	else if(dig == 'S')
		for (i = 0; i < lin; i++) {
			celula = (matriz + i + (k - i) * lin);
			soma += *celula;
		}
	else
		return 0;

	return soma;
}

/**
 * Calcula a soma de todos os elementos da matriz
 * @param  matriz Matriz sobre a qual será calculada o total
 * @param  lin    Nº de linhas da matriz
 * @param  col    Nº de colunas da matriz
 * @return        A soma dos elementos da matriz
 */
int soma_elementos_matriz_int(int *matriz, int lin, int col) {
	int soma = 0, *celula;

	for (int i = 0; i < lin; i++)
	{
		for (int j = 0; j < col; j++)
		{
			celula = (matriz + j + i * col);
			soma += *celula;
		}
	}

	return soma;
}
#endif /* MATRIX_MATH_H */