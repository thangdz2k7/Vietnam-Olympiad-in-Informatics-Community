#include <bits/stdc++.h>
using namespace std;

vector<int> solveGenius(int N, int S, const vector<int>& U, const vector<int>& V);
bool solveCitizen(const vector<int>& A,const vector<vector<int>>& history);

namespace LJTJRRVZRN {
	void verdict(int e, int x) {
		cout << e << ' ' << x << endl;
		exit(0);
	}
}

int main() {
	int N, K, S;
	cin >> N >> K >> S;

	vector<int> U, V;
	vector<int> inDeg(N, 0);
	vector<vector<int>> adj(N);

	for (int i = 0; i < K; ++i) {
		int u, v; cin >> u >> v;
		U.push_back(u);
		V.push_back(v);
		adj[u].push_back(v);
		++inDeg[v];
	}

	vector<int> X = solveGenius(N, S, U, V);
	if ((int)X.size() != N) LJTJRRVZRN::verdict(-1, X.size());
	for (int i = 0; i < N; ++i) {
		if (X[i] <= 0) LJTJRRVZRN::verdict(-2, i);
	}

	vector<vector<int>> history;
	vector<int> out(N, false);
	int cntOut = 0;

	for (int turn = 1; turn <= N; ++turn) {
		vector<int> currentTurn, vertex;
		for (int i = 0; i < N; ++i) {
			if (out[i]) continue;
			vector<int> A = X;
			A.erase(A.begin() + i);
			sort (A.begin(), A.end());
			bool leave = solveCitizen(A, history);
			if (leave) {
				out[i] = true;
				vertex.emplace_back(i);
				currentTurn.push_back(X[i]);
			}
		}
		if ((int)currentTurn.size() > S) LJTJRRVZRN::verdict(-4, currentTurn.size());
		for (auto x : vertex) 
			if (inDeg[x] > 0) LJTJRRVZRN::verdict(-5, x);
		for (auto x : vertex)
			for (auto v : adj[x]) --inDeg[v];
		cntOut += currentTurn.size();
		sort (currentTurn.begin(), currentTurn.end());
		history.push_back(currentTurn);
	}

	if (cntOut != N) LJTJRRVZRN::verdict(-3, cntOut);

	int P = *max_element(X.begin(), X.end());
	LJTJRRVZRN::verdict(P, 0);

	return 0;
}