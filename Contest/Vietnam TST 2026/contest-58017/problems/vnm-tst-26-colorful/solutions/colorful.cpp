#include<bits/stdc++.h>
#include "colorfullib.h"
using namespace std;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
vector<int>solve(int n){
  vector<int>small = {0}, large, perm(n - 1);
  iota(perm.begin(), perm.end(), 1);
  shuffle(perm.begin(), perm.end(), rng);
  for(int& i : perm){
    small.push_back(i);
    if(ask(small)){
      small.pop_back();
      large.push_back(i);
    }
  }
  vector<int>cut_point = {small.size()}; 
  for(int ptr = 0; true; ){
    int low = 1, high = cut_point.back() - 1, next_cut = 0;
    while(low <= high){
      int mid = (low + high) >> 1;
      vector<int>p(small.begin(), small.begin() + mid); 
      p.insert(p.end(), large.begin(), large.begin() + ptr + 1);
      if(ask(p)){
        high = mid - 1;
      }
      else{
        low = (next_cut = mid) + 1;
      }
    }
    cut_point.push_back(next_cut);
    if(next_cut == 0){
      break;
    }
    vector<int>p(small.begin(), small.begin() + next_cut);
    p.insert(p.end(), large.begin(), large.begin() + ptr + 1);
    do{
      p.push_back(large[++ptr]);
    } while(!ask(p));
  }
  reverse(cut_point.begin(), cut_point.end());
  vector<vector<int>>part(1, vector<int>(1, large.back()));
  large.pop_back();
  for(int& i : large){
    int low = 0, high = min(int(cut_point.size()) - 2, int(part.size()) - 1), pos = 0;
    while(low <= high){
      int mid = (low + high) >> 1;
      vector<int>p(1, i);
      for(int j = 0; j <= mid; j++){
        p.push_back(part[j][0]);
      }
      p.insert(p.end(), small.begin(), small.begin() + cut_point[int(cut_point.size()) - mid - 2]);
      if(ask(p)){
        low = pos = mid + 1;
      }
      else{
        high = mid - 1;
      }
    }
    if(pos == min(int(cut_point.size()) - 1, int(part.size()))){
      while(pos < part.size()){
        vector<int>p(small.begin(), small.begin() + cut_point[int(cut_point.size()) - 2]);
        p.push_back(part[pos][0]);
        p.push_back(i);
        if(!ask(p)){
          break;
        }
        pos++;
      }
    }
    if(pos == part.size()){
      part.push_back(vector<int>());
    }
    part[pos].push_back(i);
  }
  int large_color = part.size();
  vector<int>ans(n);
  for(int i = 0; i < large_color; i++){
    for(int& j : part[i]){
      ans[j] = i;
    }
  }
  vector<vector<int>>new_part(1, vector<int>(1, small.back()));
  small.pop_back();
  for(int& i : small){
    int low = 0, high = int(new_part.size()) - 1, pos = 0;
    while(low <= high){
      int mid = (low + high) >> 1;
      vector<int>p(1, i);
      for(int j = 0; j <= mid; j++){
        p.push_back(new_part[j][0]);
      }
      for(int j = int(cut_point.size()) - mid - 2; j > 0; ){
        p.push_back(part[--j][0]);
      }
      if(ask(p)){
        low = pos = mid + 1;
      }
      else{
        high = mid - 1;
      }
    }
    if(pos == new_part.size()){
      new_part.push_back(vector<int>());
    }
    new_part[pos].push_back(i);
  }
  for(int i = 0; i < new_part.size(); i++){
    for(int& j : new_part[i]){
      ans[j] = i + large_color;
    }
  }
  return ans;
}