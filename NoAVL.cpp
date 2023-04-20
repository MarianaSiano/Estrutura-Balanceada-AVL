#include <bits/stdc++.h>
#include <iostream>

#include "NoAVL.h"

using namespace std;

NoAVL::NoAVL(int chave)
{
    this->chave = chave;
    this->altura = 0;
    this->esq = NULL;
    this->dir = NULL;
}

NoAVL::~NoAVL()
{
    delete this->esq;
    delete this->dir;
}

int NoAVL::getChave()
{
    return this->chave;
}

int NoAVL::getAltura()
{
    return this->altura;
}

NoAVL *NoAVL::getEsq()
{
    return this->esq;
}

NoAVL *NoAVL::getDir()
{
    return this->dir;
}

void NoAVL::setChave(int chave)
{
    this->chave = chave;
}

void NoAVL::setAltura(int altura)
{
    this->altura = altura;
}

void NoAVL::setEsq(NoAVL *esq)
{
    this->esq = esq;
}

void NoAVL::setDir(NoAVL *dir)
{
    this->dir = dir;
}