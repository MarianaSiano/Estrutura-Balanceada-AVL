#include <bits/stdc++.h>
#include <iostream>

#include "NoAVL.h"
#include "AVL.h"

using namespace std;

AVL::AVL(NoAVL* raiz) {
    raiz = NULL;
}

AVL::~AVL() {
    limpar(raiz);
}

int AVL::altura(NoAVL *no) {
    if (no == NULL) {
        return -1;
    } 
    
    else {
        return no->getAltura();
    }
}

int AVL::fatorBalanceamento(NoAVL *no) {
    return fatorBalanceamento(no->getEsq()) - fatorBalanceamento(no->getDir());
}

NoAVL *AVL::rotacaoEsquerda(NoAVL *no) {
    NoAVL *noDir = no->getDir();
    NoAVL *noDirEsq = noDir->getEsq();

    noDir->setEsq(no);
    no->setDir(noDirEsq);

    no->setAltura(max(altura(no->getEsq()), altura(no->getDir())) + 1);
    noDir->setAltura(max(altura(noDir->getEsq()), altura(noDir->getDir())) + 1);

    return noDir;
}

NoAVL *AVL::rotacaoDireita(NoAVL *no) {
    NoAVL *noEsq = no->getEsq();
    NoAVL *noEsqDir = noEsq->getDir();

    noEsq->setDir(no);
    no->setEsq(noEsqDir);

    no->setAltura(max(altura(no->getEsq()), altura(no->getDir())) + 1);
    noEsq->setAltura(max(altura(noEsq->getEsq()), altura(noEsq->getDir())) + 1);

    return noEsq;
}

NoAVL *AVL::rotacaoEsquerdaDireita(NoAVL *no) {
    no->setEsq(rotacaoEsquerda(no->getEsq()));
    return rotacaoDireita(no);
}

NoAVL *AVL::rotacaoDireitaEsquerda(NoAVL *no) {
    no->setDir(rotacaoDireita(no->getDir()));
    return rotacaoEsquerda(no);
}