//
// Created by pja on 28/02/2019.
//
#include <stdio.h>
#include "estado.h"


// exemplo de uma função para imprimir o estado (Tabuleiro)
void printa(ESTADO e, int check)
{
    char c = ' ';
    int a;

    if (e.modo == 0)
        printf("Modo: 2jog");
    if (e.peca == VALOR_O)
        printf("-- Jogador: O\n ");
    else
        printf("-- Jogador: X\n ");
    for (a = 1; a < 9; ++a)
        printf(" %d",a);
    putchar('\n');
    a = 1;
    for (int i = 0; i < 8; i++, a++) {
        printf("%d ", a);
        for (int j = 0; j < 8; j++) {
            switch (e.grelha[i][j]) {
                case VALOR_O: {
                    c = 'O';
                    break;
                }
                case VALOR_X: {
                    c = 'X';
                    break;
                }
                case VAZIA: {
                    c = '-';
                    break;
                }
            }
            printf("%c ", c);

        }
        printf("\n");
    }
    printf("\n");
    printf( "X: %d  |  O: %d\n",e.scoresx,e.scoreo);

    if (check == 0)
        printf("Jogada Inválida\n");

}

