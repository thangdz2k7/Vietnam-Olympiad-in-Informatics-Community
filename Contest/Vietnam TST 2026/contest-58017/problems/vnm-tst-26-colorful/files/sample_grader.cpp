#include<bits/stdc++.h>
#include "colorfullib.h"
using namespace std;
namespace Grader{
  int n, k;
  vector<int>a;
  bool ask(vector<int>ve){
    vector<bool>vis(k, false);
    for(int& x : ve){
      vis[a[x]] = true;
    }
    return count(vis.begin(), vis.end(), true) >= ((k + 1) >> 1);
  }
  void process_test(){
    cin >> n >> k;
    a.resize(n);
    for(int i = 0; i < n; i++){
      cin >> a[i];
    }
    vector<int>b = solve(n);
    for(int i = 0; i < n; i++){
      for(int j = i + 1; j < n; j++){
        if((a[i] == a[j] && b[i] != b[j]) || (a[i] != a[j] && b[i] == b[j])){
          cout << "Wrong Answer";
          return;
        }
      }
    }
    cout << "Accepted!";
  }
}
bool ask(vector<int>ve){
  return Grader::ask(ve);
}
int main(int argc, char* argv[]){
  Grader::process_test();
}