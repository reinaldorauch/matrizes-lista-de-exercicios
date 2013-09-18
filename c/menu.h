#ifndef MENU_H
#define MENU_H

#pragma once

/**
 * Printa na tela do usuário o cabeçalho do programa
 */
void cabecalho() {
    puts("---------------------------------------------------------");
    puts("\tExercícios do dia 04/09/2013 de matrizes");
    puts("---------------------------------------------------------");
}

/**
 * Função placeholder para opções do menu ainda não implementadas
 */
void nao_implementado() {
	printf("+-----------------------------------------------------\n");
	printf("| Função não implementada ainda\n");
	printf("+-----------------------------------------------------\n");
}

/**
 * Limpa a stream stdin
 */
void limpa_stdin(){
	char c;
	while((c = getchar()) != '\n' && c != EOF);
}

/**
 * Para o menu
 */
void para_menu() {
	puts("\nPressione enter para continuar");
	limpa_stdin();
}

/**
 * Força a saída do programa
 */
void encerra_programa() {
	puts("\n Saindo....");
	exit(0);
}

/**
 * Imprime as opções e recebe a opção escolhida
 */
char get_option() {
    char c;

    puts("Selecione uma opção:\n");
    puts("\t[1] Executar o programa para o exercício 2");
    puts("\t[2] Executar o programa para o exercício 3");
    puts("\t[0] Sair do programa");

    while((c = getchar()) != '\n')

    return c;
}

#endif /* MENU_H */