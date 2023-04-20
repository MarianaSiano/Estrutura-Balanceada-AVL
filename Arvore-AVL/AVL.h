#include <bits/stdc++.h>
#include <iostream>

#include "NoAVL.h"

using namespace std;

class AVL {
private:
    NoAVL *raiz;

    int altura(NoAVL *no);
    int fatorBalanceamento(NoAVL *no);
    NoAVL *rotacaoEsquerda(NoAVL *no);
    NoAVL *rotacaoDireita(NoAVL *no);
    NoAVL *rotacaoEsquerdaDireita(NoAVL *no);
    NoAVL *rotacaoDireitaEsquerda(NoAVL *no);
    NoAVL *inserir(NoAVL *no, int chave);
    NoAVL *remover(NoAVL *no, int chave);
    NoAVL *minimo(NoAVL *no);
    void preOrdem(NoAVL *no);
    void emOrdem(NoAVL *no);
    void posOrdem(NoAVL *no);
    void limpar(NoAVL *no);
};