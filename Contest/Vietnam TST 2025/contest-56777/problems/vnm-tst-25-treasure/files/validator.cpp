#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> lab;

    DSU(int n = 0) {
        lab.assign(n + 1, -1);
    }

    int find_set(int p) {
        return lab[p] < 0 ? p : lab[p] = find_set(lab[p]);
    }

    bool join(int u, int v) {
        u = find_set(u), v = find_set(v);
        if (u != v) {
            if (lab[u] > lab[v]) swap(u, v);
            lab[u] += lab[v], lab[v] = u;
            return true;
        }
        return false;
    }
};

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    ensure(!validator.group().empty());

    int subtask = validator.group().back() - '0';
    ensuref(1 <= subtask && subtask <= 3, "Invalid subtask %s", validator.group().c_str());

    int MAX_N = (int)1e5;
    if (subtask == 1) MAX_N = 18;

    int n = inf.readInt(1, MAX_N, "n"); inf.readSpace();
    int adaptive = inf.readInt(0, 1, "adaptive"); inf.readEoln();

    vector<int> state = inf.readInts(n, 0, 1, "state");
    inf.readEoln();

    DSU dsu(n); vector<pair<int, int>> edges;
    for (int i = 1; i < n; ++i) {
        int u = inf.readInt(1, n, "u"); inf.readSpace();
        int v = inf.readInt(1, n, "v"); inf.readEoln();
        ensuref(u != v, "u == v");
        ensuref(dsu.join(u, v), "Not a tree");
        edges.emplace_back(u, v);
    }

    vector<int> deg(n + 1, 0);
    for (auto it : edges) ++deg[it.first], ++deg[it.second];

    for (int i = 1; i <= n; ++i) {
        if (subtask == 2) ensuref(deg[i] <= 2, "Not a line");
        else ensuref(deg[i] <= 3, "degree[%d] > 3", i);
    }

    int Alice = inf.readInt(1, n, "Alice"); inf.readSpace();
    int Bob = inf.readInt(1, n, "Bob"); inf.readEoln();

    inf.readEof();
    return 0;
}