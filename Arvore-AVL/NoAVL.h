#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class NoAVL {
private:
    int chave;
    int altura;
    NoAVL *esq;
    NoAVL *dir;
};