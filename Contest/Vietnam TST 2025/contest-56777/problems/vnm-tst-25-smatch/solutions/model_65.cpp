#include<bits/stdc++.h>
#include "smatchlib.h"
using namespace std;
const int mod = 379;
int gt[14];
void init(){
	for(int i = gt[0] = 1; i < 14; i++){
		gt[i] = gt[i - 1] * i % mod;
	}
}
string solve(){
	init();
	string s = "";
	for(int i = 1; i < 13; i++){
		for(int j = 0; j < 13; j++){
			s += char('a' + j);
		}
	}
	int n, lr_len, x = ask(s + 'a');
	if(x == 12){
		lr_len = ((n = (ask("abcdabcdabcda") == 0 ? 11 : 4)) == 4 ? 2 : 9);
	}
	else if(x == gt[13]){
		n = lr_len = 13;
	}
	else{
		for(int i = 3; i < 13; i++){
			for(int j = 1; j <= i; j++){
				if(x == gt[i] * j % mod){
					if(j == 1){
						s = "";
						for(int k = 0; k < i; k++){
							for(int t = 0; t < i; t++){
								s += char('a' + t);
							}
						}
						lr_len = ((n = i + int(ask(s) == 0)) == i ? i : 1);
					}
					else{
						n = i + 1;
						lr_len = j;
					}
					i = 13;
					break;
				}
			}
		}
	}
	if(n == 13 && lr_len > 7){
		string ans = "";
		for(int i = 1; i < n; i++){
			for(int j = 0; j < n; j++){
				ans += char('a' + j);
			}
		}	
		return ans + 'a';
	}
	int l = 1;
	for(int i = 3; i > -1; i--){
		int nl = l + (1 << i);
		if(nl <= n - lr_len + 1){
			string s = "";
			for(int j = 1; j < n; j++){
				for(int t = int(j < nl); t < n; t++){
					s += char('a' + t);
				}
			}
			s += 'a';
			if(ask(s) == x){
				l = nl;
			}
		}
	}
	int r = l + lr_len - 1;
	string ans = "";
	bool z = false;
	if(l - 1 < n - r){
		int L = l - 1, R = n - r;
		l = R + 1;
		r = n - L;
		z = true;
	}
	for(int i = 1; i < l; i++){
		if(i == 1){
			for(int j = 1; j < n; j++){
				ans += char('a' + j);
			}
		}
		else if(i & 1){
			for(int j = 2; j < n; j++){
				ans += char('a' + j);
			}
		}
		else{
			for(int j = n - 2; j > 0; j--){
				ans += char('a' + j);
			}
		}
	}
	if(r == n){
		for(int i = l; i < r; i++){
			for(int j = 0; j < n; j++){
				ans += char('a' + j);
			}
		}
		ans += 'a';
	}
	else{
		for(int i = l; i <= r; i++){
			for(int j = 0; j < n; j++){
				ans += char('a' + j);
			}
		}
		for(int i = r + 1; i < n; i++){
			for(int j = 1; j < n; j++){
				ans += char('a' + j);
			}
		}
	}
	if(z){
		reverse(ans.begin(), ans.end());
	}
	return ans;
}
