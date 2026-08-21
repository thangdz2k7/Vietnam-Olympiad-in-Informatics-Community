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

int n, k, q, timer1, timer2, ti[NM], tin[NM], tout[NM], dep[NM], a[NM], nxt[NM], up[LG][NM], f[NM];
vector<int> o, g[NM];
pair<int, int> eu[LG][2 * NM];
vector<pair<int, int>> PATHS, paths1[NM], paths2[NM];

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
    for (int i = 1; i < LG; i++)
        up[i][u] = up[i - 1][up[i - 1][u]];
    eu[0][ti[u] = ++timer1] = {dep[u], u};
    tin[u] = ++timer2;
    for (int v : g[u])
    {
        g[v].erase(find(all(g[v]), u));
        up[0][v] = u;
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

int UP(int u, int k)
{
    while (k)
    {
        int t = __lg(k);
        u = up[t][u];
        k ^= 1 << t;
    }
    return u;
}

struct ST
{
    pair<int, int> dt[4 * NM];
    multiset<pair<int, int>> s[NM];
    void build(int x = 1, int l = 1, int r = n)
    {
        if (l == r)
        {
            dt[x] = {0, 0};
            s[l].clear();
            return;
        }
        int m = l + r >> 1;
        build(x << 1, l, m);
        build(x << 1 | 1, m + 1, r);
        dt[x] = {0, 0};
    }
    void upd(const int& i, const int& t, const pair<int, int>& v, int x = 1, int l = 1, int r = n)
    {
        if (l == r)
        {
            if (t)
                s[l].insert(v);
            else
                s[l].erase(s[l].find(v));
            dt[x] = (s[l].size() ? *prev(s[l].end()) : make_pair(0, 0));
            return;
        }
        int m = l + r >> 1;
        m >= i ? upd(i, t, v, x << 1, l, m) : upd(i, t, v, x << 1 | 1, m + 1, r);
        dt[x] = max(dt[x << 1], dt[x << 1 | 1]);
    }
    pair<int, int> get(const int& l, const int& r, int x = 1, int lx = 1, int rx = n)
    {
        if (l > rx || lx > r || l > r)
            return {0, 0};
        if (lx >= l && rx <= r)
            return dt[x];
        int m = lx + rx >> 1;
        return max(get(l, r, x << 1, lx, m), get(l, r, x << 1 | 1, m + 1, rx));
    }
}st;

void calc(int u)
{
    int jump = max(st.get(1, tin[u] - 1), st.get(tout[u] + 1, n)).se;
    if (dep[jump] < dep[nxt[u]] && f[jump])
        f[u] = 1;
    for (auto t : paths1[u])
    {
        int l = t.fi, v = t.se;
        st.upd(tin[v], 1, {dep[l], l});
    }
    for (int v : g[u])
    {
        for (auto t : paths2[v])
        {
            int x = t.fi, y = t.se;
            st.upd(tin[x], 0, {dep[u], u});
            st.upd(tin[y], 1, {dep[u], u});
        }
        calc(v);
        for (auto t : paths2[v])
        {
            int x = t.fi, y = t.se;
            st.upd(tin[x], 1, {dep[u], u});
            st.upd(tin[y], 0, {dep[u], u});
        }
    }
    for (auto t : paths1[u])
    {
        int l = t.fi, v = t.se;
        st.upd(tin[v], 0, {dep[l], l});
    }
}

bool ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

void reset()
{
    st.build();
    timer1 = timer2 = 0;
    o.clear();
    PATHS.clear();
    dep[1] = f[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        a[i] = nxt[i] = f[i] = 0;
        g[i].clear();
        paths1[i].clear();
        paths2[i].clear();
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
        PATHS.push_back({u, v});
    }
    fill(bit.dt, bit.dt + n + 1, 0);
    sort(all(PATHS), [&](const auto& x, const auto& y) 
    {
        return dep[lca(x.fi, x.se)] > dep[lca(y.fi, y.se)];
    });
    int res = 0;
    for (auto t : PATHS)
    {
        int u = lca(t.fi, t.se);
        if (a[u])
            continue;
        int sum = bit.get(tin[t.fi]) + bit.get(tin[t.se]) - 2 * bit.get(tin[up[0][u]]);
        if (!sum)
        {
            a[u] = 1;
            res++;
            bit.upd(tin[u], tout[u], 1);
        }
    }
    reverse(all(o));
    for (int u : o)
        nxt[u] = (a[u] ? u : nxt[up[0][u]]);
    for (auto t : PATHS)
    {
        int u = t.fi, v = t.se, l = lca(u, v);
        int uu = nxt[u], vv = nxt[v];
        if (make_pair(dep[uu], dep[u]) < make_pair(dep[vv], dep[v]))
            swap(u, v), swap(uu, vv);
        if (dep[vv] < dep[l])
            paths1[uu].push_back({l, u});
        else if (uu == vv && uu == l)
        {
            paths1[uu].push_back({l, u});
            if (!ancestor(v, u))
                paths2[UP(v, dep[v] - dep[l] - 1)].push_back({u, v});
        }
        else if (ancestor(vv, uu))
            paths1[uu].push_back({l, u});
    }
    calc(1);
    vector<int> ans;
    for (int i = 0; i < q; i++)
    {
        int u = X[i] + 1, v = Y[i] + 1, l = lca(u, v);
        if (bit.get(tin[u]) + bit.get(tin[v]) != 2 * bit.get(tin[up[0][l]]))
            ans.push_back(res);
        else
            ans.push_back(res + !f[l]);
    }
    return ans;
}