#include<bits/stdc++.h>
#include "colorfullib.h"
using namespace std;

namespace ZXQWERTYUIOP{
  int qwe, asd, zxc, vbn;
  vector<int>poi;

  void boom(string msg){
    cout << "-1 WA! " << msg << endl;
    exit(0);
  }

  void start(){
    vbn = 0;
  }

  bool ping(vector<int>arr){
    vector<bool>chk(qwe, false);
    for(int& lol : arr){
      if(lol < 0 || lol >= qwe || chk[lol]){
        boom("Wrong asking format");
      }
      chk[lol] = true;
    }

    zxc++;

    vector<bool>flag(asd, false);
    for(int& lol : arr){
      flag[poi[lol]] = true;
    }

    return count(flag.begin(), flag.end(), true) >= ((asd + 1) >> 1);
  }

  double calc(){
    if(vbn > 14000){
      return 0;
    }
    return 1400.0 / double(max(vbn, 1400));
  }

  void run(){
    zxc = 0;
    cin >> qwe >> asd;
    poi.resize(qwe);

    for(int i = 0; i < qwe; i++){
      cin >> poi[i];
    }

    vector<int>res = solve(qwe);

    if((int)res.size() != qwe){
      boom("Size does not match");
    }

    for(int& lol : res){
      if(lol < -1 || lol >= asd){
        boom("Color out of bound");
      }
    }

    for(int i = 0; i < qwe; i++){
      for(int j = i + 1; j < qwe; j++){
        if((poi[i] == poi[j] && res[i] != res[j]) || 
           (poi[i] != poi[j] && res[i] == res[j])){
          boom("Wrong answer");
        }
      }
    }

    vbn = max(vbn, zxc);
  }
}

bool ask(vector<int>arr){
  return ZXQWERTYUIOP::ping(arr);
}

int main(int argc, char* argv[]){
  ZXQWERTYUIOP::start();

  int ttt;
  cin >> ttt;

  for(int i = 0; i < ttt; i++){
    ZXQWERTYUIOP::run();
  }

  cout << ZXQWERTYUIOP::calc() << " OK";
}