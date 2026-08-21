#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

static const int N = 29;
static const int LIM = (1 << 30); // exclusive

static inline int clamp30(long long v) {
    if (v < 0) v = 0;
    if (v >= LIM) v %= LIM;
    return (int)v;
}

// Build number with fixed low k bits
static int build_with_low_bits(int low, int k) {
    int maxHighBits = 30 - k;
    int maxHigh = ((1 << maxHighBits) - 1);
    int high = rnd.next(0, maxHigh);
    long long v = ((long long)high << k) + low;
    return clamp30(v);
}

// Build number divisible by 8
static int build_div8() {
    return build_with_low_bits(0, 3);
}

static void output(const vector<pair<int,int>>& pts) {
    for (auto [x,y] : pts)
        cout << x << " " << y << "\n";
}

/* ================= STRATEGIES ================= */

static vector<pair<int,int>> gen_rand() {
    vector<pair<int,int>> pts(N);
    for (int i = 0; i < N; i++)
        pts[i] = { rnd.next(0, LIM-1),
                   rnd.next(0, LIM-1) };
    return pts;
}

static vector<pair<int,int>> gen_anti8() {
    vector<pair<int,int>> pts;
    pts.reserve(N);

    vector<pair<int,int>> residues;
    for (int rx = 0; rx < 8; rx++)
        for (int ry = 0; ry < 8; ry++)
            residues.push_back({rx, ry});

    shuffle(residues.begin(), residues.end());

    for (int i = 0; i < N; i++) {
        auto [rx, ry] = residues[i];
        int x = build_with_low_bits(rx, 3);
        int y = build_with_low_bits(ry, 3);
        pts.push_back({x,y});
    }

    shuffle(pts.begin(), pts.end());
    return pts;
}

static vector<pair<int,int>> gen_coll8() {
    vector<pair<int,int>> pts;
    pts.reserve(N);

    int m = rnd.next(2, 4);
    vector<pair<int,int>> pool;
    for (int i = 0; i < m; i++)
        pool.push_back({ rnd.next(0,7), rnd.next(0,7) });

    for (int i = 0; i < N; i++) {
        auto [rx, ry] = pool[rnd.next(0, m-1)];
        int x = build_with_low_bits(rx, 3);
        int y = build_with_low_bits(ry, 3);
        pts.push_back({x,y});
    }

    shuffle(pts.begin(), pts.end());
    return pts;
}

static vector<pair<int,int>> gen_boundary() {
    vector<pair<int,int>> pts;
    pts.reserve(N);

    // zeros
    for (int i = 0; i < 6; i++)
        pts.push_back({0,0});

    // near max
    for (int i = 0; i < 6; i++) {
        int x = LIM - 1 - rnd.next(0, 50);
        int y = LIM - 1 - rnd.next(0, 50);
        pts.push_back({x,y});
    }

    // controlled low bits near extremes
    for (int i = 0; i < 6; i++) {
        int rx = rnd.next(0,7);
        int ry = rnd.next(0,7);

        int x = clamp30((long long)(LIM - 1 - rnd.next(0, 1<<20)) & ~7LL);
        int y = clamp30((long long)(rnd.next(0, 1<<20)) & ~7LL);

        x = clamp30((long long)x + rx);
        y = clamp30((long long)y + ry);

        pts.push_back({x,y});
    }

    while ((int)pts.size() < N)
        pts.push_back({ rnd.next(0, LIM-1),
                        rnd.next(0, LIM-1) });

    shuffle(pts.begin(), pts.end());
    return pts;
}

static vector<pair<int,int>> gen_all_equal() {
    int x = rnd.next(0, LIM-1);
    int y = rnd.next(0, LIM-1);
    return vector<pair<int,int>>(N, {x,y});
}

/* ================= Subtask-1 Enforcer =================
   Guarantee: at least 8 points have x % 8 == 0 and y % 8 == 0.
*/
static void enforce_sub1(vector<pair<int,int>>& pts) {
    int cnt = 0;
    for (auto &p : pts)
        if ((p.first % 8 == 0) && (p.second % 8 == 0))
            cnt++;

    while (cnt < 8) {
        int idx = rnd.next(0, N-1);

        if ((pts[idx].first % 8 == 0) && (pts[idx].second % 8 == 0))
            continue;

        pts[idx].first  -= (pts[idx].first % 8);
        pts[idx].second -= (pts[idx].second % 8);
        cnt++;
    }
}

/* ========================= MAIN ========================= */

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    string mode = opt<string>("mode", "rand");
    bool is_sub1 = opt<int>("is_sub1", 0);

    vector<pair<int,int>> pts;

    if (mode == "rand") pts = gen_rand();
    else if (mode == "anti8") pts = gen_anti8();
    else if (mode == "coll8") pts = gen_coll8();
    else if (mode == "boundary") pts = gen_boundary();
    else if (mode == "all_equal") pts = gen_all_equal();
    else pts = gen_rand();

    if (is_sub1)
        enforce_sub1(pts);

    output(pts);
}