#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

static int maxNForSubtask(int subtaskId) {
    if (subtaskId == 1) return 4;
    if (subtaskId == 2) return 5;
    if (subtaskId == 3) return 6;
    if (subtaskId == 4) return 7;
    if (subtaskId == 5) return 8;
    if (subtaskId == 6) return 9;
    if (subtaskId == 7) return 10;
    return 13;
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int subtaskId = opt<int>("subtaskId");
    int mode = opt<int>("mode");
    int n_param = opt<int>("n");

    ensuref(1 <= subtaskId && subtaskId <= 8, "subtaskId must be in 1..8");
    ensuref(1 <= mode && mode <= 6, "mode must be in 1..6");
    ensuref(0 <= n_param && n_param <= 13, "n must be in 0..13");

    int cap = maxNForSubtask(subtaskId);

    if (mode == 6) {
        int t = rnd.next(1, 20);
        cout << t << " " << subtaskId << " " << mode << "\n";

        for (int i = 0; i < t; ++i) {
            int n = rnd.next(4, cap);   // random n per testcase
            int l = rnd.next(1, n);
            int r = rnd.next(l, n);
            cout << n << " " << l << " " << r << "\n";
        }
        return 0;
    }

    // Deterministic mode
    int n;
    if (n_param == 0) {
        if (subtaskId <= 7) n = subtaskId + 3;
        else n = 13;
    } else {
        n = min(n_param, cap);
    }

    const int BUCKET_SIZE = 20;

    vector<pair<int,int>> pairs;
    pairs.reserve(1LL * n * (n + 1) / 2);
    for (int l = 1; l <= n; ++l) {
        for (int r = l; r <= n; ++r) {
            pairs.push_back({l, r});
        }
    }

    int cntBuckets = (pairs.size() + BUCKET_SIZE - 1) / BUCKET_SIZE;
    ensuref(mode <= cntBuckets,
            "mode must be <= cntBuckets (cntBuckets=%d)", cntBuckets);

    int start = (mode - 1) * BUCKET_SIZE;
    int end = min((int)pairs.size(), start + BUCKET_SIZE);
    int t = end - start;

    cout << t << " " << subtaskId << " " << mode << "\n";
    for (int i = start; i < end; ++i) {
        cout << n << " " << pairs[i].first << " " << pairs[i].second << "\n";
    }

    return 0;
}