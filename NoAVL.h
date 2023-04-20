#ifndef NOAVL_H
#define NOAVL_H

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class NoAVL
{
public:
    int chave;
    int altura;
    NoAVL* esquerda;
    NoAVL* direita;

    NoAVL(int chave);
    ~NoAVL();
};

#endif // NOAVL_H