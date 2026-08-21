#include <bits/stdc++.h>

using namespace std;

const int MAX = 5e3 + 5;

using bs = bitset <MAX>;

int n, q, p[MAX], d[MAX][MAX];
bs e[MAX];

void process(){
	cin >> n >> q;
	for (int i = 1; i <= n; ++ i) {
		cin >> p[i];
		for (int j = 1; j < i; ++ j) if (p[j] > p[i]){ 
			e[i].set(j);
			e[j].set(i);
		}
	}

	for (int r = 1; r <= n; ++ r){
		queue <int> qu;
		bs not_vis;
		for (int u = 1; u <= n; ++ u) not_vis[u] = 1;

		not_vis[r] = 0, qu.push(r);
		while (qu.size()){
			int u = qu.front(); qu.pop();
			bs cur = not_vis & e[u];
			cur.set(n + 1);
			for (int v = cur._Find_first(); v <= n; v = cur._Find_next(v)) {
				not_vis.flip(v);
				d[r][v] = d[r][u] + 1;
				qu.push(v);
			}
		}
	}

	while (q --){
		int u, l, r; cin >> u >> l >> r;
		int ans = 0;
		for (int v = 1; v <= n; ++ v) if (d[u][v] >= l && d[u][v] <= r){
			ans += d[u][v];
		}
		cout << ans << "\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	process();
	return 0;
}