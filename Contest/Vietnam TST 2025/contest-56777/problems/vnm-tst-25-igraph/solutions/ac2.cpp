#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

int N, Q;
int P[MAXN], pos[MAXN];
int f_1[MAXN], f_2[MAXN], g_1[MAXN], g_2[MAXN];

struct Node {
    int count;
    int left, right;
} tree[4000000];

int root[MAXN];
int node_cnt = 0;

int update(int node, int l, int r, int idx) {
    int new_node = ++node_cnt;
    tree[new_node] = tree[node];
    tree[new_node].count++;

    if (l == r) return new_node;

    int mid = (l + r) / 2;
    if (idx <= mid)
        tree[new_node].left = update(tree[node].left, l, mid, idx);
    else
        tree[new_node].right = update(tree[node].right, mid + 1, r, idx);

    return new_node;
}

int query(int node, int l, int r, int ql, int qr) {
    if (!node || ql > r || qr < l) return 0;
    if (ql <= l && r <= qr) return tree[node].count;

    int mid = (l + r) / 2;
    return query(tree[node].left, l, mid, ql, qr) +
           query(tree[node].right, mid + 1, r, ql, qr);
}

const int HASH_SIZE = 10000007;

int head[HASH_SIZE];

struct Edge {
    long long key;
    int val;
    int next;
} edges[5000005];

int edge_cnt = 0;

inline void init_hash() {
    memset(head, -1, sizeof(head));
}

inline int get_hash(long long key) {
    int h = key % HASH_SIZE;
    for (int i = head[h]; i != -1; i = edges[i].next) {
        if (edges[i].key == key) return edges[i].val;
    }
    return -1;
}

inline void insert_hash(long long key, int val) {
    int h = key % HASH_SIZE;
    edges[edge_cnt] = {key, val, head[h]};
    head[h] = edge_cnt++;
}

inline int get_BL_memo(int L1, int L2) {
    if (L1 <= 1 || L2 <= 1) return 0;

    long long key = ((long long)L1 << 32) | L2;
    int val = get_hash(key);
    if (val != -1) return val;

    int res = query(root[L1 - 1], 1, N, 1, L2 - 1);
    insert_hash(key, res);
    return res;
}

inline int get_TR_memo(int R1, int R2) {
    if (R1 >= N || R2 >= N) return 0;

    long long key = (((long long)R1 << 32) | R2) ^ 0x123456789ABCDEF0LL;
    int val = get_hash(key);
    if (val != -1) return val;

    int res = (N - R1) - (query(root[N], 1, N, 1, R2) -
                          query(root[R1], 1, N, 1, R2));

    insert_hash(key, res);
    return res;
}

struct Query {
    int l, r, id;
};

vector<Query> qs[MAXN];
long long ans_out[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> N >> Q)) return 0;

    for (int i = 1; i <= N; ++i) {
        cin >> P[i];
        pos[P[i]] = i;
    }

    f_1[N] = pos[N];
    for (int y = N - 1; y >= 1; --y)
        f_1[y] = min(f_1[y + 1], pos[y]);

    f_2[N] = P[N];
    for (int x = N - 1; x >= 1; --x)
        f_2[x] = min(f_2[x + 1], P[x]);

    g_1[1] = pos[1];
    for (int y = 2; y <= N; ++y)
        g_1[y] = max(g_1[y - 1], pos[y]);

    g_2[1] = P[1];
    for (int x = 2; x <= N; ++x)
        g_2[x] = max(g_2[x - 1], P[x]);

    root[0] = 0;

    for (int i = 1; i <= N; ++i) {
        root[i] = update(root[i - 1], 1, N, P[i]);
    }

    for (int i = 0; i < Q; ++i) {
        int u, l, r;
        cin >> u >> l >> r;
        qs[u].push_back({l, r, i});
    }

    init_hash();

    vector<int> C_vals;
    vector<long long> pref_ans;

    for (int u = 1; u <= N; ++u) {
        if (qs[u].empty()) continue;

        C_vals.clear();

        int prev_BL = get_BL_memo(u, P[u]);
        int prev_TR = get_TR_memo(u, P[u]);

        C_vals.push_back(0);
        C_vals.push_back(N - 1 - prev_BL - prev_TR);

        int cur_L1 = f_1[P[u]], cur_L2 = f_2[u];
        int cur_R1 = g_1[P[u]], cur_R2 = g_2[u];

        while (true) {
            int cur_BL = get_BL_memo(cur_L1, cur_L2);
            int cur_TR = get_TR_memo(cur_R1, cur_R2);

            int c_d = prev_BL - cur_BL + prev_TR - cur_TR;
            C_vals.push_back(c_d);

            if (cur_BL == prev_BL && cur_TR == prev_TR) break;

            prev_BL = cur_BL;
            prev_TR = cur_TR;

            int nxt_L1 = f_1[cur_L2];
            int nxt_L2 = f_2[cur_L1];
            int nxt_R1 = g_1[cur_R2];
            int nxt_R2 = g_2[cur_R1];

            cur_L1 = nxt_L1;
            cur_L2 = nxt_L2;
            cur_R1 = nxt_R1;
            cur_R2 = nxt_R2;
        }

        pref_ans.assign(C_vals.size(), 0);

        for (size_t d = 1; d < C_vals.size(); ++d) {
            pref_ans[d] = pref_ans[d - 1] + 1LL * d * C_vals[d];
        }

        int max_d = (int)C_vals.size() - 1;

        for (const auto& q : qs[u]) {
            long long res = 0;

            if (q.l <= max_d) {
                int actual_r = min(q.r, max_d);
                res = pref_ans[actual_r] - pref_ans[q.l - 1];
            }

            ans_out[q.id] = res;
        }
    }

    for (int i = 0; i < Q; ++i) {
        cout << ans_out[i] << "\n";
    }

    return 0;
}
