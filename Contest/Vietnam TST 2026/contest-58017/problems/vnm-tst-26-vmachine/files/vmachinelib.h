#include <bits/stdc++.h>

using namespace std;

namespace JURJJRURYRJRURY{

void wa(string msg){
  cout << "Wrong answer (" << msg << ")\n";
  exit(0);
}

int read(int l = INT_MIN, int r = INT_MAX, string msg = ""){
  int x; 
  if(!(cin >> x)) wa("error input " + msg);
  if(!(l <= x && x <= r)) wa("invalid range " + msg);
  return x;
}

const int SIZE = 2000;
const int MIN = -32768;
const int MAX = +32767;
const int LIMIT = 4e6;

int NTN, used[205], op, maxOp;
vector<pair<int, int>> treeEdges;
vector<int> tour;
int16_t A[SIZE];

void reset(){
  maxOp = max(op, maxOp);
  op = 0;
  treeEdges.clear();
  tour.clear();
  fill(used, used + 205, 0);
}

void init(){
  for(int i = 0; i < SIZE; ++i){
    A[i] = 0;
  }

  for(int i = 0; i < NTN - 1; ++i){
    A[2 * i] = treeEdges[i].first;
    A[2 * i + 1] = treeEdges[i].second;
  }
}

void checkPos(int i){
  if(!(0 <= i && i < SIZE)) wa("invalid index call");
}

void addOp(){
  ++op;
  if(op > LIMIT) wa("exceeded maximum number of operations");
}

void sub(int i, int j, int k){
  checkPos(i);
  checkPos(j);
  checkPos(k);
  A[k] = A[i] - A[j];
  addOp();
}

void mul(int i, int j, int k){
  checkPos(i);
  checkPos(j);
  checkPos(k);
  A[k] = A[i] * A[j];
  addOp();
}

void cmp(int i, int j, int k){
  checkPos(i);
  checkPos(j);
  checkPos(k);
  A[k] = (A[i] == A[j]);
  addOp();
}

void print(int i){
  checkPos(i);
  int u = A[i];
  if(!(1 <= u && u <= NTN)) wa("invalid index vertex");
  if(used[u]) wa("appeared");
  tour.emplace_back(u);
  used[u] = 1;
}

int pos[205];
void checkAnswer(){
  if((int)tour.size() < NTN) wa("print less than NTN times");
  for(int i = 0; i < NTN; ++i) pos[tour[i]] = i;
  for(int i = 0; i < NTN - 1; ++i){
    int u, v;
    tie(u, v) = treeEdges[i];
    if(!(pos[u] < pos[v])) wa("wrong order");
  }
}

}

void print(int i){
  JURJJRURYRJRURY::print(i);
}
void sub(int i, int j, int k){
  JURJJRURYRJRURY::sub(i, j, k);
}
void mul(int i, int j, int k){
  JURJJRURYRJRURY::mul(i, j, k);
}
void cmp(int i, int j, int k){
  JURJJRURYRJRURY::cmp(i, j, k);
}
void solve(int NTN);

int main(){
  int T = JURJJRURYRJRURY::read(1, 50, "T");
  for(int t = 0; t < T; ++t){
    int NTN = JURJJRURYRJRURY::read(1, 200, "NTN");
    JURJJRURYRJRURY::NTN = NTN;
    for(int i = 0; i < NTN - 1; ++i){
      int u = JURJJRURYRJRURY::read(1, NTN, "u"), v = JURJJRURYRJRURY::read(1, NTN, "v");
      JURJJRURYRJRURY::treeEdges.emplace_back(u, v);
    }
    JURJJRURYRJRURY::init();
    solve(NTN);
    JURJJRURYRJRURY::checkAnswer();
    JURJJRURYRJRURY::reset();
  }
  cout << "Accepted " << JURJJRURYRJRURY::maxOp;
  return 0;
}