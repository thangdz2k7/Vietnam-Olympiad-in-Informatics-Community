#include "testlib.h"

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);

    int M = ouf.readInt(-1, 88, "Max value of M");

    if (M == -1) quit(_wa, "wrong answer");
    if (M <= 56) quit(_ok, "correct");
    
    int score = 0;
    if (M == 57) score = 80;
    else score = 176 - M * 2;

    quitp(score, "done");
    return 0;
}