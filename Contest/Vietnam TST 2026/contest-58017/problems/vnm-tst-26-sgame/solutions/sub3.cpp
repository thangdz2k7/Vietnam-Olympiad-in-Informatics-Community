#include <bits/stdc++.h>
#include "sgamelib.h"

using namespace std;

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

vector<int> solve(int N, int M, int Q, const vector<int>& H, const vector<int>& L_arr, const vector<int>& R_arr, const vector<int>& P_arr) {
    vector<int> Last(N, -1);
    vector<int> Prev(M, -1);
    vector<int> last_seen(N, -1);
    
    Fenwick bit_pos(M); 
    Fenwick bit_val(N); 
    
    for (int i = 0; i < M; i++) {
        int x = H[i];
        Prev[i] = last_seen[x];
        last_seen[x] = i;
        Last[x] = i;
    }
    
    for (int x = 0; x < N; x++) {
        if (Last[x] != -1) {
            bit_pos.add(Last[x] + 1, 1); // BIT dùng index 1-based
            bit_val.add(x + 1, 1);
        }
    }
    
    vector<int> ans(Q);
    
    for (int i = 0; i < Q; i++) {
        int L = L_arr[i];
        int R = R_arr[i];
        int P = P_arr[i];
        
        vector<pair<int, int>> pos_changes; 
        vector<int> val_changes;
        
        for (int j = L; j <= R; j++) {
            int x = H[j];
            
            if (Last[x] == j) {
                int curr = j;
                while (curr >= L) {
                    curr = Prev[curr];
                }
                
                int new_last = curr; 
                pos_changes.push_back({j, new_last});
                
                if (new_last == -1) {
                    val_changes.push_back(x);
                }
            }
        }
        
        for (auto change : pos_changes) {
            bit_pos.add(change.first + 1, -1);
            if (change.second != -1) bit_pos.add(change.second + 1, 1);
        }
        for (int x : val_changes) {
            bit_val.add(x + 1, -1);
        }
        
        int pos_P = -1;
        if (Last[P] > R) {
            pos_P = Last[P];
        } else if (Last[P] < L) {
            pos_P = Last[P];
        } else {
            int curr = Last[P];
            while (curr >= L) curr = Prev[curr];
            pos_P = curr;
        }
        
        if (pos_P != -1) {
            ans[i] = bit_pos.query(pos_P + 2, M); 
        } else {
            ans[i] = P + bit_val.query(P + 2, N);
        }
        
        for (auto change : pos_changes) {
            if (change.second != -1) bit_pos.add(change.second + 1, -1);
            bit_pos.add(change.first + 1, 1);
        }
        for (int x : val_changes) {
            bit_val.add(x + 1, 1);
        }
    }
    
    return ans;
}