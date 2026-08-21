#include "bits/stdc++.h"

using namespace std;

#ifdef duc_debug
#include "bits/debug.h"
#else
#define debug(...)
#endif

const int N = 3e6 + 6;
const int maxn = 1e5 + 5;
const int B = 350;
int n, a[maxn], q;
int p[maxn], pos[maxn];
int qu[maxn], ql[maxn], qr[maxn];
long long res[maxn];
int pl[maxn], pr[maxn];
int len;
vector<int> g[N];
long long ans[maxn];
vector<int> qe[maxn];

vector<int> stk[maxn];
vector<int> par;
vector<int> kth;
vector<pair<int, int>> prs;
vector<long long> val;
vector<int> h;
int nodes;

int bit[maxn];
void upd(int i, int v) {
  for (; i <= len; i += i & (-i)) {
    bit[i] += v;
  }
}

int get(int i) {
  int ans = 0;
  for (; i > 0; i -= i & (-i)) {
    ans += bit[i];
  }
  return ans;
}

void build_lr(int l, int r) {
  vector<int> vec;
  for (int i = l; i <= r; ++i) {
    vec.push_back(a[i]);    
  }
  sort(vec.begin(), vec.end());
  for (int i = l; i <= r; ++i) {
    p[i] = lower_bound(vec.begin(), vec.end(), a[i]) - vec.begin() + 1;
    pos[p[i]] = i;
  }
  for (int i = l; i <= r; ++i) {
    pl[i] = pr[i] = i;
  }
  set<pair<int, int>> s;
  for (int i = r; i >= l; --i) {
    if (!s.empty() and s.begin()->first < p[i]) {
      pr[i] = s.begin()->second;
    }
    s.insert(make_pair(p[i], i));
  }
  int mn = r + 1;
  for (int i = len; i >= 1; --i) {
    mn = min(mn, pos[i]);
    pl[pos[i]] = mn;
  }
}

void create(int x, int y) {
  par.push_back(-1);
  prs.emplace_back(x, y);
  val.push_back(0);
}

void calc(int l, int r, bool rv) {
  len = r - l + 1;
  build_lr(l, r);
  for (int x = r; x >= l; --x) {
    create(x, x);
    stk[x].insert(stk[x].begin(), (int)prs.size() - 1);
    for (int i = 0; i < (int)stk[x].size(); ++i) {
      int id = stk[x][i];
      int y = prs[id].second;
      int xl = pl[y], xr = pr[x];
      if (x == xl and y == xr) continue;
      if (stk[xl].empty() || p[prs[stk[xl].back()].second] > p[xr]) {
        create(xl, xr);
        stk[xl].emplace_back((int)prs.size() - 1);
      }
      par[id] = stk[xl].back();
    }
  }
  for (int i = 0; i <= len; ++i) {
    bit[i] = 0;
  }
  for (int i = l; i <= r; ++i) {
    ans[i] += (i - l);
    for (auto id : stk[i]) {
      val[id] = get(p[prs[id].second] - 1);
    }
    upd(p[i], 1);
  }
}

void dfs(int u) {
  if (par[u] != -1) {
    val[u] += val[par[u]];
  }
//  debug(u, prs[u], par[u], val[u], h[u]);
  for (auto v : g[u]) {
    dfs(v);
  }
}

long long get_path(int u, int id, int k) {
  debug(u, id, k, val[u], ans[id]);
  long long cur = val[u] + ans[id];
  --k;
  int kk = k;
  if (k < 0) return 0;
  while (k >= B) {
    k -= B;
    debug(u, kth[u]);
    u = kth[u];
    if (u < 0) break;
  }
  if (u >= 0) {
    for (int i = 0; i < k; ++i) {
//      debug(u, par[u]);
      u = par[u];
      if (u < 0) break;
    }
  }
  debug(u);
  if (u >= 0) {
    cur -= val[u];
    cur -= h[u] * (kk + 1);
  }
  return cur;
}

void solve() {
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i <= q; ++i) {
    cin >> qu[i] >> ql[i] >> qr[i];
    qe[qu[i]].push_back(i);
  }
  for (int ite = 0; ite < 2; ++ite) {
    int mx = 0;
    int lst = 0;
    for (int i = 1; i <= n; ++i) {
      mx = max(mx, a[i]);
      if (mx == i) {
        if (lst + 1 <= i) {
          calc(lst + 1, i, ite);
        }
        lst = i;
      } 
    }
    int nodes = (int)val.size();
    kth.resize(nodes, -10);
    h.resize(nodes, 0);
    for (int i = 0; i < nodes; ++i) {
      h[i] = val[i];
      if (par[i] != -1) {
        g[par[i]].emplace_back(i);
      }
    }
    for (int i = 0; i < nodes; ++i) {
      if (par[i] == -1) {
        dfs(i);
      }
    }
    vector<int> ver;
    for (int i = 0; i < (int)prs.size(); ++i) {
      if (prs[i].first == prs[i].second) {
        int xx = (ite ? n - prs[i].first + 1 : prs[i].first);
        ver.push_back(i);
      }
    }
    while (!ver.empty()) {
      auto u = ver.back();
      ver.pop_back();
      if (kth[u] != -10) continue;
      kth[u] = u;
      for (int i = 0; i < B; ++i) {
        kth[u] = par[kth[u]];   
        if (kth[u] == -1) break;     
      }
      if (kth[u] >= 0) ver.push_back(kth[u]);
    }
    for (int i = 0; i < (int)prs.size(); ++i) {
//      debug(i, prs[i], par[i], kth[i]);
      if (prs[i].first != prs[i].second) continue;
      int vcl = prs[i].first;
      if (ite) vcl = n - vcl + 1;
      for (auto id : qe[vcl]) {
        int u = qu[id], l = ql[id], r = qr[id];
        if (ite) u = n - u + 1;
        res[id] += get_path(i, u, r) - get_path(i, u, l - 1);
      }
    }
    
    reverse(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) {
      a[i] = n - a[i] + 1;
    }
    val.clear();
    prs.clear();
    par.clear();
    h.clear();
    kth.clear();
    for (int i = 0; i < nodes; ++i) {
      g[i].clear();
    }
    for (int i = 1; i <= n; ++i) {
      stk[i].clear();
      ans[i] = 0;
    }
  }
  for (int i = 1; i <= q; ++i) {
    cout << res[i] << '\n';
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  solve();

  return 0;
}
/*
7 5
1 4 6 3 2 5 7 
6 1 7
3 1 7
5 1 7
1 1 7
4 1 7

5 1
1 4 2 5 3 
4 2 3
*/
