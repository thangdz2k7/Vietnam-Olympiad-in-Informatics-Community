#include "treasurelib.h"

#include <bits/stdc++.h>
using namespace std;

#define POPCOUNT(n) (__builtin_popcountll((n)))
#define CLZ(n) (__builtin_clzll((n)))
#define CTZ(n) (__builtin_ctzll((n)))
#define LOG(n) (63 - __builtin_clzll((n)))
#define BIT(n, i) (((n) >> (i)) & 1ll)
#define MASK(i) (1ll << (i))
#define FLIP(n, i) ((n) ^ (1ll << (i)))
#define ON(n, i) ((n) | MASK(i))
#define OFF(n, i) ((n) & ~MASK(i))

#define Int __int128
#define fi first
#define se second

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef pair<long long, int> pli;
typedef pair<int, long long> pil;
typedef vector<pair<int, int>> vii;
typedef vector<pair<long long, long long>> vll;
typedef vector<pair<long long, int>> vli;
typedef vector<pair<int, long long>> vil;

template <class T1, class T2> bool maximize(T1 &x, T2 y) {
    if (x < y) {
        x = y;
        return true;
    }
    return false;
}
template <class T1, class T2> bool minimize(T1 &x, T2 y) {
    if (x > y) {
        x = y;
        return true;
    }
    return false;
}

template <class T> void remove_duplicate(vector<T> &ve) {
    sort (ve.begin(), ve.end());
    ve.resize(unique(ve.begin(), ve.end()) - ve.begin());
}

const int N = 1e5 + 5;
const int MOD = 1e9 + 7;

int n = 1, myRoom = 1;
int par[N], light[N], sz[N], dep[N], wanted[N];
bool isRightPath;
vector<int> adj[N], ke[N], see;
bitset<N> deleted, inPath, isFree;

int find(vector<int> s, int value) {
	for (int i = 1; i <= 3; ++i) if (s[i] == value) {
		return i;
	}
	return 0;
}

void explore() {
    light[myRoom] = see[0];
    int dir = find(see, 0);
    
    if (dir != 0) {
        adj[myRoom].emplace_back(++n), adj[n].emplace_back(myRoom);
        par[n] = myRoom, dep[n] = dep[myRoom] + 1; 
        see = move(dir), myRoom = n, explore();
    }
    else {
        dir = find(see, par[myRoom]);
        if (dir != 0) see = move(dir), myRoom = par[myRoom], explore();
    }
}

void reset() {
    for (int i = 1; i <= n + 1; ++i) {
        adj[i].clear(), ke[i].clear();
        dep[i] = 0, par[i] = -100;
        inPath[i] = deleted[i] = false;
    }
}

void count_child(int u, int fa) {
    sz[u] = 1;
    for (auto v : adj[u]) if (v != fa && !deleted[v]) {
        count_child(v, u);
        sz[u] += sz[v];
    }
}

void get_centroids(const int SZ, int u, int fa, vector<int> &centroids) {
    if (u == 1) isRightPath = true;
    int max_size = SZ - sz[u];
    for (auto v : adj[u]) if (v != fa && !deleted[v]) {
        get_centroids(SZ, v, u, centroids);
        maximize(max_size, sz[v]);
    }
    if (max_size <= SZ / 2) centroids.emplace_back(u);
}

void moveTo(int room) {
    if (myRoom == room) return;

    // move from myRoom to room
    while (myRoom != 1) {
        int dir = find(see, par[myRoom]);
        if (dir == 0) exit(-1);
        see = move(dir), myRoom = par[myRoom];
    }

    vector<int> path;
    while (room != 1) path.emplace_back(room), room = par[room];

    reverse(path.begin(), path.end());
    for (auto &x : path) {
        int dir = find(see, x);
        if (dir == 0) exit(-1);
        see = move(dir), myRoom = x;
    }
}

int centroid_decomp(int u) {
    vector<int> centroids; isRightPath = false;
    count_child(u, -1), get_centroids(sz[u], u, -1, centroids);

    int centroid = centroids[0];
    deleted[centroid] = true;
    if (isRightPath) inPath[centroid] = true;

    for (auto v : adj[centroid]) if (!deleted[v]) {
        ke[centroid].emplace_back(centroid_decomp(v));
    }
    return centroid;
}

void get_tour(vector<int> &tour, int u, int fa) {
    tour.emplace_back(u);
    for (auto v : adj[u]) if (v != fa) {
        get_tour(tour, v, u);
    }
    if (fa != -1) tour.emplace_back(fa);
}

void set_light(int u, int color) {
    if (!isFree[u]) {
        if (wanted[u] != color) exit(-1);
    }
    wanted[u] = color;
    isFree[u] = false;
}

void recolor() { 
    vector<int> tour; get_tour(tour, myRoom, -1);
    if (light[myRoom] != wanted[myRoom]) flip(), light[myRoom] ^= 1;

    for (int i = 1; i < tour.size(); ++i) {
        int u = tour[i];
        int dir = find(see, u);
        see = move(dir), myRoom = u;
        if (light[u] != wanted[u]) flip(), light[u] ^= 1;
    }
}

void solveAlice(vector<int> S) {
    n = myRoom = 1, see = S;
    explore();

    if (n <= 18) {
        if (n == 2) wanted[1] = 0;
        else wanted[1] = light[1];
     
        for (int i = 2; i <= n; ++i) wanted[i] = !wanted[1];
     
        recolor();
        reset();
        return;
    }

    for (int i = 1; i <= n; ++i) wanted[i] = light[i], isFree[i] = true;

    vector<int> centroids; int root = 1;
    count_child(1, -1), get_centroids(n, 1, -1, centroids);
    if (centroids.size() == 2) {
        root = n + 1;
        deleted[centroids[1]] = true;
        ke[root].emplace_back(centroid_decomp(centroids[0]));
        deleted[centroids[1]] = false;
        deleted[centroids[0]] = true;
        ke[root].emplace_back(centroid_decomp(centroids[1]));
        deleted[centroids[0]] = false;
    }
    else {
        root = centroids[0];
        deleted[root] = true;
        for (auto v : adj[root]) {
            ke[root].emplace_back(centroid_decomp(v));
        }
    }

    int u = root; vector<int> num01(2, 0), deg2;
    while (u != 1) {
        for (int i = 0; i < ke[u].size(); ++i) if (inPath[ke[u][i]]) {
            swap(ke[u][i], ke[u][0]);
            break;
        }

        if (ke[u].size() == 1) {
            set_light(ke[u][0], 1);
        }
        else if (ke[u].size() == 2) {
            deg2.emplace_back(u);
            if (light[ke[u][0]] != light[ke[u][1]]) ++num01[light[ke[u][0]]];
        }
        else if (ke[u].size() == 3) {
            if (light[ke[u][0]] == light[ke[u][1]] && light[ke[u][0]] == light[ke[u][2]]) {
                // all same color
                set_light(ke[u][0], !light[ke[u][0]]);
                set_light(ke[u][1], light[ke[u][0]]);
                set_light(ke[u][2], light[ke[u][0]]);
            }
            else {
                set_light(ke[u][0], light[ke[u][0]]);
                set_light(ke[u][1], !light[ke[u][0]]);
                set_light(ke[u][2], !light[ke[u][0]]);
            }
        }

        u = ke[u][0];
    }

    // When to stop
    if (ke[1].size() == 1) set_light(ke[1][0], 0);
    else if (ke[1].size() == 2) {
        if (light[ke[1][0]] != light[ke[1][1]]) {
            set_light(ke[1][0], 0);
            set_light(ke[1][1], 0);
        }
        else {
            set_light(ke[1][0], light[ke[1][0]]);
            set_light(ke[1][1], light[ke[1][0]]);
        }
    }
    else if (ke[1].size() == 3) {
        vector<int> cnt(2, 0);
        for (auto &x : ke[1]) ++cnt[light[x]];
        for (auto &x : ke[1]) set_light(x, cnt[0] < cnt[1]);
    }

    int Xor = 0;
    for (int i = 1; i <= n; ++i) Xor ^= wanted[i];

    for (auto &x : deg2) {
        if (light[ke[x][0]] == light[ke[x][1]]) Xor ^= 1;
    }

    int deg2_dir = Xor;
    if (num01[0] < num01[1]) deg2_dir = 1;
    if (num01[0] > num01[1]) deg2_dir = 0;

    for (auto &x : deg2) {
        assert(ke[x].size() == 2);
        for (auto v : ke[x]) {
            if (inPath[v]) set_light(v, deg2_dir);
            else set_light(v, !deg2_dir);
        }
    }

    if (Xor != deg2_dir) {
        for (int i = 1; i <= n; ++i) if (isFree[i]) {
            set_light(i, !wanted[i]);
            break;
        }
    }
    
    for (int i = 0; i < 10; ++i) flip();
    
    recolor();
    reset();
}

void solveBob(vector<int> S) {
    n = myRoom = 1, see = S;
    explore();

    if (n <= 18) {
        vector<int> cnt(2, 0), ver(2, 0);
        for (int i = 1; i <= n; ++i) {
            ++cnt[light[i]];
            ver[light[i]] = i;
        }
        if (cnt[0] == 1) moveTo(ver[0]);
        else moveTo(ver[1]);
        reset();
        return;
    }

    vector<int> centroids; int root = 1;
    count_child(1, -1), get_centroids(n, 1, -1, centroids);
    if (centroids.size() == 2) {
        root = n + 1;
        deleted[centroids[1]] = true;
        ke[root].emplace_back(centroid_decomp(centroids[0]));
        deleted[centroids[1]] = false;
        deleted[centroids[0]] = true;
        ke[root].emplace_back(centroid_decomp(centroids[1]));
        deleted[centroids[0]] = false;
    }
    else {
        root = centroids[0];
        deleted[root] = true;
        for (auto v : adj[root]) {
            ke[root].emplace_back(centroid_decomp(v));
        }
    }

    int deg2_dir = 0;
    for (int i = 1; i <= n; ++i) deg2_dir ^= light[i];

    int u = root;
    while (true) {
        if (ke[u].size() == 1) {
            if (light[ke[u][0]] == 1) u = ke[u][0];
            else break;
        }
        else {
            bool same_color = true;
            for (int i = 1; i < ke[u].size(); ++i)
                same_color &= (light[ke[u][0]] == light[ke[u][i]]);
            if (same_color) break;
            if (ke[u].size() == 2) {
                if (light[ke[u][0]] == deg2_dir) u = ke[u][0];
                else u = ke[u][1];
            }
            else {
                assert(ke[u].size() == 3);
                vector<int> cnt(2, 0), ver(2, 0);
                for (auto &x : ke[u]) ++cnt[light[x]], ver[light[x]] = x;
                if (cnt[0] < cnt[1]) u = ver[0];
                else u = ver[1];
            }
        }
    }

    moveTo(u);
    reset();
}