#include "testlib.h"
#include<bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int t = inf.readInt(1, 20000, "_t");
    inf.readEoln();
    long long sum_n = 0;

    for (int tc = 1; tc <= t; tc++) {
        int n = inf.readInt(3, 256, "n");
        inf.readSpace();
        int k = inf.readInt(3, 32, "k");
        ensuref(k <= n, "k must be <= n");
        inf.readEoln();
        sum_n += n;
        ensuref(sum_n <= 20000, "sum of all n exceeds 2e4");
        vector<bool>vis(k, false);
        for (int i = 0; i < n; i++) {
            int x = inf.readInt(0, k - 1, "a_i");
            if(i + 1 < n){
                inf.readSpace();
            }
            vis[x] = true;
        }
        ensuref(find(vis.begin(), vis.end(), false) == vis.end(), "a must contains all colors");
        inf.readEoln();
    }
    inf.readEof();
}