#ifndef ARVOREAVL_H
#define ARVOREAVL_H

#include <bits/stdc++.h>
#include <iostream>

#include "NoAVL.h"

using namespace std;

class ArvoreAVL {

private:
    NoAVL *raiz; //Raiz da arvore
    NoAVL *novoNo(int valor); //Cria um novo no

    int altura(NoAVL *no); //Altura da arvore
    int fatorBalanceamento(NoAVL *no); //Fator de balanceamento

    NoAVL *rotacionarEsquerda(NoAVL *no); //Rotação simples a esquerda
    NoAVL *rotacionarDireita(NoAVL *no); //Rotação simples a direita
    NoAVL *rotacionarEsquerdaDireita(NoAVL *no); //Rotação dupla a esquerda-direita
    NoAVL *rotacionarDireitaEsquerda(NoAVL *no); //Rotação dupla a direita-esquerda
    NoAVL *inserir(NoAVL *no, int valor); //Insere um no na arvore
    NoAVL *remover(NoAVL *no, int valor); //Remove um no da arvore
    
    void imprimir(NoAVL *no);
    void deletarArvore(NoAVL *no);
};

#endif // ARVOREAVL_H