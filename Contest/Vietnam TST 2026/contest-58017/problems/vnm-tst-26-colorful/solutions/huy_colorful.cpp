#include "colorfullib.h"

#include <bits/stdc++.h>
using namespace std;

vector<int> solve(int n) {
	vector<int> ID(n, -1);
	vector<vector<int>> g;

	for (int i = 0; i < n; ++i) if (ID[i] == -1) {
		vector<int> ve = {i}; ID[i] = g.size();
		for (int j = i + 1; j < n; ++j) if (ID[j] == -1) {
			ve.emplace_back(j);
			if (ask(ve)) ve.pop_back();
			else ID[j] = ID[i];
		}
		g.emplace_back(ve);
	}

	// cerr << g.size() << '\n';

	int low = 0, high = g[0].size() - 1, last = -1;
	while (low <= high) {
		int mid = (low + high) >> 1;
		vector<int> ve(g[0].begin(), g[0].begin() + mid + 1);
		ve.emplace_back(g[1][0]);
		if (!ask(ve)) low = (last = mid) + 1;
		else high = mid - 1;
	}

	vector<int> ans(n, -1), base(g[0].begin(), g[0].begin() + last + 1);
	int color = 0; vector<int> colors;

	for (int i = 1; i < g.size(); ++i) {
		for (auto &x : g[i]) if (ans[x] == -1) {
			vector<int> ve = base; ve.emplace_back(x);
			ans[x] = color++;
			if (i == 1) colors.emplace_back(x);
			for (auto &y : g[i]) if (ans[y] == -1) {
				ve.emplace_back(y);
				if (ask(ve)) ve.pop_back();
				else ans[y] = ans[x];
			}
		}
	}

	colors.pop_back();
	// cerr << colors.size() << '\n';

	for (auto &x : g[0]) if (ans[x] == -1) {
		vector<int> ve = colors; ve.emplace_back(x);
		ans[x] = color++;
		for (auto &y : g[0]) if (ans[y] == -1) {
			ve.emplace_back(y);
			if (ask(ve)) ve.pop_back();
			else ans[y] = ans[x];
		}
	}

	// for (auto &x : ans) cerr << x << ' ';
	// cerr << '\n';
	return ans;
}