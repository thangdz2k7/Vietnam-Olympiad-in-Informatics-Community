#include <bits/stdc++.h>
#include "colorfullib.h"
using namespace std;
namespace{
#define FOR(i, l, r) for(int i = (l); i < (r); ++i)
#define F0R(i, r) FOR(i, 0, r)
#define FORD(i, l, r) for(int i = (r) - 1; i >= (l); --i)
#define F0RD(i, r) FORD(i, 0, r)
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)
#define sz(v) (int)v.size()
#define uniquify(v) v.erase(unique(all(v)), end(v))
#define ff first
#define ss second
#define mp make_pair
#define mt make_tuple 
#define pb push_back 
#define eb emplace_back 
#define tcT template<class T 
#define tcTU tcT, class U
tcT> bool minimize(T& a, const T& b){ return a > b ? a = b, 1 : 0; }
tcT> bool maximize(T& a, const T& b){ return a < b ? a = b, 1 : 0; }
tcT> using vc = vector<T>;
tcT> using vvc = vc<vc<T>>;
using ll = long long;
using db = double;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vi = vc<int>;
using vl = vc<ll>;
using vpi = vc<pi>;
using vpl = vc<pl>;
using vvi = vvc<int>;
using vvl = vvc<ll>;
using vvpi = vvc<pi>;
using vvpl = vvc<pl>;

tcT> void pr(const T& x){ cerr << x; }
void pr(char c){ cerr << '\'' << c << '\''; }
void pr(string s){ cerr << '"' << s << '"'; }
void pr(bool b){ cerr << (b ? "True" : "False"); }
tcTU> void pr(const pair<T, U>& p){ 
  cerr << "("; pr(p.ff); cerr << ", "; pr(p.ss); cerr << ")";
}
tcT> void prite(T a, T b, string sep = ", "){
  cerr << "{";
  bool f = false;
  for(T c = a; c != b; ++c){
    if(f) cerr << sep;
    pr(*c);
    f = 1;
  }
  cerr << "}";
}
tcT> void pr(const vc<T>& v){ prite(begin(v), end(v)); }
tcT> void pr(const set<T>& v){ prite(begin(v), end(v)); }
tcT> void pr(const multiset<T>& v){ prite(begin(v), end(v)); }
tcTU> void pr(const map<T, U>& v){ prite(begin(v), end(v)); }
void PR(){ cerr << '\n'; }
tcT> void PR(const T& a){ pr(a); cerr << '\n'; }
tcT, class...U> void PR(const T& a, const U&... b){
  pr(a); cerr << " | "; PR(b...);
}

#ifdef LOCAL 
  #define dbg(...) (cerr << "[:" << __LINE__ << "] (" << #__VA_ARGS__ << ") = ", PR(__VA_ARGS__), cerr << '\n')
#else 
  #define dbg(...) 
#endif //LOCAL 

mt19937 rng(12369);
}
vector<int> solve(int N){
    vi A, B;
    vi idx(N);
    iota(all(idx), 0);
    // shuffle(all(idx), rng);
    for(auto i : idx){
        A.pb(i);
        if(ask(A)){
            B.pb(i);
            A.pop_back();
        } 
    }

    vi C = A;
    C.insert(begin(C), B[0]);
    
    vi leaderA, outA; 
    auto ask2 = [&](vi a, vi b){
        a.insert(end(a), all(b));
        return ask(a);
    };

    while(sz(C) > 1){
        int u = C.back(); C.pop_back();
        if(ask2(leaderA, C)){
            outA.pb(u);
        } else{
            leaderA.pb(u);
        }
    }

    dbg(leaderA, outA);

    int bound = sz(leaderA);
    // cerr << dbg(bound) << "\n";
    vi color(N, -1), parent(N, -1);
    int cnt = 0;
    vi leaderB;

    for(auto b : B){
        bool first = true;
        int l = 0, r = sz(leaderB) - 1, firstPos = -1;
        while(l <= r){
            int mid = l + r >> 1;
            if(first) minimize(mid, sz(leaderA) - 1);
            first = false;
            int siz = min(bound, mid + 1);
            // cerr << mid << " | " << max(0, mid - bound + 1) << ", " << mid << '\n';
            vi q = {b};
            for(int i = mid - siz + 1; i <= mid; ++i) q.pb(leaderB[i]);
            int needMore = bound - siz;
            assert(sz(leaderA) >= needMore);
            F0R(i, needMore){
                q.pb(leaderA[i]);
            }
            bool res = ask(q);
            // cerr << dbg(res) << '\n';
            if(res){ //new color
                l = mid + 1;
            } else{ //exist in prefix
                firstPos = mid;
                r = mid - 1;
            }
        }
        dbg(b, firstPos);
        if(firstPos == -1){
            leaderB.pb(b);
            parent[b] = b;
        } else{
            parent[b] = leaderB[firstPos];
        }
    }

    dbg(leaderB);

    // cerr << "leaderb = ";
    // for(auto u : leaderB) cerr << u << ' ';
    // cerr << '\n';
    
    for(auto u : leaderA){
        parent[u] = u;
        color[u] = cnt++;
        // cerr << dbg(u) << dbg(color[u]) << '\n';
    }
    for(auto u : leaderB){
        color[u] = cnt++;
        // cerr << dbg(u) << dbg(color[u]) << '\n';
    }

    for(auto a : outA){
        // cerr << dbg(a) << '\n';
        int l = 0, r = sz(leaderA) - 1, pos = -1;
        while(l <= r){
            int mid = l + r >> 1;
            vi q = {a};
            int siz = mid + 1;
            for(int i = 0; i <= mid; ++i) q.pb(leaderA[i]);
            int needMore = bound - siz;
            assert(needMore <= sz(leaderB));
            F0R(i, needMore) q.pb(leaderB[i]);
            if(ask(q)){ //new color
                l = mid + 1;
            } else{
                pos = mid;
                r = mid - 1;
            }
        }
        assert(pos != -1);
        parent[a] = leaderA[pos];
    }

    F0R(u, N){
        assert(parent[u] != -1);
        color[u] = color[parent[u]];
    }

    // cerr << "color = ";
    // for(auto c : color) cerr << c << ' '; cerr << '\n';
    return color;
}