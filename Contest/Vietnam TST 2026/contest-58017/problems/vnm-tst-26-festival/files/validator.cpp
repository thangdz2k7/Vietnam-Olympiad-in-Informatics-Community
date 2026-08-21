#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
	registerValidation(argc, argv);
    ensure(!validator.group().empty());

    int subtask = validator.group().back() - '0';
    ensuref(1 <= subtask && subtask <= 4, "Invalid subtask %s", validator.group().c_str());

    int MAXN = (subtask == 1 ? 2 : 200);
    int N = inf.readInt(2, MAXN, "N"); inf.readSpace();

    int K = inf.readInt(0, N * (N - 1) / 2, "K"); inf.readSpace();

    int MAXS = (subtask == 3 ? 2 : N);
    int S = inf.readInt(1, MAXS, "S"); inf.readEoln();

    vector<int> inDeg(N, 0);
    vector<vector<int>> adj(N, vector<int>());
    vector<vector<int>> check(N, vector<int>(N, 0));

    for (int i = 0; i < K; ++i) {
    	int u = inf.readInt(0, N - 1, format("U[%d]", i)); inf.readSpace();
    	int v = inf.readInt(0, N - 1, format("V[%d]", i)); inf.readEoln();
    	ensuref(u != v, "u == v");
    	ensuref(!check[u][v], "multiple edges");
    	check[u][v] = true;
    	adj[u].emplace_back(v);
    	++inDeg[v];
    }
    
    inf.readEof();

    // DAG
    queue<int> q; int cnt = 0;
    for (int i = 0; i < N; ++i)
    	if (inDeg[i] == 0) q.emplace(i);
    while (!q.empty()) {
    	int u = q.front(); q.pop();
    	++cnt;
    	for (auto v : adj[u])
    		if (--inDeg[v] == 0) q.emplace(v);
    }

    ensuref(cnt == N, "Not a DAG");

    if (subtask == 2) {
    	for (int i = 0; i < N; ++i)
    		ensuref(inDeg[i] <= 1, "%d has more than one parent", i);
    }
	return 0;
}