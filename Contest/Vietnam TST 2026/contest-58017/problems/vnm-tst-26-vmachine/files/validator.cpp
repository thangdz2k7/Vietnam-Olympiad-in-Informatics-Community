#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int T = inf.readInt(1, 50, "T");
    inf.readEoln();

    for (int tc = 1; tc <= T; ++tc) {
        setTestCase(tc);

        int N = inf.readInt(1, 200, "N");
        inf.readEoln();

        vector<int> indeg(N + 1, 0);
        vector<vector<int>> g(N + 1);
        set<pair<int, int>> seen;

        for (int i = 1; i <= N - 1; ++i) {
            int u = inf.readInt(1, N, format("u[%d]", i).c_str());
            inf.readSpace();
            int v = inf.readInt(1, N, format("v[%d]", i).c_str());
            inf.readEoln();

            ensuref(u != v, "self-loop at edge %d", i);
            ensuref(seen.insert({u, v}).second,
                    "duplicate edge (%d, %d)", u, v);

            ++indeg[v];
            ensuref(indeg[v] <= 1,
                    "vertex %d has indegree > 1", v);

            g[u].push_back(v);
        }

        vector<int> roots;
        for (int v = 1; v <= N; ++v) {
            if (indeg[v] == 0) roots.push_back(v);
        }

        ensuref((int)roots.size() == 1,
                "there must be exactly one root, found %d",
                (int)roots.size());

        int root = roots[0];

        vector<int> vis(N + 1, 0);
        queue<int> q;
        q.push(root);
        vis[root] = 1;

        int cnt = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            ++cnt;

            for (int v : g[u]) {
                ensuref(!vis[v],
                        "graph is not a rooted tree (cycle or repeated reach to %d)",
                        v);
                vis[v] = 1;
                q.push(v);
            }
        }

        ensuref(cnt == N, "graph is not connected");
    }

    inf.readEof();
}