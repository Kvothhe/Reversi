#include <stdio.h>
#include <malloc.h>
#include "estado.h"


int main()
{

    int x,y, check, nivel;
    char linha[50], file[20];
    char c1,c2;
    int validas[512] = {};
    int v;
    ESTADO e = {0};
    ESTADO p;
    check = 1;

    // estado inicial do tabuleiro. Inicio do jogo!

    e.grelha[3][4] = VALOR_X;
    e.grelha[4][3] = VALOR_X;
    e.grelha[3][3] = VALOR_O;
    e.grelha[4][4] = VALOR_O;
    e.peca = VALOR_X;
    e.scoresx = 2;
    e.scoreo = 2;
/*
    e.grelha[2][3] = VALOR_X;
    e.grelha[1][3] = VALOR_O;
*/

    //e.grelha[2][2] = VALOR_X;
    //zerarValidas();
    push(e);
    printf("\n");
    printa(e, check);
    printf("\n");

    check = 0;
    //Comandos
    do {
        fgets(linha,50,stdin);

        switch (pCima(linha[0])) {
            case 'N':
                sscanf(linha, "%c %c", &c1, &c2);
                check = 1;
                newGame(&e,pCima(c2), check);
                break;
            case 'L':
                sscanf(linha, "%c %s", &c1, file);
                printf("Ler do %s\n", file); //file -> ficheiro
                carregaEstado(file, &e);
                break;
            case 'E':
                sscanf(linha, "%c %s", &c1, file);
                printf("Guardar como %s\n", file); //file -> ficheiro
                saveEstado(file, &e, validas, &v);
                break;
            case 'J':
                sscanf(linha, "%c %d %d", &c1, &x, &y);
                --y, --x;
                zerarValidas(validas);
                capturapecas(&e,&x,&y,validas,&v, &check);
                passaJogada(&e,validas,&v);
                printa(e, check);
                if(e.modo == 1)
                    bot(&e,pCima(c2),nivel,validas,&v, &check);
                if(checkawin(e))
                {
                    win(e);
                    linha[0] = 'Q';
                }
                //push(e);
                break;
            case 'S':
                valida(e, validas,&v);
                // Imprimir um ponto‘.’ nas posições com jogada válida.
                break;
            case 'H':
                //validas[0] = "\0";
                hint(e,validas,&v);
                // Sugestão de jogada. Deve ser colocado um ‘?’ no sitio sugerido.
                break;
            case 'U':
                // Para desfazer a última jogada(Undo). Isto tem de permitir desfazer até ao estado inicial do jogo!
                sscanf(linha,"%c",&c1);
                e = pop();
                printa(e, check);
                break;
            case 'A':
                // Comando para inicializar o bot. Possui três niveis de dificuldade.
                sscanf(linha, "%c %c %d", &c1, &c2, &nivel);
                printf("Bot joga com %c, nível %d\n", pCima(c2), nivel);
                if((nivel == 1 || nivel == 2 || nivel == 3) && (pCima(c2) == 'X' || pCima(c2) == 'O'))
                {
                    e.modo = 1;
                    bot(&e, pCima(c2), nivel, validas, &v, &check);
                }
                else
                    printf("Bot Inválido\n");
                break;
        }
    } while(pCima(linha[0]) != 'Q');

    return 0;
}
