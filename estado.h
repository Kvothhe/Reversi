//
// Created by pja on 27/02/2019.
//



#ifndef PROJ_ESTADO_H
#define PROJ_ESTADO_H


/**
estado.h
Definição do estado i.e. tabuleiro. Representação matricial do tabuleiro.
*/


// definição de valores possiveis no tabuleiro
typedef enum {VAZIA, VALOR_X, VALOR_O} VALOR;

/**
Estrutura que armazena o estado do jogo
*/
typedef struct estado {
    VALOR peca; // peça do jogador que vai jogar!
    VALOR grelha[8][8];
    int scoresx;
    int scoreo;
    char modo; // modo em que se está a jogar! 0-> manual, 1-> contra computador
} ESTADO;

struct Node
{
    ESTADO e;
    struct Node* next;
};
struct Node* top;

void printa(ESTADO, int);

int pCima(char);
void newGame(ESTADO*, int, int);
void limpar(ESTADO*);
void valida(ESTADO, int*,int*);
void jogaveis(ESTADO, int, int, int*,int*);
VALOR contrario(VALOR v);
void printaValor(VALOR v);
void zerarValidas(int*);
void validarJog(ESTADO, int*,int*);
void ordenar(int*,int);
int posv(ESTADO,int*,int,int,int,int*);
void capturapecas(ESTADO*,int*,int*,int*,int *, int *);
void scores(ESTADO*);
void push(ESTADO);
ESTADO pop();
void saveEstado (char*, ESTADO*, int*, int*);
void carregaEstado (char*, ESTADO*);
int alea(ESTADO,int*,int*);
void hint(ESTADO,int*,int *);
int checkawin(ESTADO);
void win(ESTADO);
ESTADO botfacil(ESTADO e,int validas[],int *v, int *);

#endif //PROJ_ESTADO_H
