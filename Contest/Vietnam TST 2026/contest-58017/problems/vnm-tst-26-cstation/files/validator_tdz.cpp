#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    string subtask = validator.group();

    int T = inf.readInt(1, 200000, "T");
    inf.readEoln();

    long long sumN = 0, sumK = 0, sumQ = 0;

    for (int tc = 1; tc <= T; tc++) {
        setTestCase(tc);

        int N = inf.readInt(1, 100000, "N");
        inf.readSpace();
        int K = inf.readInt(1, 100000, "K");
        inf.readSpace();
        int Q = inf.readInt(1, 100000, "Q");
        inf.readEoln();

        sumN += N;
        sumK += K;
        sumQ += Q;

        auto isSub = [&](int x) {
            return subtask == to_string(x);
        };

        // Subtask 1
        if (isSub(1)) {
            ensuref(N <= 14 && K <= 14 && Q <= 14 && T <= 50,
                    "Subtask 1 violated");
        }

        // Subtask 2
        if (isSub(2)) {
            ensuref(sumN <= 500 && sumK <= 500 && sumQ <= 500,
                    "Subtask 2 violated");
        }

        // Subtask 3
        if (isSub(3)) {
            ensuref(sumN <= 3000 && sumK <= 3000 && sumQ <= 3000,
                    "Subtask 3 violated");
        }

        vector<int> A(N - 1), B(N - 1);

        for (int i = 0; i < N - 1; i++) {
            A[i] = inf.readInt(0, N - 1, "A[i]");
            inf.readSpace();
            B[i] = inf.readInt(0, N - 1, "B[i]");
            inf.readEoln();

            ensuref(A[i] != B[i], "self-loop");
        }

        // Subtask 4: chain
        if (isSub(4)) {
            for (int i = 0; i < N - 1; i++) {
                ensuref(A[i] == i && B[i] == i + 1,
                        "Subtask 4 violated at edge %d", i);
            }
        }

        // check tree
        vector<vector<int>> adj(N + 1);
        for (int i = 0; i < N - 1; i++) {
            adj[A[i]].push_back(B[i]);
            adj[B[i]].push_back(A[i]);
        }

        vector<bool> vis(N + 1, false);
        queue<int> q;
        q.push(1);
        vis[1] = true;

        int cnt = 1;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) {
                if (!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                    cnt++;
                }
            }
        }
        ensuref(cnt == N, "Graph not connected");

        // U, V
        for (int i = 0; i < K; i++) {
            int U = inf.readInt(0, N - 1, "U[i]");
            inf.readSpace();
            int V = inf.readInt(0, N - 1, "V[i]");
            inf.readEoln();
        }

        // X, Y
        for (int i = 0; i < Q; i++) {
            int X = inf.readInt(0, N - 1, "X[i]");
            inf.readSpace();
            int Y = inf.readInt(0, N - 1, "Y[i]");
            inf.readEoln();
        }
    }

    // Global constraint
    ensuref(sumN <= 200000, "sum N too large");
    ensuref(sumK <= 200000, "sum K too large");
    ensuref(sumQ <= 200000, "sum Q too large");

    inf.readEof();
}