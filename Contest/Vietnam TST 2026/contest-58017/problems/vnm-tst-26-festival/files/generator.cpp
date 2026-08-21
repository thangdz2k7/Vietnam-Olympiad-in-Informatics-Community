#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

typedef vector<pair<int, int>> vii;

#define fi first
#define se second

pair<vii, pair<vector<int>, vector<int>>> get_layer(int S, int idx) { // 3 * S
	vii edges;
	vector<int> layer1, layer2;
	for (int i = 0; i < 2 * S - 1; ++i) layer1.emplace_back(idx++);
	for (int i = 0; i < S + 1; ++i) layer2.emplace_back(idx++);

	for (auto &x : layer1) for (int i = 1; i < layer2.size(); ++i) {
		edges.emplace_back(x, layer2[i]);
	}

	for (int i = 0; i < S; ++i)
		edges.emplace_back(layer1[i], layer2[0]);

	return make_pair(edges, make_pair(layer1, layer2));
}

pair<vii, pair<vector<int>, vector<int>>> get_chain_layer(int S, int idx) { // 3 * S + 2
	vii edges;
	vector<int> layer1, layer2;
	for (int i = 0; i < S; ++i) layer1.emplace_back(idx++);
	for (int i = 0; i < 2 * (S - 1); ++i) layer2.emplace_back(idx++);
	if (rnd.next(2)) reverse(layer1.begin(), layer1.end());
	if (rnd.next(2)) reverse(layer2.begin(), layer2.end());
	for (auto &x : layer1) for (auto &y : layer2) {
		edges.emplace_back(x, y);
	}

	layer1.emplace_back(idx++);
	for (int i = 0; i < 3; ++i) edges.emplace_back(idx - 1, idx), ++idx;
	layer2.emplace_back(idx - 1);
	return make_pair(edges, make_pair(layer1, layer2));
}

int main(int argc, char *argv[]) {
	registerGen(argc, argv, 1);
	prepareOpts(argc, argv);

	int subtask = opt<int>("subtask");
	int testId = opt<int>("testId");
	int n = opt<int>("N");
	int S = opt<int>("S");
	int flipped = opt<int>("flipped");
	string type = opt<string>("type");

	vii edges;

	if (subtask == 2) {
		for (int i = 1; i < n; ++i) {
			if (rnd.next(2)) edges.emplace_back(rnd.next(0, i - 1), i);
		}
	}
	else {
		if (type == "layer") {
			int idx = 0;
			auto pattern = get_layer(S, 0); idx += 3 * S;
			edges = pattern.fi; vector<int> pre = pattern.se.se;
			while (idx + 3 * S <= n) {
				auto pattern = get_layer(S, idx);
				for (auto &x : pre) for (auto &y : pattern.se.fi) {
					edges.emplace_back(x, y);
				}

				for (auto &it : pattern.fi) edges.emplace_back(it.fi, it.se);
				pre = pattern.se.se;

				idx += 3 * S;
			}

			while (idx < n) {
				for (auto &x : pre) edges.emplace_back(x, idx);
				++idx;
			}
		}

		if (type == "chain_layer") {
			int idx = 0;
			auto pattern = get_chain_layer(S, 0); idx += 3 * S + 2;
			edges = pattern.fi; vector<int> pre = pattern.se.se;
			while (idx + 3 * S + 2 <= n) {
				auto pattern = get_chain_layer(S, idx);
				for (auto &x : pre) for (auto &y : pattern.se.fi) {
					edges.emplace_back(x, y);
				}

				for (auto &it : pattern.fi) edges.emplace_back(it.fi, it.se);
				pre = pattern.se.se;

				idx += 3 * S + 2;
			}

			while (idx < n) {
				for (auto &x : pre) edges.emplace_back(x, idx);
				++idx;
			}
		}

		if (type == "chain") {
			int idx = 0;
			int sink = idx++, chainLen = (n - 26) / S;
			for (int _ = 0; _ < S; ++_) {
				edges.emplace_back(idx, sink); ++idx;
				for (int i = 0; i < chainLen - 1; ++i) {
					edges.emplace_back(idx - 1, idx);
					edges.emplace_back(idx, sink); ++idx;
				}
			}

			vector<int> chain = {idx++};
			for (int i = 0; i < 19; ++i) {
				edges.emplace_back(idx - 1, idx);
				chain.emplace_back(idx++);
			}

			for (int i = 0; i < 5; ++i) {
				edges.emplace_back(chain.back(), idx++);
			}

			int front = chain[0];
			while (idx < n) {
				if (rnd.next(2)) edges.emplace_back(idx, front), front = idx;
				else edges.emplace_back(chain.back(), idx);
				++idx;
			}
		}
	}

	vector<int> label(n); iota(label.begin(), label.end(), 0);
	if (testId == 1) {
		sort (label.begin(), label.end());
	}
	else if (testId == 2) {
		sort (label.begin(), label.end(), greater<int>());
	}
	else {
		shuffle(label.begin(), label.end());
	}
	for (auto &it : edges) {
		it.fi = label[it.fi], it.se = label[it.se];
		if (flipped) swap(it.fi, it.se);
	}
	shuffle(edges.begin(), edges.end());

	cout << n << ' ' << edges.size() << ' ' << S << endl;
	for (auto &it : edges) cout << it.fi << ' ' << it.se << endl;

	return 0;
}