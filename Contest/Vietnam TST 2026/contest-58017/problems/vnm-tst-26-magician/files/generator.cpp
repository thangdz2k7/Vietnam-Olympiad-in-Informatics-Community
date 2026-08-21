#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

mt19937 rng;

int randInt(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

// sub1: chain
vector<vector<int>> gen_chain(int n) {
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
        g[i].push_back(i + 1);
    }
    return g;
}

// sub2: build theo level
vector<vector<int>> gen_tree(int n) {
    while (true) {
        vector<int> cnt;
        int sum = 0;

        // root
        cnt.push_back(1);
        sum = 1;

        int maxDepth = randInt(0, 7);

        for (int i = 1; i <= maxDepth; i++) {
            int x = randInt(1, 8);
            if (sum + x > n) x = n - sum;
            if (x <= 0) break;

            cnt.push_back(x);
            sum += x;
            if (sum == n) break;
        }

        if (sum != n) continue;

        vector<vector<int>> g(n);
        vector<vector<int>> level;

        int cur = 0;
        for (int c : cnt) {
            vector<int> nodes;
            for (int i = 0; i < c; i++) {
                nodes.push_back(cur++);
            }
            level.push_back(nodes);
        }

        for (int d = 1; d < (int)level.size(); d++) {
            for (int u : level[d]) {
                int par = level[d - 1][randInt(0, (int)level[d - 1].size() - 1)];
                g[par].push_back(u);
            }
        }

        return g;
    }
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int subtaskId = opt<int>("subtaskId");
    int mode = opt<int>("mode");
    int seed = opt<int>("seed");

    ensuref(1 <= subtaskId && subtaskId <= 2, "subtaskId must be in [1, 2]");
    ensuref(1 <= mode && mode <= 2, "mode must be in [1, 2]");

    rng.seed(seed);

    vector<int> tests;

    int T=100;

    for (int i = 0; i < T; i++) {
        int n;
        if (subtaskId == 1) {
            n = (mode == 1 ? randInt(1, 9) : 9);
        } else {
            n = (mode == 1 ? randInt(1, 32) : 32);
        }
        tests.push_back(n);
    }

    cout << tests.size() << '\n';

    for (int n : tests) {
        cout << n << '\n';

        vector<vector<int>> g;

        if (subtaskId == 1) g = gen_chain(n);
        else g = gen_tree(n);

        vector<int> p(n);
        iota(p.begin(), p.end(), 0);
        shuffle(p.begin(), p.end(), rng);

        vector<vector<int>> newg(n);
        for (int i = 0; i < n; i++) {
            for (int v : g[i]) {
                newg[p[i]].push_back(p[v]);
            }
        }

        for (int i = 0; i < n; i++) {
            cout << newg[i].size();
            if (!newg[i].empty()) cout << ' ';
            for (int j = 0; j < (int)newg[i].size(); j++) {
                cout << newg[i][j];
                if (j + 1 < (int)newg[i].size()) cout << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}