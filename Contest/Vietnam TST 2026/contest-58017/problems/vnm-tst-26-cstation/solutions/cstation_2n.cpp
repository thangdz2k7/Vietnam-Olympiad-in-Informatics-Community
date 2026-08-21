#include "cstationlib.h"
#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define endl '\n'
#define setmin(x, y) x = min((x), (y))
#define setmax(x, y) x = max((x), (y))
#define all(x) x.begin(), x.end()

const int NM = 2e5 + 5;

int n, k, q, dep[NM], par[NM], a[NM];
vector<int> g[NM];
vector<pair<int, int>> paths;

void dfs(int u)
{
    for (int v : g[u])
        if (v != par[u])
        {
            par[v] = u;
            dep[v] = dep[u] + 1;
            dfs(v);
        }
}

vector<int> solve(int N, int K, int Q, const vector<int>& A, const vector<int>& B, const vector<int>& U, const vector<int>& V, const vector<int>& X, const vector<int>& Y)
{
    n = N, k = K, q = Q;
    for (int i = 1; i <= n; i++)
    {
        g[i].clear();
        paths.clear();
    }
    for (int i = 0; i < n - 1; i++)
    {
        int u = A[i] + 1, v = B[i] + 1;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    for (int i = 0; i < k; i++)
    {
        int u = U[i] + 1, v = V[i] + 1;
        paths.push_back({u, v});
    }
    vector<int> ans;
    for (int i = 0; i < q; i++)
    {
        int uu = X[i] + 1, vv = Y[i] + 1, res = n;
        paths.push_back({uu, vv});
        for (int msk = 0; msk < (1 << n); msk++)
        {
            for (int j = 0; j < n; j++)
                a[j + 1] = msk >> j & 1;
            bool die = 0;
            for (auto t : paths)
            {
                int u = t.fi, v = t.se;
                bool ok = a[u] | a[v];
                while (u != v)
                {
                    if (dep[u] < dep[v])
                        swap(u, v);
                    u = par[u];
                    ok |= a[u];
                }
                if (!ok)
                {
                    die = 1;
                    break;
                }
            }
            if (!die)
                setmin(res, __builtin_popcount(msk));
        }
        ans.push_back(res);
        paths.pop_back();
    }
    return ans;
}