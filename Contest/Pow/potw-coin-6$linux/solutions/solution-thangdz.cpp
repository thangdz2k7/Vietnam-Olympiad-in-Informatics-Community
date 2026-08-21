#include <bits/stdc++.h>
#define ii pair <int, int>
#define F first
#define S second
#define ll long long
#define lb long double
#define pb push_back
#define vi vector <int>
#define vll vector <ll>
#define Bit(x, i) ((x) >> (i) & 1)
#define Mask(i) (1ll << (i))
#define All(v) (v).begin(), (v).end()

using namespace std;

void maxzi(auto &a, auto b){
    a = max(a, b);
}

void minzi(auto &a, auto b){
    a = min(a, b);
}

const int N = 2e5 + 5;
const int mod = 1e9 + 7;
const int LG = 20;

void add(auto &a, auto b){
    a += b;
    if (a >= mod) a -= mod;
    if (a < 0) a += mod;
}

auto Pow(auto a, auto b){
    if (b == 0) return 1;
    if (b % 2) return 1ll * a * Pow(a, b - 1) % mod;
    auto c = Pow(a, b / 2);
    return 1ll * c * c % mod;
}

// * end

int n, m, pos[N], cnt = 0, a[N], deg[N];
int x[4 * N], y[4 * N];
vi adj[N];

void topo_sort(){
    queue <int> qu;
    for (int i = 1; i <= n; ++ i){
        if (!deg[i]){
            qu.push(i);
        }
    }
    while (!qu.empty()){
        int u = qu.front();
        qu.pop();
        ++ cnt;
        a[cnt] = u;
        pos[u] = cnt;
        for (int v : adj[u]){
            -- deg[v];
            if (!deg[v]) qu.push(v);
        }
    }
}

struct Node{
    int Min = 0, lz = 0, pos = 0;

    Node(){}

    Node(int val, int l){
        lz = 0;
        Min = val;
        pos = l;
    }

    void add(int val){
        lz += val;
        Min += val;
    }

    void mer(Node a, Node b){
        if (a.Min < b.Min) pos = a.pos;
        else pos = b.pos;
        Min = min(a.Min, b.Min) + lz;
    }
};

struct Segtree{
    vector <Node> it;

    void build(int s, int l, int r){
        if (l == r){
            it[s] = Node(n - 1, l);
            return;
        }

        int mid = l + r >> 1;
        build(2 * s, l, mid);
        build(2 * s + 1, mid + 1, r);
        it[s].mer(it[2 * s], it[2 * s + 1]);
    }

    Segtree(int n){
        it.resize(4 * n + 3);
        build(1, 1, n);
    }

    void upd(int s, int l, int r, int u, int v, ll val){
        if (u <= l && r <= v){
            it[s].add(val);
            return;
        }

        int mid = l + r >> 1;
        if (mid >= u) upd(2 * s, l, mid, u, v, val);
        if (mid + 1 <= v) upd(2 * s + 1, mid + 1, r, u, v, val);
        it[s].mer(it[2 * s], it[2 * s + 1]);
    }

    void del(int s, int l, int r, int u){
        if (l == r){
            it[s] = Node(mod, l);
            return;
        }

        int mid = l + r >> 1;
        if (mid >= u) del(2 * s, l, mid, u);
        else del(2 * s + 1, mid + 1, r, u);
        it[s].mer(it[2 * s], it[2 * s + 1]);
    }


};

int lastl[N], lastr[N];

void solve(){
    cin >> n >> m;
    for (int i = 1; i <= m; ++ i){
        cin >> x[i] >> y[i];
        adj[x[i]].pb(y[i]);
        deg[y[i]] ++;
    }
    topo_sort();
    Segtree seg(n);
    vi ans(n + 1, -1);
    for (int i = 1; i <= n; ++ i) lastr[i] = n + 1;
    for (int i = 1; i <= m; ++ i){
        int u = pos[x[i]];
        int v = pos[y[i]];
        if (lastr[u] > v) {seg.upd(1, 1, n, v, lastr[u] - 1, -1); lastr[u] = v;}
        if (lastl[v] < u) {seg.upd(1, 1, n, lastl[v] + 1, u, -1); lastl[v] = u;}
        while (!seg.it[1].Min){
            int k = seg.it[1].pos;
            ans[a[k]] = i;
            seg.del(1, 1, n, k);
        }
    }
    for (int i = 1; i <= n; ++ i) cout << ans[i] << ' ';
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t --) solve();

    return 0;
}