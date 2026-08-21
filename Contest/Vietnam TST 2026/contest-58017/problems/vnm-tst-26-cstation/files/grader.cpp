#include "cstationlib.h"

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--)
    {
        int N, K, Q;
        cin >> N >> K >> Q;

        vector<int> A, B, U, V, X, Y;

        for (int i = 1; i < N; i++)
        {
            int u, v;
            cin >> u >> v;
            A.push_back(u);
            B.push_back(v);
        }

        for (int i = 1; i <= K; i++)
        {
            int u, v;
            cin >> u >> v;
            U.push_back(u);
            V.push_back(v);
        }

        for (int i = 1; i <= Q; i++)
        {
            int u, v;
            cin >> u >> v;
            X.push_back(u);
            Y.push_back(v);
        }

        vector<int> res = solve(N, K, Q, A, B, U, V, X, Y);

        for (int x : res) 
            cout << x << ' ';
        cout << '\n';
    }
}