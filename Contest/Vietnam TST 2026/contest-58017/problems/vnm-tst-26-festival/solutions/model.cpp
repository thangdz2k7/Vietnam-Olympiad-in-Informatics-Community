/*
 * Coffman–Graham Scheduling Algorithm
 *
 * Given a DAG of n jobs with precedence constraints and W machines,
 * schedule all jobs to minimize makespan (total time slots).
 *
 * Input format (stdin):
 *   n m W          — n nodes, m edges, W machines
 *   u v            — edge u->v means u must finish before v starts
 *   (repeated m times)
 *
 * Output:
 *   For each time slot, the jobs assigned to it.
 */

#include "festivallib.h"
#include <bits/stdc++.h>
using namespace std;

struct Graph {
    int n;
    vector<vector<int>> succ;   // succ[u]: nodes that depend on u  (u -> v)
    vector<vector<int>> pred;   // pred[v]: prerequisites of v
    vector<int> in_degree;      // for topo purposes
    vector<int> out_degree;

    Graph(int n) : n(n), succ(n), pred(n), in_degree(n, 0), out_degree(n, 0) {}

    void add_edge(int u, int v) {   // u must finish before v
        succ[u].push_back(v);
        pred[v].push_back(u);
        out_degree[u]++;
        in_degree[v]++;
    }
};

// ─────────────────────────────────────────────
// Phase 1 — Label nodes 1..n
//
// Process nodes in reverse: start from sinks, work towards sources.
// At each step, among all nodes whose successors are all labeled,
// pick the one whose sorted-descending label list is lex-smallest.
// ─────────────────────────────────────────────
vector<int> compute_labels(const Graph& G) {
    int n = G.n;
    vector<int> label(n, 0);        // label[node] = assigned label
    vector<int> labeled_succ(n, 0); // how many successors have been labeled

    // A node is "ready" when all its successors are labeled
    // (i.e., labeled_succ[u] == out_degree[u])
    // Initially, sinks are ready.
    // ready_set stores ready nodes; we pick the best one each round.
    set<int> ready;
    for (int u = 0; u < n; u++)
        if (G.out_degree[u] == 0)
            ready.insert(u);

    // Comparator: given two nodes u and v, prefer u if its
    // sorted-descending successor label list is lex-smaller.
    auto get_succ_labels = [&](int u) -> vector<int> {
        vector<int> sv;
        for (int s : G.succ[u])
            sv.push_back(label[s]);
        sort(sv.rbegin(), sv.rend());
        return sv;
    };

    for (int lbl = 1; lbl <= n; lbl++) {
        // Find the ready node with the lex-smallest successor label vector
        int best = -1;
        vector<int> best_vec;

        for (int u : ready) {
            vector<int> sv = get_succ_labels(u);
            if (best == -1 || sv < best_vec) {
                best = u;
                best_vec = sv;
            }
        }

        // Assign label
        label[best] = lbl;
        ready.erase(best);

        // Unlock predecessors of best whose all successors are now labeled
        for (int p : G.pred[best]) {
            labeled_succ[p]++;
            if (labeled_succ[p] == G.out_degree[p])
                ready.insert(p);
        }
    }

    return label;
}

// ─────────────────────────────────────────────
// Phase 2 — Build the schedule
//
// Process nodes in DECREASING label order (label n first).
// Assign each node to the earliest time slot t such that:
//   1. All predecessors are scheduled in a slot < t.
//   2. Slot t has fewer than W jobs already.
// ─────────────────────────────────────────────
vector<int> build_schedule(const Graph& G,
                                   const vector<int>& label,
                                   int W) {
    int n = G.n;
    vector<int> slot(n, 0);         // slot[u] = assigned time slot (1-indexed)
    vector<int> slot_count;         // slot_count[t] = jobs in slot t
    slot_count.push_back(0);        // dummy for 1-indexing

    // Order: decreasing label → node with label n goes first
    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(),
         [&](int a, int b){ return label[a] > label[b]; });

    for (int u : order) {
        // Earliest slot forced by predecessors
        int earliest = 1;
        for (int p : G.pred[u])
            earliest = max(earliest, slot[p] + 1);

        // Find the first slot >= earliest with room for one more job
        int t = earliest;
        while (true) {
            if ((int)slot_count.size() <= t)
                slot_count.resize(t + 1, 0);
            if (slot_count[t] < W)
                break;
            t++;
        }

        slot[u] = t;
        slot_count[t]++;
    }

    return slot;
}

vector<int> solveGenius(int n, int S, const vector<int>& U, const vector<int>& V) {
    Graph G(n);
    for (int i = 0; i < U.size(); ++i) {
        G.add_edge(U[i], V[i]);
    }

    vector<int> label = compute_labels(G);
    vector<int> slot = build_schedule(G, label, S);
    return slot;
}

bool solveCitizen(const vector<int>& A,const vector<vector<int>>& history) {
    int cur = 1, last = -1;
    for (int i = 0; i < history.size(); ++i)
        if (!history[i].empty()) ++cur, last = i;
    int cnt = 0;
    for (auto &x : A) cnt += (x == cur);
    if (cnt == (int)history.size() - last - 1) return true;
    return false;
}