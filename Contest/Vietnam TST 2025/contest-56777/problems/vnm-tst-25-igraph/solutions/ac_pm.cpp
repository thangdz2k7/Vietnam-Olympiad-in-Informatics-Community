#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "C:\debug.h"
#else
#define debug(...) 42
#endif

#define N 100000
#define B 318
#define MAX 200000

int n, q, ver;
int a[N], cnt[MAX], sf_pos[N], sf_val[N], inv_at[MAX];
long long res[N], sum[MAX];
bool vis[MAX];
vector<pair<int, int>> elem[N], addAt[N], que[N];
vector<int> g[MAX];

namespace ds {
  int cnt[N], cntB[N / B + 1];
  void add(int i) {
    int block = i / B, r = min(n, (block + 1) * B);
    for (int j = i; j < r; ++j) ++cnt[j];
    for (int j = block + 1; j <= (n - 1) / B; ++j) ++cntB[j];
  }
  int qry(int i) { return i == -1 ? 0 : cnt[i] + cntB[i / B]; }
  void clear() {
    memset(cnt, 0, sizeof(cnt));
    memset(cntB, 0, sizeof(cntB));
  }
}

int add(int x, int y) {
  if (!elem[x].empty() && elem[x].back().first == y) return elem[x].back().second;
  elem[x].push_back({y, ++ver}); 
  addAt[sf_pos[x]].push_back({sf_val[y], ver});
  assert(ver < MAX);
  return ver;
}

void dfs(int id, int dep) {
  vis[id] = 1;
  cnt[dep] = inv_at[id];
  sum[dep] = sum[dep - 1] + inv_at[id];
  auto qry = [&](int k) {
    long long res = 0;
    k = min(k, dep);
    if (k == -1) res -= inv_at[id], k = 0;
    return res + sum[dep - k] + 1LL * cnt[dep - k] * (k + 1);
  };
  for (int nxt : g[id]) {
    if (nxt < 0) {
      int u = -nxt - 1;
      for (auto [k, id] : que[u]) {
        if (id > 0) res[id - 1] += qry(k);
        else res[-id - 1] -= qry(k);
      }
    } else dfs(nxt, dep + 1);
  }
}

void solve() {
  for (int i = 0; i < n; ++i) { 
    sf_pos[i] = a[i];
    sf_val[a[i]] = i; 
  }
  for (int i = n - 2; ~i; --i) {
    sf_pos[i] = min(sf_pos[i], sf_pos[i + 1]);
    sf_val[i] = min(sf_val[i], sf_val[i + 1]);
  }
  for (int i = 0; i < n; ++i) addAt[a[i]].push_back({i, -i - 1});
  for (int i = n - 1; ~i; --i) {
    for (int it = 0; it < (int) addAt[i].size(); ++it) {
      auto [j, prv] = addAt[i][it];
      int nxt = add(j, i);
      if (nxt ^ prv) g[nxt].push_back(prv);
    }
  }
  for (int i = 0; i < n; ++i) {
    for (auto [j, id] : elem[i]) inv_at[id] = ds::qry(j);
    ds::add(a[i]);
  }
  for (int i = ver; i; --i) if (!vis[i]) dfs(i, 0);
  ds::clear();
  for (int i = 0; i < n; ++i) {
    elem[i].clear();
    addAt[i].clear();
  }
  for (int i = 1; i <= ver; ++i) g[i].clear(), vis[i] = 0;
  ver = 0;
}

int main() {
  ios::sync_with_stdio(false); 
  cin.tie(nullptr);
  cin >> n >> q;
  for (int i = 0; i < n; ++i) cin >> a[i], --a[i];
  for (int i = 0; i < q; ++i) {
    int u, l, r; cin >> u >> l >> r; --u;
    if (l == 1) res[i] += n - 1;
    que[u].push_back({l - 2, i + 1});
    que[u].push_back({r - 1, -i - 1});
  }
  solve();
  reverse(a, a + n);
  for (int i = 0; i < n; ++i) a[i] = n - 1 - a[i];
  reverse(que, que + n);
  solve();
  for (int i = 0; i < q; ++i) cout << res[i] << "\n";
}