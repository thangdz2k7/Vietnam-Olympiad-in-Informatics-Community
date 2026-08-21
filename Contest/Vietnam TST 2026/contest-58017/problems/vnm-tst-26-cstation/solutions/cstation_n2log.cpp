#include "cstationlib.h"
#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define endl '\n'
#define setmin(x, y) x = min((x), (y))
#define setmax(x, y) x = max((x), (y))
#define all(x) x.begin(), x.end()

const int NM = 1e5 + 5;
const int LG = 18;

int n, k, q, timer1, timer2, ti[NM], tin[NM], tout[NM], dep[NM], par[NM];
vector<int> o, g[NM];
pair<int, int> eu[LG][2 * NM];
vector<pair<int, int>> paths[NM];

struct BIT
{
    int dt[NM];
    void upd(int i, int v)
    {
        for (; i < NM; i += i & -i)
            dt[i] += v;
    }
    void upd(int l, int r, int v)
    {
        upd(l, v);
        upd(r + 1, -v);
    }
    int get(int i)
    {
        int res = 0;
        for (; i; i -= i & -i)
            res += dt[i];
        return res;
    }
}bit;

void dfs(int u)
{
    eu[0][ti[u] = ++timer1] = {dep[u], u};
    tin[u] = ++timer2;
    for (int v : g[u])
        if (v != par[u])
        {
            par[v] = u;
            dep[v] = dep[u] + 1;
            dfs(v);
            eu[0][++timer1] = {dep[u], u};
        }
    tout[u] = timer2;
    o.push_back(u);
}

int lca(int u, int v)
{
    u = ti[u], v = ti[v];
    if (u > v)
        swap(u, v);
    int t = __lg(v - u + 1);
    return min(eu[t][u], eu[t][v - (1 << t) + 1]).se;
}

void reset()
{
    timer1 = timer2 = 0;
    o.clear();
    for (int i = 1; i <= n; i++)
    {
        g[i].clear();
        paths[i].clear();
    }
}

vector<int> solve(int N, int K, int Q, const vector<int>& A, const vector<int>& B, const vector<int>& U, const vector<int>& V, const vector<int>& X, const vector<int>& Y)
{
    n = N, k = K, q = Q;
    reset();
    for (int i = 0; i < n - 1; i++)
    {
        int u = A[i] + 1, v = B[i] + 1;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    for (int i = 1; (1 << i) <= timer1; i++)
        for (int j = 1; j + (1 << i) - 1 <= timer1; j++)
            eu[i][j] = min(eu[i - 1][j], eu[i - 1][j + (1 << i - 1)]); 
    for (int i = 0; i < k; i++)
    {
        int u = U[i] + 1, v = V[i] + 1;
        paths[lca(u, v)].push_back({u, v});
    }
    vector<int> ans;
    for (int i = 0; i < q; i++)
    {
        int uu = X[i] + 1, vv = Y[i] + 1, res = 0;
        paths[lca(uu, vv)].push_back({uu, vv});
        fill(bit.dt, bit.dt + n + 1, 0);
        for (int u : o)
            for (auto t : paths[u])
            {
                int sum = bit.get(tin[t.fi]) + bit.get(tin[t.se]) - 2 * bit.get(tin[par[u]]);
                if (!sum)
                {
                    res++;
                    bit.upd(tin[u], tout[u], 1);
                    break;
                }
            }
        ans.push_back(res);
        paths[lca(uu, vv)].pop_back();
    }
    return ans;
}