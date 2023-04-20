#include <bits/stdc++.h>
#include <iostream>

#include "NoAVL.h"
#include "arvoreAVL.h"

using namespace std;

//Construtor
ArvoreAVL::ArvoreAVL() {
    raiz = NULL; //Inicializa a raiz como NULL
}
    
//Destrutor
ArvoreAVL::~ArvoreAVL() {
    limpar(raiz); //Limpa a arvore
}

//Altura da arvore
int ArvoreAVL::altura(NoAVL *no) {
    if (no == NULL) //Se o no for NULL
    {
        return -1; //Retorna -1
    } 

    else //Se não 
    {
        return no->getAltura(); //Retorna a altura do no
    }
}

//Fator de balanceamento
int ArvoreAVL::fatorBalanceamento(NoAVL *no) {
    return fatorBalanceamento(no->getEsq()) - fatorBalanceamento(no->getDir()); //Retorna a altura da subarvore esquerda menos a altura da subarvore direita
}

//Rotação simples a esquerda
NoAVL *ArvoreAVL::rotacaoEsquerda(NoAVL *no) {
    NoAVL *noDir = no->getDir(); //No direita recebe o no direito do no
    NoAVL *noDirEsq = noDir->getEsq(); //No direita esquerda recebe o no direito esquerdo do no direito

    noDir->setEsq(no); //No direita esquerda recebe o no
    no->setDir(noDirEsq); //No direita recebe o no direita esquerda

    no->setAltura(max(altura(no->getEsq()), altura(no->getDir())) + 1); //No altura recebe a altura maxima entre a altura da subarvore esquerda e a altura da subarvore direita mais 1
    noDir->setAltura(max(altura(noDir->getEsq()), altura(noDir->getDir())) + 1); //No direita altura recebe a altura maxima entre a altura da subarvore esquerda e a altura da subarvore direita mais 1

    return noDir; //Retorna o no direita
}

//Rotação simples a direita
NoAVL *ArvoreAVL::rotacaoDireita(NoAVL *no) {
    NoAVL *noEsq = no->getEsq(); //No esquerda recebe o no esquerdo do no
    NoAVL *noEsqDir = noEsq->getDir(); //No esquerda direita recebe o no esquerdo direito do no esquerdo

    noEsq->setDir(no); //No esquerda direita recebe o no
    no->setEsq(noEsqDir); //No esquerda recebe o no esquerda direita

    no->setAltura(max(altura(no->getEsq()), altura(no->getDir())) + 1); //No altura recebe a altura maxima entre a altura da subarvore esquerda e a altura da subarvore direita mais 1
    noEsq->setAltura(max(altura(noEsq->getEsq()), altura(noEsq->getDir())) + 1); //No esquerda altura recebe a altura maxima entre a altura da subarvore esquerda e a altura da subarvore direita mais 1

    return noEsq; //Retorna o no esquerda
}

//Rotação dupla a esquerda
NoAVL *ArvoreAVL::rotacaoEsquerdaDireita(NoAVL *no) {
    no->setEsq(rotacaoEsquerda(no->getEsq())); //No esquerda recebe a rotação a esquerda do no esquerda
    return rotacaoDireita(no); //Retorna a rotação a direita do no
}

//Rotação dupla a direita
NoAVL *ArvoreAVL::rotacaoDireitaEsquerda(NoAVL *no) {
    no->setDir(rotacaoDireita(no->getDir())); //No direita recebe a rotação a direita do no direita
    return rotacaoEsquerda(no); //Retorna a rotação a esquerda do no
}

//Inserir
NoAVL *ArvoreAVL::inserir(NoAVL *no, int chave) {
    //Se o no for NULL
    if (no == NULL) {
        return new NoAVL(chave); //Retorna um novo no
    }

    //Se a chave for menor que a chave do no
    if (chave < no->getChave()) {
        no->setEsq(inserir(no->getEsq(), chave)); //No esquerda recebe a inserção do no esquerda com a chave
    }

    //Se a chave for maior que a chave do no
    else if (chave > no->getChave()) {
        no->setDir(inserir(no->getDir(), chave)); //No direita recebe a inserção do no direita com a chave
    }

    //Senão
    else {
        return no; //Retorna o no
    }

    no->setAltura(1 + max(altura(no->getEsq()), altura(no->getDir()))); //No altura recebe 1 mais a altura maxima entre a altura da subarvore esquerda e a altura da subarvore direita

    int balanceamento = fatorBalanceamento(no); //Balanceamento recebe o fator de balanceamento do no

    //Se o balanceamento for maior que 1 e a chave for menor que a chave do no esquerda
    if (balanceamento > 1 && chave < no->getEsq()->getChave()) {
        return rotacaoDireita(no);
    }

    //Se o balanceamento for menor que -1 e a chave for maior que a chave do no direita
    if (balanceamento < -1 && chave > no->getDir()->getChave()) {
        return rotacaoEsquerda(no);
    }

    //Se o balanceamento for maior que 1 e a chave for maior que a chave do no esquerda
    if (balanceamento > 1 && chave > no->getEsq()->getChave()) {
        return rotacaoEsquerdaDireita(no);
    }

    //Se o balanceamento for menor que -1 e a chave for menor que a chave do no direita
    if (balanceamento < -1 && chave < no->getDir()->getChave()) {
        return rotacaoDireitaEsquerda(no);
    }

    return no;
}

//Remover
NoAVL *ArvoreAVL::remover(NoAVL *no, int chave)
{
    //Se o no for NULL
    if (no == NULL) {
        return no;
    }

    //Se a chave for menor que a chave do no
    if (chave < no->getChave()) {
        no->setEsq(remover(no->getEsq(), chave));
    }

    //Se a chave for maior que a chave do no
    else if (chave > no->getChave()) {
        no->setDir(remover(no->getDir(), chave));
    }

    //Senão
    else {
        if ((no->getEsq() == NULL) || (no->getDir() == NULL)) {
            NoAVL *temp = no->getEsq() ? no->getEsq() : no->getDir(); //Se o no tiver filhos

            //Se o no não tiver filhos
            if (temp == NULL) {
                temp = no;
                no = NULL;
            }

            //Senão
            else {
                *no = *temp; //No recebe o no temporário
            }

            free(temp); //Libera a memória
        }

        else {
            NoAVL *temp = minimo(no->getDir()); //No recebe o mínimo da subarvore direita

            no->setChave(temp->getChave()); //No chave recebe a chave do no temporário

            no->setDir(remover(no->getDir(), temp->getChave())); //No direita recebe a remoção do no direita com a chave do no temporário
        }
    }

    //Se o no for NULL
    if (no == NULL) {
        return no;
    }

    //Atualiza a altura do no
    no->setAltura(1 + max(altura(no->getEsq()), altura(no->getDir())));

    //Pega o fator de balanceamento do no
    int balanceamento = fatorBalanceamento(no);

    //Se o balanceamento for maior que 1 e o fator de balanceamento do no esquerda for maior ou igual a 0
    if (balanceamento > 1 && fatorBalanceamento(no->getEsq()) >= 0) {
        return rotacaoDireita(no);
    }

    //Se o balanceamento for maior que 1 e o fator de balanceamento do no esquerda for menor que 0
    if (balanceamento > 1 && fatorBalanceamento(no->getEsq()) < 0) {
        return rotacaoEsquerdaDireita(no);
    }

    //Se o balanceamento for menor que -1 e o fator de balanceamento do no direita for menor ou igual a 0
    if (balanceamento < -1 && fatorBalanceamento(no->getDir()) <= 0) {
        return rotacaoEsquerda(no);
    }

    //Se o balanceamento for menor que -1 e o fator de balanceamento do no direita for maior que 0
    if (balanceamento < -1 && fatorBalanceamento(no->getDir()) > 0) {
        return rotacaoDireitaEsquerda(no);
    }

    return no;
}

//Rotacionar para a direita
NoAVL *ArvoreAVL::minimo(NoAVL *no) {
    NoAVL *atual = no; //No atual recebe o no

    //Enquanto o no atual tiver filho esquerdo
    while (atual->getEsq() != NULL) {
        atual = atual->getEsq(); //No atual recebe o filho esquerdo do no atual
    }

    return atual;
}

//Montar em pre-ordem
void ArvoreAVL::preOrdem(NoAVL *no) {
    if (no != NULL) {
        cout << no->getChave() << " ";
        preOrdem(no->getEsq());
        preOrdem(no->getDir());
    }
}

//Montar em ordem
void ArvoreAVL::emOrdem(NoAVL *no) {
    if (no != NULL) {
        emOrdem(no->getEsq()); //Montar em ordem a subarvore esquerda
        cout << no->getChave() << " "; //Imprimir a chave do no
        emOrdem(no->getDir()); //Montar em ordem a subarvore direita
    }
}

//Montar em pós-ordem
void ArvoreAVL::posOrdem(NoAVL *no) {
    if (no != NULL) {
        posOrdem(no->getEsq()); //Montar em pós-ordem a subarvore esquerda
        posOrdem(no->getDir()); //Montar em pós-ordem a subarvore direita
        cout << no->getChave() << " "; //Imprimir a chave do no
    }
}

//Limpar
void ArvoreAVL::limpar(NoAVL *no) {
    if (no != NULL) {
        limpar(no->getEsq()); //Limpar a subarvore esquerda
        limpar(no->getDir()); //Limpar a subarvore direita
        delete no; //Deletar o no
    }
}

//Imprimir
void ArvoreAVL::imprimirAVL() {
    cout << "Pre-ordem: ";
    preOrdem(raiz);
    cout << endl;

    cout << "Em ordem: ";
    emOrdem(raiz);
    cout << endl;

    cout << "Pos-ordem: ";
    posOrdem(raiz);
    cout << endl;
}