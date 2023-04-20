#include <bits/stdc++.h>
#include <iostream>

#include "NoAVL.h"

using namespace std;

class ArvoreAVL {
private:
    NoAVL *raiz; //ponteiro para a raiz da árvore

public:
    ArvoreAVL(); //construtor
    ~ArvoreAVL(); //destrutor
    
    int altura(NoAVL *no); //retorna a altura do nó
    int fatorBalanceamento(NoAVL *no); //retorna o fator de balanceamento do nó

    NoAVL *rotacaoEsquerda(NoAVL *no); //rotaciona o nó para a esquerda
    NoAVL *rotacaoDireita(NoAVL *no); //rotaciona o nó para a direita
    NoAVL *rotacaoEsquerdaDireita(NoAVL *no); //rotaciona o nó para a esquerda e depois para a direita
    NoAVL *rotacaoDireitaEsquerda(NoAVL *no); //rotaciona o nó para a direita e depois para a esquerda
    NoAVL *inserir(NoAVL *no, int chave); //insere um nó na árvore
    NoAVL *remover(NoAVL *no, int chave); //remove um nó da árvore
    NoAVL *minimo(NoAVL *no); //retorna o nó com a menor chave da árvore

    void percorrerPreOrdem(NoAVL *no); //imprime a árvore em pré-ordem
    void percorrerInOrdem(NoAVL *no); //imprime a árvore em ordem
    void percorrerPosOrdem(NoAVL *no); //imprime a árvore em pós-ordem
    void limpar(NoAVL *no); //limpa a árvore
    void imprimirAVL(); //imprime a árvore
};