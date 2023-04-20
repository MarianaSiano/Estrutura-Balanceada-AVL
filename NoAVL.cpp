#include <bits/stdc++.h>
#include <iostream>

#include "NoAVL.h"

using namespace std;

NoAVL::NoAVL(int chave)
{
    this->chave = chave;
    this->altura = 1;
    this->esquerda = NULL;
    this->direita = NULL;
}

NoAVL::~NoAVL()
{
    delete this->esquerda;
    delete this->direita;
}