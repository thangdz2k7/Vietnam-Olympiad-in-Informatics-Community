#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int subtask = opt<int>("subtask", 4);
    int t = opt<int>("t", 0); 
    int qt = opt<int>("qt", 0); 

    int max_val = 200000;
    if (subtask == 1) max_val = 500;
    if (subtask == 2) max_val = 5000;

    int n = opt<int>("n", rnd.next(max_val / 2, max_val));
    int m = opt<int>("m", rnd.next(max_val / 2, max_val));
    int q = opt<int>("q", rnd.next(max_val / 2, max_val));

    vector<int> h(m);
    if (t == 3) {
        int pool_size = rnd.next(1, min(n, 100));
        vector<int> pool;
        for (int i = 0; i < pool_size; i++) pool.push_back(rnd.next(0, n - 1));
        for (int i = 0; i < m; i++) h[i] = pool[rnd.next(0, pool_size - 1)];
    } else {
        for (int i = 0; i < m; i++) {
            if (t == 0) {
                h[i] = rnd.next(0, n - 1);
            } else if (t == 1) {
                h[i] = rnd.wnext(0, n - 1, 5); 
            } else if (t == 2) {
                h[i] = rnd.wnext(0, n - 1, -5); 
            } else if (t == 4) {
                if (rnd.next(0, 1) == 0) h[i] = rnd.next(0, min(10, n - 1));
                else h[i] = rnd.next(0, n - 1);
            }
        }
    }

    vector<int> L(q), R(q);
    if (subtask == 3) {
        int max_sum = 200000;
        vector<int> cuts;
        cuts.push_back(0);
        cuts.push_back(max_sum);
        for (int i = 0; i < q - 1; i++) cuts.push_back(rnd.next(0, max_sum));
        sort(cuts.begin(), cuts.end());
        
        for (int i = 0; i < q; i++) {
            int len = cuts[i + 1] - cuts[i];
            len = min(len, m - 1); 
            L[i] = rnd.next(0, m - 1 - len);
            R[i] = L[i] + len;
        }
    } else {
        for (int i = 0; i < q; i++) {
            if (qt == 0) {
                L[i] = rnd.next(0, m - 1);
                R[i] = rnd.next(L[i], m - 1);
            } else if (qt == 1) {
                L[i] = rnd.wnext(0, m - 1, -3); 
                R[i] = rnd.wnext(L[i], m - 1, 3);
            } else if (qt == 2) {
                L[i] = rnd.next(0, m - 1);
                int len = rnd.wnext(0, m - 1 - L[i], -5);
                R[i] = L[i] + len;
            }
        }
    }

    vector<int> P(q);
    for (int i = 0; i < q; i++) {
        if (rnd.next(0, 1) == 0 && m > 0) {
            P[i] = h[rnd.next(0, m - 1)]; 
        } else {
            P[i] = rnd.next(0, n - 1);
        }
    }

    println(n, m, q);
    println(h);
    for (int i = 0; i < q; i++) {
        println(L[i], R[i], P[i]);
    }

    return 0;
}