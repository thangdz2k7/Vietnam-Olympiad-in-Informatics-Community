#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<pair<int, int>> vii;
 
#define fi first
#define se second

 
int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);
 
    int Q = ouf.readInt(-1, (int)1e6, "number of asks");
    ouf.readEoln();
    string s = ouf.readString();
    
    if (Q < 0) {
        quitf(_wa, s.c_str());
        return 0;
    }
    
    double score = 0;
    if (Q > 276) score = 0.0;
    else if (174 <= Q && Q <= 276) score = 0.2 * pow(0.95, Q - 174);
    else if (94 <= Q && Q < 174) score = 0.2 + 0.2 * pow(0.95, Q - 94);
    else if (76 <= Q && Q < 94) score = 0.4 + 0.5 * pow(0.8, Q - 76);
    else if (66 <= Q && Q < 76) score = 0.9 + 0.1 * pow(0.8, Q - 66);
    else if (Q < 66) score = 1.0;
    
    score *= 100.0;
 
    quitp(score);
    return 0;
}
