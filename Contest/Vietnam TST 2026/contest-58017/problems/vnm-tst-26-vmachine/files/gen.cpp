#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

template<class T>
void shuffleVector(vector<T>& a, int l = 0) {
    for (int i = (int)a.size() - 1; i > l; --i) {
        int j = rnd.next(l, i);
        swap(a[i], a[j]);
    }
}

vector<pair<int, int>> makeFixedLine(int n) {
    vector<pair<int, int>> edges;
    for (int v = 2; v <= n; ++v) {
        edges.push_back({v - 1, v});
    }
    return edges;
}

vector<pair<int, int>> makeRandomPath(int n) {
    if (n <= 1) return {};

    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 1);
    shuffleVector(ord);

    vector<pair<int, int>> edges;
    for (int i = 1; i < n; ++i) {
        edges.push_back({ord[i - 1], ord[i]});
    }
    shuffleVector(edges);
    return edges;
}

vector<pair<int, int>> makeFixedStar(int n) {
    vector<pair<int, int>> edges;
    for (int v = 2; v <= n; ++v) {
        edges.push_back({1, v});
    }
    return edges;
}

// level = 0  -> line
// level = 100 -> star
vector<pair<int, int>> makeBlendTree(int n, int level) {
    if (n <= 1) return {};
    if (level <= 0) return makeFixedLine(n);
    if (level >= 100) return makeFixedStar(n);

    // Build on labels 1..n first
    vector<pair<int, int>> edges;
    for (int v = 2; v <= n; ++v) {
        // target goes from v-1 (line) down to 1 (star)
        int target = 1 + (int)(1LL * (v - 2) * (100 - level) / 100);

        int parent;
        if (rnd.next(0, 99) < 70) {
            parent = target;
        } else {
            int radius = max(1, (v - 1) / 8);
            int L = max(1, target - radius);
            int R = min(v - 1, target + radius);
            parent = rnd.next(L, R);
        }

        edges.push_back({parent, v});
    }

    // Relabel to avoid being too regular
    vector<int> perm(n + 1);
    iota(perm.begin(), perm.end(), 0);
    shuffleVector(perm, 1);

    for (auto& e : edges) {
        e.first = perm[e.first];
        e.second = perm[e.second];
    }

    shuffleVector(edges);
    return edges;
}

int getMaxN(int subtask) {
    if (subtask == 1) return 10;
    if (subtask == 2) return 10;
    if (subtask == 3) return 30;
    if (subtask == 4) return 30;
    if (subtask == 5) return 60;
    if (subtask == 6) return 100;
    if (subtask == 7) return 120;
    if (subtask == 8) return 150;
    if (subtask == 9) return 200;
    quitf(_fail, "invalid subtask");
    return -1;
}

int chooseN(int maxN, int tc) {
    static const int smalls[] = {1, 2, 3, 4, 5};

    if (tc < 5) return min(smalls[tc], maxN);
    if (tc < 15) return rnd.wnext(1, maxN, tc);
    if (tc < 30) return rnd.wnext(max(1, maxN / 2), maxN, tc);
    return maxN;
}

vector<pair<int, int>> generateCase(int subtask, int n, int tc, int T) {
    // Subtask 1:
    // A[2i-2] = i, A[2i-1] = i+1  => exact line 1->2->...->N
    if (subtask == 1) {
        return makeFixedLine(n);
    }

    // Subtask 3:
    // every vertex has at most one direct child => path
    if (subtask == 3) {
        return makeRandomPath(n);
    }

    // Other subtasks:
    // move gradually from line tree to star tree across the 50 tests
    int level = (T == 1 ? 0 : (100 * tc) / (T - 1));

    if (level == 0) return makeFixedLine(n);
    if (level == 100) return makeFixedStar(n);
    return makeBlendTree(n, level);
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int seed = opt<int>("seed");
    rnd.setSeed(seed);
    int subtask = opt<int>(1);
    int maxN = getMaxN(subtask);
    const int T = 50;

    cout << T << '\n';
    vector<vector<pair<int, int>>> trees;
    for (int tc = 0; tc < T; ++tc) {
        int n = chooseN(maxN, tc);
        vector<pair<int, int>> edges = generateCase(subtask, n, tc, T);
        shuffle(begin(edges), end(edges));
        trees.emplace_back(edges);
    }

    shuffle(begin(trees), end(trees));
    for(auto tree : trees){
      int n = (int)tree.size() + 1;
      cout << n << '\n';
      for(auto [u, v] : tree){
        cout << u << ' ' << v << '\n';
      }
    }

    return 0;
}