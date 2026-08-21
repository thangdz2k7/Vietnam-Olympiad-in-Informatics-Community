#include "testlib.h"
#include <bits/stdc++.h>
 
using namespace std;
 
// contestant phải implement
vector<int> solveAlice(vector<vector<int>> adj);
vector<vector<int>> solveBob(vector<int> S);
 
int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
 
    int M = 0;
 
    int T; cin >> T; while (T --){
 
        int N; cin >> N;
 
        vector <int> fa(N, -1);
        vector <vector <int>> adj_Alice(N);
 
        for (int i = 0; i < N; ++ i){
            int siz; cin >> siz;
            adj_Alice[i].resize(siz);
            for (int &c : adj_Alice[i]) cin >> c, fa[c] = i;
        }
 
        vector <int> encode = solveAlice(adj_Alice);
        assert(int(encode.size()) == N);
        for (int val : encode){
            assert(0 < val && val < 89);
            M = max(M, val);
        }
 
        vector <int> ord(N);
        iota(ord.begin(), ord.end(), 0);
        shuffle(ord.begin(), ord.end());
 
        vector <int> send_Bob = encode;
        for (int i = 0; i < N; ++ i) send_Bob[i] = encode[ord[i]];

        vector <int> used(N, 0);
        int nume = 0;
 
        vector <vector <int>> adj_Bob = solveBob(send_Bob);
        assert(int(adj_Bob.size()) == N);
        for (int i = 0; i < N; ++ i){
            for (int c : adj_Bob[i]){
                assert(0 <= c && c < N);
                if (used[ord[c]] || fa[ord[c]] != ord[i]){
                    cout << -1 << endl;
                    return 0;
                }
                used[ord[c]] = 1;
                nume ++;
            }
        }

        if (nume != N - 1) {
            cout << -1 << endl;
            return 0;
        }
    }
 
    
    cout << M << endl;
 
    return 0;
}