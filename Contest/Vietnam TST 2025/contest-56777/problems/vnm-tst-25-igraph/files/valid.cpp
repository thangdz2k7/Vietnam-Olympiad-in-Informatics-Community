#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
*/

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
template <class T> using PQMax = priority_queue<T>;
template <class T> using PQMin = priority_queue<T, vector<T>, greater<T>>;
template <class T1, class T2>
bool maximize(T1 &a, T2 b){
	return (b > a) ? (a = b, true) : false;
}
template <class T1, class T2>
bool minimize(T1 &a, T2 b){
	return (b < a) ? (a = b, true) : false;
}
template <class T>
void read(T &number)
{
	bool negative = false;
	register int c;
	number = 0;
	c = getchar();
	while (c != '-' && !isalnum(c)) c = getchar();
	if (c=='-'){
		negative = true;
		c = getchar();
	}
	for (; (c>47 && c<58); c=getchar())
		number = number *10 + c - 48;
	if (negative)
		number *= -1;
}
template <class T, class ...Ts>
void read(T &a, Ts& ... args){
	read(a);
	read(args...);
}

/*
struct Node
{
	int node, len;
	Node() {node = len = 0;}
	Node(int node, int len) {this -> node = node, this -> len = len;}
};
typedef vector<Node> vg;
*/

#define fi first
#define se second

#define FOR(type, i, a, b) for(type i = (a); i <= (b); i++)
#define REV(type, i, b, a) for(type i = (b); i >= (a); i--)

#define testBit(n, bit) (((n) >> (bit)) & 1)
#define flipBit(n, bit) ((n) ^ (1ll << (bit)))
#define cntBit(n) __builtin_popcount(n)
#define cntBitll(n) __builtin_popcountll(n)
#define log2(n) (31 - __builtin_clz(n))
#define log2ll(n) (63 - __builtin_clzll(n))
#define CURRENT_TIMESTAMP chrono::steady_clock::now().time_since_epoch().count()
#define randomize mt19937_64 mt(CURRENT_TIMESTAMP)

#define MAX_NQ 100'000
#define MOD 1000000007

int n, q, SUBTASK;
vector<int> p;
int u[MAX_NQ + 1];
int l[MAX_NQ + 1];
int r[MAX_NQ + 1];

void readInput() {
	n = inf.readInt(1, MAX_NQ, "n"); inf.readSpace();
	q = inf.readInt(1, MAX_NQ, "q"); inf.readEoln();

	p = inf.readInts(n, 1, n, "p"); inf.readEoln();
	FOR(int, i, 1, q) {
		u[i] = inf.readInt(1, n, "u[i]"); inf.readSpace();
		l[i] = inf.readInt(1, n, "l[i]"); inf.readSpace();
		r[i] = inf.readInt(1, n, "r[i]"); inf.readEoln();
		ensuref(l[i] <= r[i], "ith query has l > r");
	}
	inf.readEof();
}

bool used[MAX_NQ];
void isPerm() {
	for (int num: p) {
		ensuref(not used[num], "p is not a perm");
		used[num] = true;
	}
}

void checkSubtask() {
	if (SUBTASK == 1) {
		ensuref(n <= 300 and q <= 300, "wrong subtask 1");
		return;
	}
	if (SUBTASK == 2) {
		ensuref(n <= 5000 and q <= 5000, "wrong subtask 2");
		return;
	}
	if (SUBTASK == 3) {
		FOR(int, i, 1, q)
			ensuref(r[i] <= 20, "wrong subtask 3 at %dth query", i);
		return;
	}
	if (SUBTASK == 4) {
		FOR(int, i, 1, q) {
			ensuref(l[i] == 1, "wrong subtask 4 at %dth query", i);
			ensuref(r[i] == n, "wrong subtask 4 at %dth query", i);
		}
		return;
	}
	return;
}

int main(int argc, char* argv[])
{
    registerValidation(argc, argv);
    prepareOpts(argc, argv);
    readInput();
    isPerm();

    string subtaskName = validator.group();
    SUBTASK = *subtaskName.rbegin() - '0';
    checkSubtask();
}
