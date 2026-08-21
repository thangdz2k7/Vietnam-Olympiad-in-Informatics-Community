#include <bits/stdc++.h>
#include "sgamelib.h"

using namespace std;

vector<int> solve(int N, int M, int Q, const vector<int>& H, const vector<int>& L, const vector<int>& R, const vector<int>& P) {
    vector<int> ans(Q);

    for (int i = 0; i < Q; i++) {
        int qL = L[i];
        int qR = R[i];
        int qP = P[i];

        vector<int> A(N);
        for (int j = 0; j < N; j++) {
            A[j] = j;
        }

        for (int j = 0; j < M; j++) {
            if (j >= qL && j <= qR) {
                continue;
            }

            int val_to_move = H[j];
            int current_pos = -1;

            for (int k = 0; k < N; k++) {
                if (A[k] == val_to_move) {
                    current_pos = k;
                    break;
                }
            }

            if (current_pos > 0) {
                for (int k = current_pos; k > 0; k--) {
                    A[k] = A[k - 1];
                }
                A[0] = val_to_move;
            }
        }

        for (int k = 0; k < N; k++) {
            if (A[k] == qP) {
                ans[i] = k;
                break;
            }
        }
    }

    return ans;
}