#include "festivallib.h"
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;

#define se second

template <class T> bool maximize(T &x, T y) {
	if (x < y) {
		x = y;
		return true;
	}
	return false;
}
template <class T> bool minimize(T &x, T y) {
    if (x > y) {
        x = y;
        return true;
    }
    return false;
}


vector<int> solveGenius(int n, int S, const vector<int>& U, const vector<int>& V) {
    vector<int> inDeg(n, 0), label(n, 0);
    vector<vector<int>> adj(n, vector<int>());

    for (int i = 0; i < U.size(); ++i) {
        adj[U[i]].emplace_back(V[i]);
        ++inDeg[V[i]];
    }

    queue<int> q;
    for (int i = 0; i < n; ++i)
    	if (inDeg[i] == 0) q.emplace(i);

    vector<int> topo;
    while (!q.empty()) {
    	int u = q.front(); q.pop();
    	topo.emplace_back(u);
    	for (auto v : adj[u])
    		if (--inDeg[v] == 0) q.emplace(v);
    }

    reverse(topo.begin(), topo.end());
    vector<int> longest(n, 0);
    for (auto &x : topo) {
        if (adj[x].size() == 0) longest[x] = 0;
        else longest[x] = 1e9;
    	for (auto v : adj[x])
    		minimize(longest[x], longest[v] + 1);
    }

    for (int i = 0; i < U.size(); ++i) ++inDeg[V[i]];

    priority_queue<pii> pq;
    for (int i = 0; i < n; ++i)
        if (inDeg[i] == 0) pq.emplace(longest[i], i);

    int phase = 0;
    while (!pq.empty()) {
        vector<int> ve;
        while (ve.size() < S && !pq.empty()) {
            int x = pq.top().se; pq.pop();
            ve.emplace_back(x);
        }

        ++phase;
        for (auto &x : ve) {
        	// cerr << x << ' ';
            label[x] = phase;
            for (auto v : adj[x])
                if (--inDeg[v] == 0) pq.emplace(longest[v], v);
        }
    }

    return label;
}

bool solveCitizen(const vector<int>& A,const vector<vector<int>>& history) {
    int cur = 1, last = -1;
    for (int i = 0; i < history.size(); ++i)
        if (!history[i].empty()) ++cur, last = i;
    int cnt = 0;
    for (auto &x : A) cnt += (x == cur);
    if (cnt == (int)history.size() - last - 1) return true;
    return false;
}