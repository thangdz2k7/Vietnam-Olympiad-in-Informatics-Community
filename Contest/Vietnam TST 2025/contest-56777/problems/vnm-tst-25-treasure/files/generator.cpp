#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<pair<int, int>> vii;

#define fi first
#define se second

class TreeGenerator {
#define FOR(i, a, b) for (int i = (a), lim = (b); i <= lim; ++i)

private:
    vector<int> lab, par, deg;
    vector<pair<int, int>> e;
    int numNode;
 
public:
    TreeGenerator(int n = 0) {
        numNode = n; e.clear();
        lab.assign(numNode + 7, 0);
        par.assign(numNode + 7, 0);
        deg.assign(numNode + 7, 0);
    }

    void addEdge(int u, int v) {
        ++deg[u], ++deg[v];
        if (u > v) swap(u, v);
        e.emplace_back(u, v);
    }

    void dnc(int l, int r) {
        ensure(l <= r);
        if (l == r) return;
        if (l + 1 == r) {
            addEdge(l, r);
            return;
        }

        int len = r - l + 1;
        if (len & 1) {
            dnc(l, l + len / 2 - 1);
            dnc(l + len / 2, r - 1);
            vector<int> veL, veR;
            for (int i = l; i < l + len / 2; ++i)
                if (deg[i] < 3) veL.emplace_back(i);
            for (int i = l + len / 2; i < r; ++i)
                if (deg[i] < 3) veR.emplace_back(i);
            ensure(!veL.empty() && !veR.empty());
            int u = rnd.any(veL);
            int v = rnd.any(veR);
            addEdge(u, r);
            addEdge(v, r);
        }
        else {
            if (rnd.next(2)) {
                dnc(l, l + len / 2 - 1);
                dnc(l + len / 2, r);
                vector<int> veL, veR;
                for (int i = l; i < l + len / 2; ++i)
                    if (deg[i] < 3) veL.emplace_back(i);
                for (int i = l + len / 2; i <= r; ++i)
                    if (deg[i] < 3) veR.emplace_back(i);
                ensure(!veL.empty() && !veR.empty());
                int u = rnd.any(veL);
                int v = rnd.any(veR);
                addEdge(u, v);
            }
            else {
                addEdge(r - 1, r);
                dnc(l, r - 1);
            }
        }
    }
 
    vector<int> genTreeAsParent(string type) {
        if (type == "full_binary") {
            FOR(i, 2, numNode) par[i] = i / 2;
            return par;
        }
 
        if (type == "line") {
            FOR(i, 2, numNode) par[i] = i - 1;
            return par;
        }
 
        if (type == "random") {
            vector<int> parents = {1}, deg(numNode + 1, 0);
            FOR(i, 2, numNode) {
                int p = rnd.next(parents.size());
                par[i] = parents[p];
                ++deg[par[i]], ++deg[i];
                if (deg[par[i]] == 3) {
                    swap(parents[p], parents.back());
                    parents.pop_back();
                }
                parents.emplace_back(i);
            }
            return par;
        }

        if (type == "binary") { // remy's algorithms
            vector<int> parents(2 * numNode + 7);
            int L = numNode + 1, R = numNode + 1;
            FOR(i, 1, numNode) {
                int p = rnd.next(L, R);
                int u = --L, v = ++R;
                parents[u] = parents[p];
                parents[v] = u;
                parents[p] = u;
            }
            for (int i = 1; i <= numNode; ++i) par[i] = parents[i];
            return par;
        }

        if (type == "recur") {
            dnc(1, numNode);
            return par;
        }      
 
        quitf(_fail, "unknown tree type %s", type.c_str());
    }
 
    vector<pair<int, int>> genTreeAsEdge(string type) {
        genTreeAsParent(type);
        if (type != "binary" && type != "recur") {            
            FOR(i, 2, numNode) ensure(1 <= par[i] && par[i] < i);
        }
        FOR(i, 0, numNode) lab[i] = i;
        shuffle(lab.begin() + 1, lab.begin() + numNode + 1);
 
        vector<pair<int, int>> edges;
        if (type == "recur") {
            ensure((int)e.size() + 1 == numNode);
            for (auto it : e) edges.emplace_back(lab[it.fi], lab[it.se]);
        }
        else {
            FOR(i, 1, numNode)
                if (par[i] != 0) edges.push_back(make_pair(lab[i], lab[par[i]]));
        }
        for (auto it : edges) if (rnd.next(2)) swap(it.fi, it.se);
        shuffle(edges.begin(), edges.end());
        // cerr << edges.size() << '\n';
        return edges;
    }
};

const int N = 1e5 + 5;
bool isRightPath;
int sz[N], Alice, Bob;
vector<int> adj[N], ke[N];
bitset<N> deleted, inPath;

bool maximize(int &x, int y) {
    if (x < y) {
        x = y;
        return true;
    }
    return false;
}

void count_child(int u, int fa) {
    sz[u] = 1;
    for (auto v : adj[u]) if (v != fa && !deleted[v]) {
        count_child(v, u);
        sz[u] += sz[v];
    }
}

void get_centroids(const int SZ, int u, int fa, vector<int> &centroids) {
    if (u == Alice) isRightPath = true;
    int max_size = SZ - sz[u];
    for (auto v : adj[u]) if (v != fa && !deleted[v]) {
        get_centroids(SZ, v, u, centroids);
        maximize(max_size, sz[v]);
    }
    if (max_size <= SZ / 2) centroids.emplace_back(u);
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

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    prepareOpts(argc, argv);

    int testId = opt<int>("testId");
    int subtask = opt<int>("subtask");
    string type = opt<string>("tree");
    string light = opt<string>("light");
    int flipped = opt<int>("flipped");
    int adaptive = opt<int>("adaptive");
    double RATE_N = opt<double>("RATE_N");
    double RATE_A = opt<double>("RATE_A");
    double RATE_B = opt<double>("RATE_B");

    int MAX_N = (int)1e5;
    if (subtask == 1) MAX_N = 18;

    int n = MAX_N * RATE_N;

    vector<int> state(n + 1);
    if (light == "on") {
        for (int i = 1; i <= n; ++i) state[i] = 1;
    }
    else if (light == "off") {
        for (int i = 1; i <= n; ++i) state[i] = 0;
    }
    else if (light == "random") {
        for (int i = 1; i <= n; ++i) state[i] = rnd.next(2);
    }

    TreeGenerator tree(n);
    vector<pair<int, int>> edges = tree.genTreeAsEdge(type);

    Alice = RATE_A * n;
    Bob   = RATE_B * n;

    if (light == "hard") {
        for (int i = 1; i <= n; ++i) state[i] = rnd.next(2);

        for (auto it : edges) {
            adj[it.fi].emplace_back(it.se);
            adj[it.se].emplace_back(it.fi);
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

        int u = root, pre = 1, depth = 0;
        int dir1 = rnd.next(2);
        int dir2 = rnd.next(3);
        int dir_centroid = rnd.next(2);

        vector<int> cnt(2, 0);
        while (!ke[u].empty()) {
            for (int i = 0; i < ke[u].size(); ++i) if (inPath[ke[u][i]]) {
                swap(ke[u][i], ke[u][0]);
                break;
            }

            if (centroids.size() == 2 && u == root) {
                state[ke[u][0]] = dir_centroid;
                state[ke[u][1]] = !dir_centroid;
                u = ke[u][0];
                continue;
            }

            if (ke[u].size() == 1) state[ke[u][0]] = dir1;
            else if (ke[u].size() == 2) {
                if (dir2 == 2) state[ke[u][0]] = state[ke[u][1]] = rnd.next(2);
                else state[ke[u][0]] = dir2, state[ke[u][1]] = !dir2;
                if (flipped) {
                    if (cnt[0] < cnt[1]) state[ke[u][0]] = 0;
                    else state[ke[u][0]] = 1;
                    state[ke[u][1]] = !state[ke[u][0]];
                    ++cnt[state[ke[u][0]]];
                }
            }
            else if (ke[u].size() == 3) {
                state[ke[u][rnd.next(1, 2)]] = state[ke[u][0]];
            }

            // cerr << ke[u].size() << ' ';
            pre = u, u = ke[u][0];
            ++depth;
        }

        // cerr << "depth = " << depth << '\n';

        if (rnd.next(2)) u = pre;
        // When to stop
        if (ke[u].size() == 1) state[ke[u][0]] = !dir1;
        else if (ke[u].size() == 2) {}
        else if (ke[u].size() == 3) {}

        Alice = u;
    }

    if (subtask == 2 && testId <= 3) {
        vector<int> deg(n + 1, 0);
        for (auto it : edges) ++deg[it.fi], ++deg[it.se];
        vector<int> ve;
        for (int i = 1; i <= n; ++i)
            if (deg[i] == 1) ve.emplace_back(i);
        ensure(ve.size() == 2);
        Alice = rnd.any(ve);
        if (testId == 1) state[Alice] = 0;
        if (testId == 2) state[ve[0] ^ ve[1] ^ Alice] = 0;
    }

    cout << n << ' ' << adaptive << endl;
    println(state.begin() + 1, state.end());
    for (auto it : edges) cout << it.fi << ' ' << it.se << endl;
    cout << Alice << ' ' << Bob << endl;

    return 0;
}