#include <bits/stdc++.h>
#include "sgamelib.h"

using namespace std;

const int INF = 1e9;

// Cấu trúc BIT 1D cơ bản
struct Fenwick {
    int n;
    vector<int> tree;
    Fenwick(int n) : n(n), tree(n + 1, 0) {}
    void add(int i, int delta) {
        for (; i <= n; i += i & -i) tree[i] += delta;
    }
    int query(int i) {
        int sum = 0;
        for (; i > 0; i -= i & -i) sum += tree[i];
        return sum;
    }
    int query(int l, int r) {
        if (l > r) return 0;
        return query(r) - query(l - 1);
    }
};

// Cấu trúc 2D Segment Tree siêu tốc cho offline queries
struct SegTree2D {
    int n;
    vector<vector<int>> vals;
    vector<vector<int>> bit;
    
    SegTree2D(int n) : n(n), vals(4 * n), bit(4 * n) {}
    
    void build(int node, int l, int r, const vector<int>& y_arr) {
        for (int i = l; i <= r; i++) {
            if (y_arr[i] != INF && y_arr[i] != -1) vals[node].push_back(y_arr[i]);
        }
        sort(vals[node].begin(), vals[node].end());
        vals[node].erase(unique(vals[node].begin(), vals[node].end()), vals[node].end());
        bit[node].assign(vals[node].size() + 1, 0);
        if (l == r) return;
        int mid = l + (r - l) / 2;
        build(2 * node, l, mid, y_arr);
        build(2 * node + 1, mid + 1, r, y_arr);
    }
    
    void update(int node, int l, int r, int x, int y_val, int delta) {
        int pos = lower_bound(vals[node].begin(), vals[node].end(), y_val) - vals[node].begin() + 1;
        for (int i = pos; i < bit[node].size(); i += i & -i) bit[node][i] += delta;
        if (l == r) return;
        int mid = l + (r - l) / 2;
        if (x <= mid) update(2 * node, l, mid, x, y_val, delta);
        else update(2 * node + 1, mid + 1, r, x, y_val, delta);
    }
    
    int query(int node, int l, int r, int ql, int qr, int min_y) {
        if (ql > r || qr < l) return 0;
        if (ql <= l && r <= qr) {
            int pos = lower_bound(vals[node].begin(), vals[node].end(), min_y) - vals[node].begin() + 1;
            int total = 0, minus = 0;
            for (int i = bit[node].size() - 1; i > 0; i -= i & -i) total += bit[node][i];
            for (int i = pos - 1; i > 0; i -= i & -i) minus += bit[node][i];
            return total - minus;
        }
        int mid = l + (r - l) / 2;
        return query(2 * node, l, mid, ql, qr, min_y) + 
               query(2 * node + 1, mid + 1, r, ql, qr, min_y);
    }
};

struct QueryX { int l, r, id, min_y; };
struct QueryC3 { int L, P, id; };

vector<int> solve(int N, int M, int Q, const vector<int>& H, const vector<int>& L_arr, const vector<int>& R_arr, const vector<int>& P_arr) {
    vector<int> First(N, INF), Last(N, -INF);
    vector<int> Prv(M, -1);
    vector<int> last_seen(N, -1);
    vector<vector<int>> pos(N);
    
    // Tiền xử lý vị trí các thao tác
    for (int i = 0; i < M; i++) {
        int x = H[i];
        if (First[x] == INF) First[x] = i;
        Last[x] = i;
        Prv[i] = last_seen[x];
        last_seen[x] = i;
        pos[x].push_back(i);
    }
    
    // Lưu vết tuyệt đối lần xuất hiện cuối cùng của mỗi phần tử
    vector<int> AbsLast(N, -1);
    for (int i = 0; i < M; i++) AbsLast[H[i]] = i;
    
    vector<int> y_arr_XY(M);
    for (int i = 0; i < M; i++) y_arr_XY[i] = AbsLast[H[i]];

    // Đếm số phần tử phân biệt ở hậu tố
    vector<int> suf_distinct(M + 1, 0);
    vector<bool> seen(N, false);
    int dist_count = 0;
    for (int i = M - 1; i >= 0; i--) {
        if (!seen[H[i]]) {
            seen[H[i]] = true;
            dist_count++;
        }
        suf_distinct[i] = dist_count;
    }
    
    // Đếm số phần tử không bao giờ bị thao tác
    vector<int> never_op(N + 1, 0);
    for (int i = N - 1; i >= 0; i--) {
        never_op[i] = never_op[i + 1] + (First[i] == INF ? 1 : 0);
    }
    
    vector<int> ans(Q, 0);
    vector<vector<QueryX>> queries_X(M); 
    vector<vector<QueryC3>> queries_C3(M);
    
    // Phân loại truy vấn
    for (int i = 0; i < Q; i++) {
        int L = L_arr[i], R = R_arr[i], P = P_arr[i];
        
        if (!pos[P].empty() && pos[P].back() >= R + 1) {
            ans[i] = suf_distinct[pos[P].back() + 1]; // Case 1
        } else {
            auto it = lower_bound(pos[P].begin(), pos[P].end(), L);
            if (it != pos[P].begin()) {
                int idx = *(--it);
                ans[i] = suf_distinct[R + 1]; // Case 2 base (|Y|)
                if (idx + 1 <= L - 1) {
                    queries_X[L - 1].push_back({idx + 1, L - 1, i, R + 1});
                }
            } else {
                ans[i] = (N - 1) - never_op[P + 1]; // Case 3 base
                queries_C3[R].push_back({L, P, i});
            }
        }
    }
    
    // Giải quyết Case 2: |X| - |X ∩ Y|
    SegTree2D segXY(M);
    segXY.build(1, 0, M - 1, y_arr_XY);
    Fenwick bit_X(M);
    
    for (int i = 0; i < M; i++) {
        if (Prv[i] != -1) {
            bit_X.add(Prv[i] + 1, -1);
            segXY.update(1, 0, M - 1, Prv[i], AbsLast[H[i]], -1);
        }
        bit_X.add(i + 1, 1);
        segXY.update(1, 0, M - 1, i, AbsLast[H[i]], 1);
        
        for (auto& q : queries_X[i]) {
            int size_X = bit_X.query(q.l + 1, q.r + 1);
            int size_XY = 0;
            if (q.min_y < M) {
                size_XY = segXY.query(1, 0, M - 1, q.l, q.r, q.min_y);
            }
            ans[q.id] += size_X - size_XY;
        }
    }
    
    // Giải quyết Case 3: Trừ đi các phần tử chỉ thao tác trong [L, R]
    SegTree2D segC3(N);
    segC3.build(1, 0, N - 1, First);
    
    vector<vector<int>> events_by_last(M);
    for (int x = 0; x < N; x++) {
        if (Last[x] >= 0) events_by_last[Last[x]].push_back(x);
    }
    
    for (int R = 0; R < M; R++) {
        for (int x : events_by_last[R]) {
            segC3.update(1, 0, N - 1, x, First[x], 1);
        }
        for (auto& q : queries_C3[R]) {
            ans[q.id] -= segC3.query(1, 0, N - 1, q.P + 1, N - 1, q.L);
        }
    }
    
    return ans;
}