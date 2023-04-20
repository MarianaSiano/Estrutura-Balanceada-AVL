#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class NoAVL {
private:
    int chave; //chave do nó
    int altura; //altura do nó
    NoAVL *esq; //ponteiro para o filho esquerdo
    NoAVL *dir; //ponteiro para o filho direito

public:
    NoAVL(int chave); //construtor
    ~NoAVL(); //destrutor

    int getChave(); //retorna a chave do nó
    int getAltura(); //retorna a altura do nó

    NoAVL *getEsq(); //retorna o filho esquerdo
    NoAVL *getDir(); //retorna o filho direito
    
    void setChave(int chave); //altera a chave do nó
    void setAltura(int altura); //altera a altura do nó
    void setEsq(NoAVL *esq); //altera o filho esquerdo
    void setDir(NoAVL *dir); //altera o filho direito
};