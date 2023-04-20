#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class NoAVL {
private:
    int chave;
    int altura;
    NoAVL *esq;
    NoAVL *dir;

public:
    NoAVL(int chave);
    ~NoAVL();
    int getChave();
    int getAltura();
    NoAVL *getEsq();
    NoAVL *getDir();
    void setChave(int chave);
    void setAltura(int altura);
    void setEsq(NoAVL *esq);
    void setDir(NoAVL *dir);
};