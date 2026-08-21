#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int _t = inf.readInt(1, 20, "_t");
    inf.readSpace();
    int subtaskId = inf.readInt(1, 8, "subtaskId");
    inf.readSpace();
    int mode = inf.readInt(1, 6, "mode");
    inf.readEoln();

    for (int tc = 1; tc <= _t; ++tc) {
        int n = inf.readInt(4, 13, "n");
        inf.readSpace();
        int l = inf.readInt(1, n, "l");
        inf.readSpace();
        int r = inf.readInt(1, n, "r");
        inf.readEoln();

        ensuref(l <= r, "must have l <= r");

        if (subtaskId == 1) ensuref(n == 4,  "Subtask 1 requires n = 4");
        if (subtaskId == 2) ensuref(n <= 5,  "Subtask 2 requires n <= 5");
        if (subtaskId == 3) ensuref(n <= 6,  "Subtask 3 requires n <= 6");
        if (subtaskId == 4) ensuref(n <= 7,  "Subtask 4 requires n <= 7");
        if (subtaskId == 5) ensuref(n <= 8,  "Subtask 5 requires n <= 8");
        if (subtaskId == 6) ensuref(n <= 9,  "Subtask 6 requires n <= 9");
        if (subtaskId == 7) ensuref(n <= 10, "Subtask 7 requires n <= 10");
        
        ensuref(mode == 6 || (n * (n + 1) / 2 + 19) / 20 >= mode, "Mode should be 6 or between [1, (number of possible pairs of (l, r)) / 20]");
    }

    inf.readEof();
    return 0;
}