#include<bits/stdc++.h>
#include "smatchlib.h"
using namespace std;
typedef long long ll;
string solve();
namespace KASJHDAOWD{
	void wrong_answer(string mess){
		cout << "-1 WA! " << mess << endl;
		exit(0);
	}
	double worst_score;
	ll f[205][1 << 13];
	int cnt_query, n, l, r, nxt[205][26];
	string s;
	ll dp(int p, int mask){
		if(mask == 0){
			return 1;
		}
		if(p == s.size()){
			return 0;
		}
		ll& ans = f[p][mask];
		if(ans != -1){
			return ans;
		}
		ans = 0;
		for(int i = 1; i < n; i++){
			if((mask >> i & 1) && nxt[p][i] != -1){
				ans += dp(nxt[p][i] + 1, mask ^ (1 << i));
			}
		}
		int pos = n - __builtin_popcount(mask) + 1;
		if(l <= pos && r >= pos && (mask & 1) && nxt[p][0] != -1){
			ans += dp(nxt[p][0] + 1, mask ^ 1);
		}
		return ans;
	}
	void calc_next(){
		fill(nxt[s.size()], nxt[s.size()] + 26, -1);
		for(int j = int(s.size()) - 1; j > -1; j--){
			for(int k = 0; k < 26; k++){
				nxt[j][k] = nxt[j + 1][k];
			}
			nxt[j][s[j] - 'a'] = j;
		}
	}
	ll ASDAJSLDJQWE(string _s){
		s = _s;
		calc_next();
		memset(f, -1, sizeof(f));
		return dp(0, (1 << n) - 1);
	}
	int AKSDOWIEQ(string _s){
		if(_s.size() > 200){
			wrong_answer("Query string length must be shorter than 200");
		}
		for(char& c : _s){
			if(c < 'a' || c > 'z'){
				wrong_answer("Must be lower case English letter");
			}
		}
		if(++cnt_query > 10){
			wrong_answer("Query limit exceed");
		}
		return ASDAJSLDJQWE(_s) % 379;
	}
	double score(int P, int J) {
    if (P <= J){
      return 1.0;
    }
    int diff = P - J;
    if(diff > n){
      return 0.4 * pow(0.9, diff - n - 1);
    }
    if(diff >= 4 && diff <= n){
      return 0.4 + 0.4 * pow(0.8, diff - 4);
    }
    return 0.8 + 0.2 * pow(0.8, diff);
	}
	int FLKAJSD[14][14][14];
	void process_test(){
		cnt_query = 0;
		cin >> n >> l >> r;
		string s = solve();
		ll real = 1;
		for(int i = 2; i < n; i++){
			real = ll(real) * i;
		}
		if(ASDAJSLDJQWE(s) != real * (r - l + 1)){
			wrong_answer("The number of string do not match");
		}
		worst_score = min(worst_score, score(cnt_query + s.size(), FLKAJSD[n][l][r]));
	}
	void init(){
		worst_score = 1.0;
		FLKAJSD[4][1][1] = 12;
		FLKAJSD[4][1][2] = 12;
		FLKAJSD[4][1][3] = 13;
		FLKAJSD[4][1][4] = 14;
		FLKAJSD[4][2][2] = 11;
		FLKAJSD[4][2][3] = 12;
		FLKAJSD[4][2][4] = 13;
		FLKAJSD[4][3][3] = 11;
		FLKAJSD[4][3][4] = 12;
		FLKAJSD[4][4][4] = 10;
		FLKAJSD[5][1][1] = 16;
		FLKAJSD[5][1][2] = 18;
		FLKAJSD[5][1][3] = 19;
		FLKAJSD[5][1][4] = 20;
		FLKAJSD[5][1][5] = 21;
		FLKAJSD[5][2][2] = 17;
		FLKAJSD[5][2][3] = 18;
		FLKAJSD[5][2][4] = 19;
		FLKAJSD[5][2][5] = 20;
		FLKAJSD[5][3][3] = 17;
		FLKAJSD[5][3][4] = 18;
		FLKAJSD[5][3][5] = 19;
		FLKAJSD[5][4][4] = 17;
		FLKAJSD[5][4][5] = 18;
		FLKAJSD[5][5][5] = 16;
		FLKAJSD[6][1][1] = 24;
		FLKAJSD[6][1][2] = 26;
		FLKAJSD[6][1][3] = 27;
		FLKAJSD[6][1][4] = 28;
		FLKAJSD[6][1][5] = 29;
		FLKAJSD[6][1][6] = 30;
		FLKAJSD[6][2][2] = 25;
		FLKAJSD[6][2][3] = 26;
		FLKAJSD[6][2][4] = 27;
		FLKAJSD[6][2][5] = 28;
		FLKAJSD[6][2][6] = 29;
		FLKAJSD[6][3][3] = 25;
		FLKAJSD[6][3][4] = 26;
		FLKAJSD[6][3][5] = 27;
		FLKAJSD[6][3][6] = 28;
		FLKAJSD[6][4][4] = 25;
		FLKAJSD[6][4][5] = 26;
		FLKAJSD[6][4][6] = 27;
		FLKAJSD[6][5][5] = 25;
		FLKAJSD[6][5][6] = 26;
		FLKAJSD[6][6][6] = 24;
		FLKAJSD[7][1][1] = 34;
		FLKAJSD[7][1][2] = 36;
		FLKAJSD[7][1][3] = 37;
		FLKAJSD[7][1][4] = 38;
		FLKAJSD[7][1][5] = 39;
		FLKAJSD[7][1][6] = 40;
		FLKAJSD[7][1][7] = 41;
		FLKAJSD[7][2][2] = 35;
		FLKAJSD[7][2][3] = 36;
		FLKAJSD[7][2][4] = 37;
		FLKAJSD[7][2][5] = 38;
		FLKAJSD[7][2][6] = 39;
		FLKAJSD[7][2][7] = 40;
		FLKAJSD[7][3][3] = 35;
		FLKAJSD[7][3][4] = 36;
		FLKAJSD[7][3][5] = 37;
		FLKAJSD[7][3][6] = 38;
		FLKAJSD[7][3][7] = 39;
		FLKAJSD[7][4][4] = 35;
		FLKAJSD[7][4][5] = 36;
		FLKAJSD[7][4][6] = 37;
		FLKAJSD[7][4][7] = 38;
		FLKAJSD[7][5][5] = 35;
		FLKAJSD[7][5][6] = 36;
		FLKAJSD[7][5][7] = 37;
		FLKAJSD[7][6][6] = 35;
		FLKAJSD[7][6][7] = 36;
		FLKAJSD[7][7][7] = 34;
		FLKAJSD[8][1][1] = 46;
		FLKAJSD[8][1][2] = 48;
		FLKAJSD[8][1][3] = 49;
		FLKAJSD[8][1][4] = 50;
		FLKAJSD[8][1][5] = 51;
		FLKAJSD[8][1][6] = 52;
		FLKAJSD[8][1][7] = 53;
		FLKAJSD[8][1][8] = 54;
		FLKAJSD[8][2][2] = 47;
		FLKAJSD[8][2][3] = 48;
		FLKAJSD[8][2][4] = 49;
		FLKAJSD[8][2][5] = 50;
		FLKAJSD[8][2][6] = 51;
		FLKAJSD[8][2][7] = 52;
		FLKAJSD[8][2][8] = 53;
		FLKAJSD[8][3][3] = 47;
		FLKAJSD[8][3][4] = 48;
		FLKAJSD[8][3][5] = 49;
		FLKAJSD[8][3][6] = 50;
		FLKAJSD[8][3][7] = 51;
		FLKAJSD[8][3][8] = 52;
		FLKAJSD[8][4][4] = 47;
		FLKAJSD[8][4][5] = 48;
		FLKAJSD[8][4][6] = 49;
		FLKAJSD[8][4][7] = 50;
		FLKAJSD[8][4][8] = 51;
		FLKAJSD[8][5][5] = 47;
		FLKAJSD[8][5][6] = 48;
		FLKAJSD[8][5][7] = 49;
		FLKAJSD[8][5][8] = 50;
		FLKAJSD[8][6][6] = 47;
		FLKAJSD[8][6][7] = 48;
		FLKAJSD[8][6][8] = 49;
		FLKAJSD[8][7][7] = 47;
		FLKAJSD[8][7][8] = 48;
		FLKAJSD[8][8][8] = 46;
		FLKAJSD[9][1][1] = 60;
		FLKAJSD[9][1][2] = 62;
		FLKAJSD[9][1][3] = 63;
		FLKAJSD[9][1][4] = 64;
		FLKAJSD[9][1][5] = 65;
		FLKAJSD[9][1][6] = 66;
		FLKAJSD[9][1][7] = 67;
		FLKAJSD[9][1][8] = 68;
		FLKAJSD[9][1][9] = 69;
		FLKAJSD[9][2][2] = 61;
		FLKAJSD[9][2][3] = 62;
		FLKAJSD[9][2][4] = 63;
		FLKAJSD[9][2][5] = 64;
		FLKAJSD[9][2][6] = 65;
		FLKAJSD[9][2][7] = 66;
		FLKAJSD[9][2][8] = 67;
		FLKAJSD[9][2][9] = 68;
		FLKAJSD[9][3][3] = 61;
		FLKAJSD[9][3][4] = 62;
		FLKAJSD[9][3][5] = 63;
		FLKAJSD[9][3][6] = 64;
		FLKAJSD[9][3][7] = 65;
		FLKAJSD[9][3][8] = 66;
		FLKAJSD[9][3][9] = 67;
		FLKAJSD[9][4][4] = 61;
		FLKAJSD[9][4][5] = 62;
		FLKAJSD[9][4][6] = 63;
		FLKAJSD[9][4][7] = 64;
		FLKAJSD[9][4][8] = 65;
		FLKAJSD[9][4][9] = 66;
		FLKAJSD[9][5][5] = 61;
		FLKAJSD[9][5][6] = 62;
		FLKAJSD[9][5][7] = 63;
		FLKAJSD[9][5][8] = 64;
		FLKAJSD[9][5][9] = 65;
		FLKAJSD[9][6][6] = 61;
		FLKAJSD[9][6][7] = 62;
		FLKAJSD[9][6][8] = 63;
		FLKAJSD[9][6][9] = 64;
		FLKAJSD[9][7][7] = 61;
		FLKAJSD[9][7][8] = 62;
		FLKAJSD[9][7][9] = 63;
		FLKAJSD[9][8][8] = 61;
		FLKAJSD[9][8][9] = 62;
		FLKAJSD[9][9][9] = 60;
		FLKAJSD[10][1][1] = 76;
		FLKAJSD[10][1][2] = 78;
		FLKAJSD[10][1][3] = 79;
		FLKAJSD[10][1][4] = 80;
		FLKAJSD[10][1][5] = 81;
		FLKAJSD[10][1][6] = 82;
		FLKAJSD[10][1][7] = 83;
		FLKAJSD[10][1][8] = 84;
		FLKAJSD[10][1][9] = 85;
		FLKAJSD[10][1][10] = 86;
		FLKAJSD[10][2][2] = 77;
		FLKAJSD[10][2][3] = 78;
		FLKAJSD[10][2][4] = 79;
		FLKAJSD[10][2][5] = 80;
		FLKAJSD[10][2][6] = 81;
		FLKAJSD[10][2][7] = 82;
		FLKAJSD[10][2][8] = 83;
		FLKAJSD[10][2][9] = 84;
		FLKAJSD[10][2][10] = 85;
		FLKAJSD[10][3][3] = 77;
		FLKAJSD[10][3][4] = 78;
		FLKAJSD[10][3][5] = 79;
		FLKAJSD[10][3][6] = 80;
		FLKAJSD[10][3][7] = 81;
		FLKAJSD[10][3][8] = 82;
		FLKAJSD[10][3][9] = 83;
		FLKAJSD[10][3][10] = 84;
		FLKAJSD[10][4][4] = 77;
		FLKAJSD[10][4][5] = 78;
		FLKAJSD[10][4][6] = 79;
		FLKAJSD[10][4][7] = 80;
		FLKAJSD[10][4][8] = 81;
		FLKAJSD[10][4][9] = 82;
		FLKAJSD[10][4][10] = 83;
		FLKAJSD[10][5][5] = 77;
		FLKAJSD[10][5][6] = 78;
		FLKAJSD[10][5][7] = 79;
		FLKAJSD[10][5][8] = 80;
		FLKAJSD[10][5][9] = 81;
		FLKAJSD[10][5][10] = 82;
		FLKAJSD[10][6][6] = 77;
		FLKAJSD[10][6][7] = 78;
		FLKAJSD[10][6][8] = 79;
		FLKAJSD[10][6][9] = 80;
		FLKAJSD[10][6][10] = 81;
		FLKAJSD[10][7][7] = 77;
		FLKAJSD[10][7][8] = 78;
		FLKAJSD[10][7][9] = 79;
		FLKAJSD[10][7][10] = 80;
		FLKAJSD[10][8][8] = 77;
		FLKAJSD[10][8][9] = 78;
		FLKAJSD[10][8][10] = 79;
		FLKAJSD[10][9][9] = 77;
		FLKAJSD[10][9][10] = 78;
		FLKAJSD[10][10][10] = 76;
		FLKAJSD[11][1][1] = 94;
		FLKAJSD[11][1][2] = 96;
		FLKAJSD[11][1][3] = 97;
		FLKAJSD[11][1][4] = 98;
		FLKAJSD[11][1][5] = 99;
		FLKAJSD[11][1][6] = 100;
		FLKAJSD[11][1][7] = 101;
		FLKAJSD[11][1][8] = 102;
		FLKAJSD[11][1][9] = 103;
		FLKAJSD[11][1][10] = 104;
		FLKAJSD[11][1][11] = 105;
		FLKAJSD[11][2][2] = 95;
		FLKAJSD[11][2][3] = 96;
		FLKAJSD[11][2][4] = 97;
		FLKAJSD[11][2][5] = 98;
		FLKAJSD[11][2][6] = 99;
		FLKAJSD[11][2][7] = 100;
		FLKAJSD[11][2][8] = 101;
		FLKAJSD[11][2][9] = 102;
		FLKAJSD[11][2][10] = 103;
		FLKAJSD[11][2][11] = 104;
		FLKAJSD[11][3][3] = 95;
		FLKAJSD[11][3][4] = 96;
		FLKAJSD[11][3][5] = 97;
		FLKAJSD[11][3][6] = 98;
		FLKAJSD[11][3][7] = 99;
		FLKAJSD[11][3][8] = 100;
		FLKAJSD[11][3][9] = 101;
		FLKAJSD[11][3][10] = 102;
		FLKAJSD[11][3][11] = 103;
		FLKAJSD[11][4][4] = 95;
		FLKAJSD[11][4][5] = 96;
		FLKAJSD[11][4][6] = 97;
		FLKAJSD[11][4][7] = 98;
		FLKAJSD[11][4][8] = 99;
		FLKAJSD[11][4][9] = 100;
		FLKAJSD[11][4][10] = 101;
		FLKAJSD[11][4][11] = 102;
		FLKAJSD[11][5][5] = 95;
		FLKAJSD[11][5][6] = 96;
		FLKAJSD[11][5][7] = 97;
		FLKAJSD[11][5][8] = 98;
		FLKAJSD[11][5][9] = 99;
		FLKAJSD[11][5][10] = 100;
		FLKAJSD[11][5][11] = 101;
		FLKAJSD[11][6][6] = 95;
		FLKAJSD[11][6][7] = 96;
		FLKAJSD[11][6][8] = 97;
		FLKAJSD[11][6][9] = 98;
		FLKAJSD[11][6][10] = 99;
		FLKAJSD[11][6][11] = 100;
		FLKAJSD[11][7][7] = 95;
		FLKAJSD[11][7][8] = 96;
		FLKAJSD[11][7][9] = 97;
		FLKAJSD[11][7][10] = 98;
		FLKAJSD[11][7][11] = 99;
		FLKAJSD[11][8][8] = 95;
		FLKAJSD[11][8][9] = 96;
		FLKAJSD[11][8][10] = 97;
		FLKAJSD[11][8][11] = 98;
		FLKAJSD[11][9][9] = 95;
		FLKAJSD[11][9][10] = 96;
		FLKAJSD[11][9][11] = 97;
		FLKAJSD[11][10][10] = 95;
		FLKAJSD[11][10][11] = 96;
		FLKAJSD[11][11][11] = 94;
		FLKAJSD[12][1][1] = 114;
		FLKAJSD[12][1][2] = 116;
		FLKAJSD[12][1][3] = 117;
		FLKAJSD[12][1][4] = 118;
		FLKAJSD[12][1][5] = 119;
		FLKAJSD[12][1][6] = 120;
		FLKAJSD[12][1][7] = 121;
		FLKAJSD[12][1][8] = 122;
		FLKAJSD[12][1][9] = 123;
		FLKAJSD[12][1][10] = 124;
		FLKAJSD[12][1][11] = 125;
		FLKAJSD[12][1][12] = 126;
		FLKAJSD[12][2][2] = 115;
		FLKAJSD[12][2][3] = 116;
		FLKAJSD[12][2][4] = 117;
		FLKAJSD[12][2][5] = 118;
		FLKAJSD[12][2][6] = 119;
		FLKAJSD[12][2][7] = 120;
		FLKAJSD[12][2][8] = 121;
		FLKAJSD[12][2][9] = 122;
		FLKAJSD[12][2][10] = 123;
		FLKAJSD[12][2][11] = 124;
		FLKAJSD[12][2][12] = 125;
		FLKAJSD[12][3][3] = 115;
		FLKAJSD[12][3][4] = 116;
		FLKAJSD[12][3][5] = 117;
		FLKAJSD[12][3][6] = 118;
		FLKAJSD[12][3][7] = 119;
		FLKAJSD[12][3][8] = 120;
		FLKAJSD[12][3][9] = 121;
		FLKAJSD[12][3][10] = 122;
		FLKAJSD[12][3][11] = 123;
		FLKAJSD[12][3][12] = 124;
		FLKAJSD[12][4][4] = 115;
		FLKAJSD[12][4][5] = 116;
		FLKAJSD[12][4][6] = 117;
		FLKAJSD[12][4][7] = 118;
		FLKAJSD[12][4][8] = 119;
		FLKAJSD[12][4][9] = 120;
		FLKAJSD[12][4][10] = 121;
		FLKAJSD[12][4][11] = 122;
		FLKAJSD[12][4][12] = 123;
		FLKAJSD[12][5][5] = 115;
		FLKAJSD[12][5][6] = 116;
		FLKAJSD[12][5][7] = 117;
		FLKAJSD[12][5][8] = 118;
		FLKAJSD[12][5][9] = 119;
		FLKAJSD[12][5][10] = 120;
		FLKAJSD[12][5][11] = 121;
		FLKAJSD[12][5][12] = 122;
		FLKAJSD[12][6][6] = 115;
		FLKAJSD[12][6][7] = 116;
		FLKAJSD[12][6][8] = 117;
		FLKAJSD[12][6][9] = 118;
		FLKAJSD[12][6][10] = 119;
		FLKAJSD[12][6][11] = 120;
		FLKAJSD[12][6][12] = 121;
		FLKAJSD[12][7][7] = 115;
		FLKAJSD[12][7][8] = 116;
		FLKAJSD[12][7][9] = 117;
		FLKAJSD[12][7][10] = 118;
		FLKAJSD[12][7][11] = 119;
		FLKAJSD[12][7][12] = 120;
		FLKAJSD[12][8][8] = 115;
		FLKAJSD[12][8][9] = 116;
		FLKAJSD[12][8][10] = 117;
		FLKAJSD[12][8][11] = 118;
		FLKAJSD[12][8][12] = 119;
		FLKAJSD[12][9][9] = 115;
		FLKAJSD[12][9][10] = 116;
		FLKAJSD[12][9][11] = 117;
		FLKAJSD[12][9][12] = 118;
		FLKAJSD[12][10][10] = 115;
		FLKAJSD[12][10][11] = 116;
		FLKAJSD[12][10][12] = 117;
		FLKAJSD[12][11][11] = 115;
		FLKAJSD[12][11][12] = 116;
		FLKAJSD[12][12][12] = 114;
		FLKAJSD[13][1][1] = 136;
		FLKAJSD[13][1][2] = 138;
		FLKAJSD[13][1][3] = 139;
		FLKAJSD[13][1][4] = 140;
		FLKAJSD[13][1][5] = 141;
		FLKAJSD[13][1][6] = 142;
		FLKAJSD[13][1][7] = 143;
		FLKAJSD[13][1][8] = 144;
		FLKAJSD[13][1][9] = 145;
		FLKAJSD[13][1][10] = 146;
		FLKAJSD[13][1][11] = 147;
		FLKAJSD[13][1][12] = 148;
		FLKAJSD[13][1][13] = 148;
		FLKAJSD[13][2][2] = 137;
		FLKAJSD[13][2][3] = 138;
		FLKAJSD[13][2][4] = 139;
		FLKAJSD[13][2][5] = 140;
		FLKAJSD[13][2][6] = 141;
		FLKAJSD[13][2][7] = 142;
		FLKAJSD[13][2][8] = 143;
		FLKAJSD[13][2][9] = 144;
		FLKAJSD[13][2][10] = 145;
		FLKAJSD[13][2][11] = 146;
		FLKAJSD[13][2][12] = 147;
		FLKAJSD[13][2][13] = 148;
		FLKAJSD[13][3][3] = 137;
		FLKAJSD[13][3][4] = 138;
		FLKAJSD[13][3][5] = 139;
		FLKAJSD[13][3][6] = 140;
		FLKAJSD[13][3][7] = 141;
		FLKAJSD[13][3][8] = 142;
		FLKAJSD[13][3][9] = 143;
		FLKAJSD[13][3][10] = 144;
		FLKAJSD[13][3][11] = 145;
		FLKAJSD[13][3][12] = 146;
		FLKAJSD[13][3][13] = 147;
		FLKAJSD[13][4][4] = 137;
		FLKAJSD[13][4][5] = 138;
		FLKAJSD[13][4][6] = 139;
		FLKAJSD[13][4][7] = 140;
		FLKAJSD[13][4][8] = 141;
		FLKAJSD[13][4][9] = 142;
		FLKAJSD[13][4][10] = 143;
		FLKAJSD[13][4][11] = 144;
		FLKAJSD[13][4][12] = 145;
		FLKAJSD[13][4][13] = 146;
		FLKAJSD[13][5][5] = 137;
		FLKAJSD[13][5][6] = 138;
		FLKAJSD[13][5][7] = 139;
		FLKAJSD[13][5][8] = 140;
		FLKAJSD[13][5][9] = 141;
		FLKAJSD[13][5][10] = 142;
		FLKAJSD[13][5][11] = 143;
		FLKAJSD[13][5][12] = 144;
		FLKAJSD[13][5][13] = 145;
		FLKAJSD[13][6][6] = 137;
		FLKAJSD[13][6][7] = 138;
		FLKAJSD[13][6][8] = 139;
		FLKAJSD[13][6][9] = 140;
		FLKAJSD[13][6][10] = 141;
		FLKAJSD[13][6][11] = 142;
		FLKAJSD[13][6][12] = 143;
		FLKAJSD[13][6][13] = 144;
		FLKAJSD[13][7][7] = 137;
		FLKAJSD[13][7][8] = 138;
		FLKAJSD[13][7][9] = 139;
		FLKAJSD[13][7][10] = 140;
		FLKAJSD[13][7][11] = 141;
		FLKAJSD[13][7][12] = 142;
		FLKAJSD[13][7][13] = 143;
		FLKAJSD[13][8][8] = 137;
		FLKAJSD[13][8][9] = 138;
		FLKAJSD[13][8][10] = 139;
		FLKAJSD[13][8][11] = 140;
		FLKAJSD[13][8][12] = 141;
		FLKAJSD[13][8][13] = 142;
		FLKAJSD[13][9][9] = 137;
		FLKAJSD[13][9][10] = 138;
		FLKAJSD[13][9][11] = 139;
		FLKAJSD[13][9][12] = 140;
		FLKAJSD[13][9][13] = 141;
		FLKAJSD[13][10][10] = 137;
		FLKAJSD[13][10][11] = 138;
		FLKAJSD[13][10][12] = 139;
		FLKAJSD[13][10][13] = 140;
		FLKAJSD[13][11][11] = 137;
		FLKAJSD[13][11][12] = 138;
		FLKAJSD[13][11][13] = 139;
		FLKAJSD[13][12][12] = 137;
		FLKAJSD[13][12][13] = 138;
		FLKAJSD[13][13][13] = 136;
	}
}
int ask(string s){
	return KASJHDAOWD::AKSDOWIEQ(s);
}
int main(int argc, char* argv[]){
	KASJHDAOWD::init();
	int _t, foo;
	cin >> _t >> foo >> foo;
	for(int _ = 0; _ < _t; _++){
		KASJHDAOWD::process_test();
	}
	cout << KASJHDAOWD::worst_score << " OK";
}