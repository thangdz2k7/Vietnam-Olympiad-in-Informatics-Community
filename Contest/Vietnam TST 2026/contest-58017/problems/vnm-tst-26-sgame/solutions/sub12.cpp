#include <bits/stdc++.h>
#include "sgamelib.h"

using namespace std;

vector<int> solve(int N, int M, int Q, const vector<int>& H, const vector<int>& L, const vector<int>& R, const vector<int>& P) {
    vector<int> ans(Q);
    
    vector<bool> seen(N, false);
    
    for (int i = 0; i < Q; i++) {
        int qL = L[i];
        int qR = R[i];
        int qP = P[i];
        
        int distinct_count = 0;
        bool found_P = false;
        
        vector<int> reset_list; 
        
        for (int j = M - 1; j >= 0; j--) {
            if (j >= qL && j <= qR) continue; 
            
            int x = H[j];
            if (!seen[x]) {
                seen[x] = true;
                reset_list.push_back(x);
                
                if (x == qP) {
                    ans[i] = distinct_count;
                    found_P = true;
                    break;
                }
                distinct_count++;
            }
        }
        
        if (!found_P) {
            int greater_moved = 0;
            for (int x : reset_list) {
                if (x > qP) {
                    greater_moved++;
                }
            }
            ans[i] = qP + greater_moved;
        }
        
        for (int x : reset_list) {
            seen[x] = false;
        }
    }
    
    return ans;
}