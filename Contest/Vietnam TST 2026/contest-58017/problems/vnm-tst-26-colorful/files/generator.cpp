#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

mt19937 rng;

int randInt(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int subtaskId = opt<int>("subtaskId");
    int mode = opt<int>("mode");
    ensuref(1 <= subtaskId && subtaskId <= 3, "subtaskId must be in [1, 3]");
    ensuref(1 <= mode && mode <= 2, "mode must be in [1, 2]");
    int rseed = opt<int>("seed");
    rng.seed(rseed);

    vector<pair<int,int>> tests;

    if (mode == 1) {
        // multitest, sum n <= 2e4
        int sum_n = 0;

        while (sum_n < 20000) {
            int n, k;

            if (subtaskId == 1) {
                n = randInt(3, 10);
                k = 3;
            } else if (subtaskId == 2) {
                n = randInt(3, 10);
                k = randInt(3, n);
            } else {
                n = randInt(3, 256);
                k = randInt(3, min(32, n));
            }

            if (sum_n + n > 20000) break;

            sum_n += n;
            tests.push_back({n, k});
        }

    } else {
        int sum_n = 0;
         while (sum_n < 20000) {
            int n, k;
    
            if (subtaskId == 1) {
                n = 10;
                k = 3;
            } else if (subtaskId == 2) {
                n = 10;
                k = randInt(3, n);
            } else {
                n = 256;
                k = randInt(3, min(32, n));
            }
            if (sum_n + n > 20000) break;

            sum_n += n;
            tests.push_back({n, k});
        }
    }

    cout << tests.size() << '\n';
    for (auto [n, k] : tests) {
        cout << n << " " << k << '\n';
        vector<int>a(k);
        iota(a.begin(), a.end(), 0);
        for(int i = k; i < n; i++){
            a.push_back(randInt(0, k - 1));
        }
        shuffle(a.begin(), a.end(), rng);
        for(int i = 0; i < n; i++){
            cout << a[i];
            if(i + 1 < n){
                cout << " ";
            }
        }
        cout << '\n';
    }

    return 0;
}