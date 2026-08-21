#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);

    int max_val = 200000;

    int n = inf.readInt(1, max_val, "N");
    inf.readSpace();
    int m = inf.readInt(1, max_val, "M");
    inf.readSpace();
    int q = inf.readInt(1, max_val, "Q");
    inf.readEoln();

    for (int i = 0; i < m; i++) {
        inf.readInt(0, n - 1, "H_i");
        if (i == m - 1) inf.readEoln();
        else inf.readSpace();
    }

    long long sum_diff = 0; 
    for (int i = 0; i < q; i++) {
        int l = inf.readInt(0, m - 1, "L_i");
        inf.readSpace();
        
        int r = inf.readInt(l, m - 1, "R_i"); 
        inf.readSpace();
        
        int p = inf.readInt(0, n - 1, "P_i");
        inf.readEoln();

        sum_diff += (long long)(r - l);
    }

    inf.readEof();

    string gr = validator.group();
    
    if (gr == "1") {
        ensuref(n <= 500 && m <= 500 && q <= 500, "Subtask 1: N, M, Q must be <= 500");
    }
    if (gr == "2") {
        ensuref(n <= 5000 && m <= 5000 && q <= 5000, "Subtask 2: N, M, Q must be <= 5000");
    }
    if (gr == "3") {
        ensuref(sum_diff <= 200000LL, "Subtask 3: Sum of (R_i - L_i) must be <= 200000");
    }

    return 0;
}