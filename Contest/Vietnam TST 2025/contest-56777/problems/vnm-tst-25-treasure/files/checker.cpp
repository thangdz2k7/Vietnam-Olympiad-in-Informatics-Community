#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<pair<int, int>> vii;

#define fi first
#define se second

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);

    int Q = ouf.readInt(-1, (int)1e6, "number of flips");

    if (Q == -1) quit(_wa, "wrong room");
    if (Q <= 17) quit(_ok, "correct");
    
    double score = 0;
    if (Q >= 49) score = 0.25 * pow(0.9, Q - 49);
    else if (33 <= Q && Q <= 48) score = 0.25 + 0.25 * pow(0.7, Q - 33);
    else if (25 <= Q && Q <= 32) score = 0.5 + 0.2 * pow(0.6, Q - 25);
    else if (18 <= Q && Q <= 24) score = 0.7 + 0.2 * pow(0.7, Q - 18);

    quitp(score, "done");
    return 0;
}