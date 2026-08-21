#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
 
mt19937 rd(89);
 
int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    
    int subtask = atoi(argv[1]);
    int type = atoi(argv[2]);
    int n = atoi(argv[3]);
    int q = atoi(argv[4]);
 
    cout << n << ' ' << q << "\n";
 
    vector<int> p(n);
    iota(p.begin(), p.end(), 1);
 
    // permutation generation
    if (type == 1) {
        shuffle(p.begin(), p.end(), rd);
    }
 
    if (type == 2) {
        // almost increasing 
        int loops = rd() % (max(10, n / 20));
        for (int i = 0; i < loops; i++) {
            int u = rd() % n, v = rd() % n;
            swap(p[u], p[v]);
        }

    }
 
    if (type == 3) {
        // almost decreasing
        int loops = rd() % (max(10, n / 20));
        for (int i = 0; i < loops; i++) {
            int u = rd() % n, v = rd() % n;
            swap(p[u], p[v]);
        }
        reverse(p.begin(), p.end());
    }
 
    if (type == 4) {
        // long path
        p[0] = 3, p[1] = 1;
        p[n - 2] = n, p[n - 1] = n - 2;
        for (int i = 2; i < n - 2; i += 2) p[i] = i + 3;
        for (int i = 3; i < n - 2; i += 2) p[i] = i - 1;
    }
 
    for (int i = 0; i < n; i++) {
        cout << p[i] << (i + 1 < n ? ' ' : '\n');
    }
 
    // generate queries
    for (int i = 0; i < q; i++) {
 
        int l, r, u;
    
        if (subtask == 4) l = 1, r = n;
        else {
            if (subtask == 3) r = rd() % 20 + 1;
            else r = rd() % n + 1;
            l = rd() % r + 1;
        }
 
        u = rd() % n + 1;
 
        cout << u << ' ' << l << ' ' << r << "\n";
    }
 
    return 0;
}