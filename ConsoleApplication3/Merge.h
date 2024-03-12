#pragma once
#include"Registro.h"
#include<vector>

void Merge(vector<Registro*>& r1, vector<Registro*>& r2, vector<Registro*>& r) {
    int i = 0, j = 0, k = 0;
    int mt = r1.size();
    while (i < mt && j < r2.size()) {
        if (r1[i]->getprecio() < r2[j]->getprecio()) {
            r[k] = r1[i];
            i++;
            k++;
        }
        else {
            r[k] = r2[j];
            j++;
            k++;
        }
    }
    while (i < mt) {
        r[k] = r1[i];
        i++;
        k++;
    }
    while (j < r2.size()) {
        r[k] = r2[j];
        j++;
        k++;
    }
}