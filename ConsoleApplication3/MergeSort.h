#pragma once
#include "Merge.h"

void mergeSort(vector<Registro*>& r, int n) {
    if (n > 1) {
        int mt = n / 2;
        vector<Registro*> A1(r.begin(), r.begin() + mt);
        vector<Registro*> A2(r.begin() + mt, r.end());
        mergeSort(A1, mt);
        mergeSort(A2, n - mt);
        Merge(A1, A2, r);
    }
}
