#include "cpointlib.h"
#include <bits/stdc++.h>
using namespace std;

vector<int> solve() {
    vector<vector<int>> S(29);
    for (int i = 0; i < 29; i++)
        S[i].push_back(i);
    
    auto mergeP = [&](int x, int y) -> void {
        assert(!S[x].empty() && !S[y].empty());
        // x <- y
        for (int v : S[y]) S[x].push_back(v);
        S[y].clear();

        add(x << 1, y << 1, x << 1);
        add(x << 1 | 1, y << 1 | 1, x << 1 | 1);

        return;
    };

    auto calcMod = [&](int x, int y, int k) -> void {
        assert(y == 0 || y == 1);
        int idx = (x << 1) | y;
        int u = 63;
        
        sub(u, u, u);
        add(u, idx, u);

        for (int i = 0; i <= k; i++)
            half(u, u);
        for (int i = 0; i <= k; i++)
            add(u, u, u);
        
        sub(idx, u, u);
    };

    auto cp = [&](int u, int v) -> void {
        if (u == v) return;
        sub(v, v, v);
        add(u, v, v);
    };  

    auto build = [&](int u, int x, int k) -> void {
        calcMod(x, 0, k);
        cp(63, u);
        calcMod(x, 1, k);
        for (int i = 0; i <= k; i++) add(u, u, u);
        add(63, u, u);
    };

    auto qry = [&](int u, int v) -> bool {
        u += 58, v += 58;
        string s = "";
        for (int i = 0; i < 64; i++) s += '0';
        s[u] = s[v] = '1';
        return ask(s);
    };

    // 28 * 2 + 1 = 57
    // 58 59 60 61 62

    vector <int> ds(5, -1);

    for (int _ = 0; _ < 3; _++) {
        fill(ds.begin(), ds.end(), -1);
        for (int i = 0; i < 29; i++) {
            if (S[i].empty()) continue;

            int it;
            {
                for (int j = 0; j < 5; j++) if (ds[j] == -1) {
                    it = j;
                    break;
                }
            }
            ds[it] = i;
            build(58 + it, i, _);
            
            for (int j = 0; j < 5; j++)
                if (j != it && ds[j] != -1) {
                    if (qry(it, j)) {
                        mergeP(ds[it], ds[j]);
                        ds[it] = ds[j] = -1;
                        break;
                    }
                }
        }
        for (int i = 0; i < 29; i++)
            if (S[i].size() != (1 << (_ + 1))) S[i].clear();
    }

    for (int i = 0; i < 29; i++)
        if (!S[i].empty()) {
            assert(S[i].size() == 8);
            vector <int> ans;
            for (int j : S[i]) {
                ans.push_back(j);
            }
            return ans;
        }
    
    assert(false);

}   

/*
0 1
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10
10 11
11 12
12 13
13 14
14 15
15 16
16 17
17 18
18 19
19 20
20 21
21 22
22 23
23 24
24 25
25 26
26 27
27 28
28 29

*/