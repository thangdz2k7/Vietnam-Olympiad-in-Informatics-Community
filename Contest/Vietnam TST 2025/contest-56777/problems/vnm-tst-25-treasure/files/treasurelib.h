#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

namespace RCQEQBMQTC{
    int N, state[100001], adaptive;
    vector<int> adj[100001];
    int cnt, cur, QNXFDYGAAE, writeOn[100001];

    vector<pair<int, int>> info;

    void KCBVCVQKHW(int start){
        for (int i = 1; i <= N; i++){
            writeOn[i] = 0; // clean all number on floors
        }
        cur = start;
        writeOn[cur] = cnt = 1;
    }

    vector<int> YARGMTTDGZ() {
        info.clear();
        info.emplace_back(state[cur], 0);
        for (int x : adj[cur]) {
            info.emplace_back(writeOn[x], x);
        }
        while (info.size() < 4) info.emplace_back(-1, -1);
        shuffle(info.begin() + 1, info.end());
        return {info[0].first, info[1].first, info[2].first, info[3].first};
    }

    vector<int> WSGEKHBAZG(int i) {
        assert(1 <= i && i <= 3 && info[i].first != -1);
        cur = info[i].second;
        if (writeOn[cur] == 0) {
            writeOn[cur] = ++cnt;
        }
        return YARGMTTDGZ();
    }

    void QAMMWVRWRN() {
        ++QNXFDYGAAE;
        state[cur] ^= 1;
    }
}

vector<int> move(int i) { return RCQEQBMQTC::WSGEKHBAZG(i); }
void flip() { RCQEQBMQTC::QAMMWVRWRN(); }

void solveAlice(vector<int> S);
void solveBob(vector<int> S);

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    cin >> RCQEQBMQTC::N >> RCQEQBMQTC::adaptive; // number of room

    for (int i = 1; i <= RCQEQBMQTC::N; ++i) cin >> RCQEQBMQTC::state[i];

    for (int i = 1; i < RCQEQBMQTC::N; i++) {
        int u, v;
        cin >> u >> v; // room u and room v share a common wall
        RCQEQBMQTC::adj[u].push_back(v);
        RCQEQBMQTC::adj[v].push_back(u);
    }

    int Alice, Bob;
    cin >> Alice >> Bob;

    if (RCQEQBMQTC::adaptive) {
        for (int _ = 0; _ < 5; ++_) {
            int u = rnd.next(1, RCQEQBMQTC::N);
            RCQEQBMQTC::KCBVCVQKHW(u);
            solveAlice(RCQEQBMQTC::YARGMTTDGZ());
        }
    }

    RCQEQBMQTC::QNXFDYGAAE = 0;
    RCQEQBMQTC::KCBVCVQKHW(Alice);
    solveAlice(RCQEQBMQTC::YARGMTTDGZ());

    RCQEQBMQTC::KCBVCVQKHW(Bob);
    solveBob(RCQEQBMQTC::YARGMTTDGZ());

    // int Alice = rand()%RCQEQBMQTC::N + 1;
    // RCQEQBMQTC::KCBVCVQKHW(Alice, true);
    // solveAlice(RCQEQBMQTC::YARGMTTDGZ());

    // int Bob = rand()%RCQEQBMQTC::N + 1;
    // RCQEQBMQTC::KCBVCVQKHW(Bob, false);
    // solveBob(RCQEQBMQTC::YARGMTTDGZ());

    if (RCQEQBMQTC::cur != Alice) cout << -1 << endl;
    else cout << RCQEQBMQTC::QNXFDYGAAE << endl;
}