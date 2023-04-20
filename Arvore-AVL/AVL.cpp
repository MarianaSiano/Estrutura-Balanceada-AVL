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

NoAVL *AVL::inserir(NoAVL *no, int chave) {
    if (no == NULL) {
        return new NoAVL(chave);
    }

    if (chave < no->getChave()) {
        no->setEsq(inserir(no->getEsq(), chave));
    }

    else if (chave > no->getChave()) {
        no->setDir(inserir(no->getDir(), chave));
    }

    else {
        return no;
    }

    no->setAltura(1 + max(altura(no->getEsq()), altura(no->getDir())));

    int balanceamento = fatorBalanceamento(no);

    if (balanceamento > 1 && chave < no->getEsq()->getChave()) {
        return rotacaoDireita(no);
    }

    if (balanceamento < -1 && chave > no->getDir()->getChave()) {
        return rotacaoEsquerda(no);
    }

    if (balanceamento > 1 && chave > no->getEsq()->getChave()) {
        return rotacaoEsquerdaDireita(no);
    }

    if (balanceamento < -1 && chave < no->getDir()->getChave()) {
        return rotacaoDireitaEsquerda(no);
    }

    return no;
}

NoAVL *AVL::remover(NoAVL *no, int chave)
{
    if (no == NULL) {
        return no;
    }

    if (chave < no->getChave()) {
        no->setEsq(remover(no->getEsq(), chave));
    }

    else if (chave > no->getChave()) {
        no->setDir(remover(no->getDir(), chave));
    }

    else {
        if ((no->getEsq() == NULL) || (no->getDir() == NULL)) {
            NoAVL *temp = no->getEsq() ? no->getEsq() : no->getDir();

            if (temp == NULL) {
                temp = no;
                no = NULL;
            }

            else {
                *no = *temp;
            }

            free(temp);
        }

        else {
            NoAVL *temp = minimo(no->getDir());

            no->setChave(temp->getChave());

            no->setDir(remover(no->getDir(), temp->getChave()));
        }
    }

    if (no == NULL) {
        return no;
    }

    no->setAltura(1 + max(altura(no->getEsq()), altura(no->getDir())));

    int balanceamento = fatorBalanceamento(no);

    if (balanceamento > 1 && fatorBalanceamento(no->getEsq()) >= 0) {
        return rotacaoDireita(no);
    }

    if (balanceamento > 1 && fatorBalanceamento(no->getEsq()) < 0) {
        return rotacaoEsquerdaDireita(no);
    }

    if (balanceamento < -1 && fatorBalanceamento(no->getDir()) <= 0) {
        return rotacaoEsquerda(no);
    }

    if (balanceamento < -1 && fatorBalanceamento(no->getDir()) > 0) {
        return rotacaoDireitaEsquerda(no);
    }

    return no;
}

NoAVL *AVL::minimo(NoAVL *no) {
    NoAVL *atual = no;

    while (atual->getEsq() != NULL) {
        atual = atual->getEsq();
    }

    return atual;
}

void AVL::preOrdem(NoAVL *no) {
    if (no != NULL) {
        cout << no->getChave() << " ";
        preOrdem(no->getEsq());
        preOrdem(no->getDir());
    }
}

void AVL::emOrdem(NoAVL *no) {
    if (no != NULL) {
        emOrdem(no->getEsq());
        cout << no->getChave() << " ";
        emOrdem(no->getDir());
    }
}

void AVL::posOrdem(NoAVL *no) {
    if (no != NULL) {
        posOrdem(no->getEsq());
        posOrdem(no->getDir());
        cout << no->getChave() << " ";
    }
}

void AVL::limpar(NoAVL *no) {
    if (no != NULL) {
        limpar(no->getEsq());
        limpar(no->getDir());
        delete no;
    }
}