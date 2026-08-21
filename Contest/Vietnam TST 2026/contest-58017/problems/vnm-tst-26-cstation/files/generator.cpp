#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define all(x) x.begin(), x.end()

const int NM = 1e5 + 5;

int sumN[] = {0, 500, 3000, 200000, 200000}, sub, a[NM], cnt[NM];
vector<int> g[NM], s[NM];
vector<pair<int, int>> queries, paths;
bool TEST = 0;

int rand(int u)
{
	return s[u][rnd.next(0, (int)s[u].size() - 1)];
}

void dfs(int u, int p = 0)
{
	s[u].clear();
	s[u].push_back(u);
	vector<int> V(1, u);
	for (int v : g[u])
	{
		g[v].erase(find(all(g[v]), u));
		dfs(v);
		if (s[v].size())
			V.push_back(v);
	}
	while (cnt[u]--)
	{
		int x = rnd.next(0, (int)V.size() - 1), y = rnd.next(0, (int)V.size() - 1);
		while (x && x == y)
			y = rnd.next(0, (int)V.size() - 1);
		queries.push_back({rand(V[x]), rand(V[y])});
	}
	if (a[u])
	{
		int x = rnd.next(0, (int)V.size() - 1), y = rnd.next(0, (int)V.size() - 1);
		while (x && x == y)
			y = rnd.next(0, (int)V.size() - 1);
		paths.push_back({rand(V[x]), rand(V[y])});
		s[u].clear();
	}
	else
	{
		sort(all(V), [&](const int& x, const int& y) {return s[x].size() > s[y].size();});
		for (int i = 1; i < V.size(); i++)
			for (int t : s[V[i]])
				s[V[0]].push_back(t);
		swap(s[u], s[V[0]]);
	}
}

int main(int argc, char* argv[])
{
	// if (fopen("in.txt", "w"))
	// 	freopen("in.txt", "w", stdout);
	registerGen(argc, argv, 1);

	int sub = opt<int>("sub");
	int MAX = opt<int>("max");

	int T = (sub ? 5 : 50);
	vector<int> Ns(T, sub ? 1 : 14);
	for (int i = T; i < sumN[sub]; i++)
	{
		int pos = rnd.next(0, T - 1);
		while (Ns[pos] == 1e5)
			pos = rnd.next(0, T - 1);
		Ns[pos]++;
	}
	if (MAX && sub)
	{
		T = (sub < 3 ? 1 : 2);
		Ns.assign(T, min(sumN[sub], 100000));
	}
	cout << T << endl;
	for (int N : Ns)
	{
		queries.clear(); paths.clear();
		for (int i = 0; i < N; i++)
			a[i] = cnt[i] = 0, g[i].clear();
		int K = rnd.next(N / 2, N), Q = rnd.next(99 * N / 100, N);
		cout << N << ' ' << K << ' ' << Q << endl;

		// Generate tree using prufer code
		vector<pair<int, int>> edges;
		if (sub != 3)
		{
			vector<int> prufer(N - 2);
			vector<int> degree(N + 1, 1);
			for (int& x : prufer)
			{
				x = rnd.next(0, N - 1);
				degree[x]++;
			}
			set<int> leaves;
			for (int i = 0; i < N; i++)
				if (degree[i] == 1)
					leaves.insert(i);
			for (int x : prufer)
			{
				int leaf = *leaves.begin();
				leaves.erase(leaves.begin());

				edges.push_back({leaf, x});

				degree[leaf]--;
				degree[x]--;

				if (degree[x] == 1)
					leaves.insert(x);
			}
			edges.push_back({*leaves.begin(), *prev(leaves.end())});
		}
		else
		{
			// Chain subtask
			for (int i = 0; i < N - 1; i++)
				edges.push_back({i, i + 1});
		}
		for (auto t : edges)
		{
			cout << t.fi << ' ' << t.se << endl;
			g[t.fi].push_back(t.se);
			g[t.se].push_back(t.fi);
		}

		// Fix the answer and choose the lca of nodes that will be used
		int S = rnd.next(N / 4, min(K, 3 * N / 4));
		if (TEST)
			cout << "S " << S << endl;
		vector<int> perm(N);
		iota(all(perm), 0);
		shuffle(all(perm));
		for (int i = 0; i < S; i++)
			a[i] = 1;

		// Choose the lca of queries
		for (int i = 1; i <= Q / 2; i++)
			queries.push_back({rnd.next(0, N - 1), rnd.next(0, N - 1)});
		for (int i = 1; i <= Q - Q / 2; i++)
		{
			int t = rnd.next(0, N - 1);
			cnt[t]++;
		}

		// Do it
		dfs(0);

		while (paths.size() < K)
			paths.push_back({perm[0], perm[0]});
		for (auto t : paths)
			cout << t.fi << ' ' << t.se << endl;
		for (auto t : queries)
			cout << t.fi << ' ' << t.se << endl;
	}
}