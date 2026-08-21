#include "festivallib.h"
#include <bits/stdc++.h>
using namespace std;

vector<int> solveGenius(int n, int S, const vector<int>& U, const vector<int>& V) {
    vector<int> label(n, 0);
    if (U.empty()) {
        if (S == 1) label[0] = 1, label[1] = 2;
        else label[0] = label[1] = 1;
    }
    else {
        label[U[0]] = 2, label[V[0]] = 1;
    }
    return label;
}

bool solveCitizen(const vector<int>& A,const vector<vector<int>>& history) {
    if (A[0] == 1) return true;
    if (!history.empty()) return true;
    return false;
}