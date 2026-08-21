#include<bits/stdc++.h>
#include "smatchlib.h"
using namespace std;
const int mod = 397;
int gt[14];
void init(){
	for(int i = gt[0] = 1; i < 14; i++){
		gt[i] = gt[i - 1] * i % mod;
	}
}
string solve(){
	init();
	int low = 4, high = 13, n;
	while(low <= high){
		int mid = (low + high) >> 1;
		string s = "";
		for(int i = 0; i < mid; i++){
			for(int j = 0; j < mid; j++){
				s += char('a' + j);
			}
		}
		int x = ask(s);
		if(x == 0){
			low = mid + 1;
		}
		else{
			high = (n = mid) - 1;
		}
	}	
	string ans = "";
	for(int i = 1; i < n; i++){
		for(int j = 0; j < n; j++){
			ans += char('a' + j);
		}
	}
	return ans + 'a';
}
