#include <bits/stdc++.h>
#include "vmachinelib.h"

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
}

namespace{
const int MAX = 2e3;
int cnt, zero, one;
int dum[10];

int newNode(){
  return cnt++;
}

void init(int N){
  cnt = 2 * N - 2;
  zero = newNode(); one = newNode();
  F0R(i, 10) dum[i] = newNode(); //init dummies
  cmp(one, one, one); //create 1
}

}

void add(int i, int j, int k){
  sub(zero, i, dum[0]);
  sub(dum[0], j, dum[0]);
  sub(zero, dum[0], k);
}

void isZero(int i, int j){ //A[j] = (A[i] == 0)
  //check if -A[i] = A[i] 
  int neg = dum[8];
  sub(zero, i, neg);
  cmp(neg, i, j);
}

void conditionalCopy(int a, int b, int cond){
  //if cond = 1 => A[a] = A[b]
  sub(a, b, dum[0]);
  mul(dum[0], cond, dum[0]);
  sub(a, dum[0], a);
}

void solve(int N){
  init(N);
  //create 1, 2, ..., N
  vi posIndex(N + 1), posDeg(N + 1);
  FOR(i, 1, N + 1){
    posIndex[i] = newNode();
  }

  FOR(i, 1, N + 1){
    posDeg[i] = newNode();
  }

  int negOne = newNode();
  sub(zero, one, negOne);
  sub(posIndex[1], negOne, posIndex[1]);
  FOR(i, 2, N + 1){
    sub(posIndex[i - 1], negOne, posIndex[i]);
  }

  for(int i = 1; i <= N; ++i){
    for(int j = 1; j < 2 * N - 2; j += 2){
      cmp(posIndex[i], j, dum[9]);
      sub(zero, dum[9], dum[9]);
      sub(posDeg[i], dum[9], posDeg[i]);
    }
  }

  int extraIndex = newNode();
  int dummy = newNode(), found = newNode();
  add(posIndex[N], posIndex[N], dummy);
  for(int _ = 1; _ <= N; ++_){
    sub(one, zero, found);
    for(int j = 1; j <= N; ++j){
      isZero(posDeg[j], dum[9]);
      mul(dum[9], found, dum[8]);
      int cond = dum[8];
      
      //cond = 1 => extraIndex = posIndex[i], posDeg[i] = A[dummy], found = false
      conditionalCopy(extraIndex, posIndex[j], cond);
      conditionalCopy(posDeg[j], dummy, cond);

      cmp(found, one, dum[0]);
      cmp(cond, zero, dum[1]);
      mul(dum[0], dum[1], found);
    }

    print(extraIndex);
    F0R(e, N - 1){
      int uid = 2 * e, vid = 2 * e + 1;
      for(int v = 1; v <= N; ++v){
        cmp(vid, posIndex[v], dum[0]);
        cmp(uid, extraIndex, dum[1]);
        mul(dum[0], dum[1], dum[2]);
        sub(posDeg[v], dum[2], posDeg[v]);
      }
    }
  }
}
