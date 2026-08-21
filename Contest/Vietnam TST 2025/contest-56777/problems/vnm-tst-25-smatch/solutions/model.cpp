#include<bits/stdc++.h>
#include "smatchlib.h"
using namespace std;
const int mod = 379;
const string CANDIDATE[] = {"", "", "", "", "bdccaaacbddba", "eaaeabbddecdbccdbaeac", "efdacaffafdbabdcbccebeebcedfaad", "cfcbefbedadecaaecfgabgbabgaeddgadegfbdfgcfc", "bahedahacbfgadhhdgcbggcecaghfecfabfddgebabfaghdfecbfeedch", "fhdffebgifiihghaddhdgecehchfgabgceciiggaafeddahhiabcaedaeicbfcbcibdagefbb", "bjebbaahjdcfhhhgjiebabffgbbacghfichcfihfehdcjdjefibjaeggfcdaeieaigjcdifdeijdaggcjhdeibacgda", "jbhegagekhfjcajhgijggdgabkeebaghdigijeiabkhckbcckkbdkiihfdeedchafkkbkcfejdjbbfaciahecgbahfcffaiaifhdgjidjjdefcd", "cceijjkbdieagbicecgigekjecfajldebjhigkibfefkhgaflaeehbhgdgbadlkhabedakagdjcfabihldcabedlfklbafflhigilgialjkjcchklicjdhdbjkkjcfhldfhfg", "emelklgeidagcgjkceagaacjjlachbeillgbcalmbldcdhdijgkigcjekkahkmbfmhcdjabkkjdfddehemiimeefhhklfdefihjimafilbfbgkbfmcgcbgilmaemcakljdhgbddmcghhlmaffiajijfhbfjkb"};
const string EDGE_CANDIDATE = "bdccaaacbddbahjjifkjegeihhigfgfkek";
int gt[14], mod_value[14][14][14];
void init(){
	for(int i = gt[0] = 1; i < 14; i++){
		gt[i] = gt[i - 1] * i % mod;
	}
	mod_value[4][1][1] = 2;
	mod_value[4][3][3] = 3;
	mod_value[4][2][2] = 4;
	mod_value[4][4][4] = 5;
	mod_value[4][1][2] = 6;
	mod_value[4][2][3] = 7;
	mod_value[4][3][4] = 8;
	mod_value[4][1][3] = 9;
	mod_value[4][2][4] = 12;
	mod_value[4][1][4] = 14;
	mod_value[5][3][3] = 2;
	mod_value[5][2][2] = 6;
	mod_value[5][2][3] = 8;
	mod_value[5][4][4] = 12;
	mod_value[5][3][4] = 14;
	mod_value[5][5][5] = 17;
	mod_value[5][1][1] = 18;
	mod_value[5][2][4] = 20;
	mod_value[5][1][2] = 24;
	mod_value[5][1][3] = 26;
	mod_value[5][4][5] = 29;
	mod_value[5][3][5] = 31;
	mod_value[5][2][5] = 37;
	mod_value[5][1][4] = 38;
	mod_value[5][1][5] = 55;
	mod_value[6][5][5] = 28;
	mod_value[6][4][4] = 34;
	mod_value[6][1][1] = 37;
	mod_value[6][3][3] = 54;
	mod_value[6][6][6] = 58;
	mod_value[6][2][2] = 60;
	mod_value[6][4][5] = 62;
	mod_value[6][5][6] = 86;
	mod_value[6][3][4] = 88;
	mod_value[6][1][2] = 97;
	mod_value[6][2][3] = 114;
	mod_value[6][3][5] = 116;
	mod_value[6][4][6] = 120;
	mod_value[6][2][4] = 148;
	mod_value[6][1][3] = 151;
	mod_value[6][3][6] = 174;
	mod_value[6][2][5] = 176;
	mod_value[6][1][4] = 185;
	mod_value[6][1][5] = 213;
	mod_value[6][2][6] = 234;
	mod_value[6][1][6] = 271;
	mod_value[7][1][7] = 68;
	mod_value[7][1][5] = 79;
	mod_value[7][2][6] = 106;
	mod_value[7][1][4] = 125;
	mod_value[7][7][7] = 128;
	mod_value[7][1][3] = 133;
	mod_value[7][1][2] = 143;
	mod_value[7][3][6] = 176;
	mod_value[7][4][6] = 186;
	mod_value[7][5][6] = 194;
	mod_value[7][1][1] = 213;
	mod_value[7][2][7] = 234;
	mod_value[7][6][6] = 240;
	mod_value[7][2][5] = 245;
	mod_value[7][2][4] = 291;
	mod_value[7][2][3] = 299;
	mod_value[7][3][7] = 304;
	mod_value[7][2][2] = 309;
	mod_value[7][4][7] = 314;
	mod_value[7][3][5] = 315;
	mod_value[7][1][6] = 319;
	mod_value[7][5][7] = 322;
	mod_value[7][4][5] = 325;
	mod_value[7][5][5] = 333;
	mod_value[7][3][4] = 361;
	mod_value[7][6][7] = 368;
	mod_value[7][3][3] = 369;
	mod_value[7][4][4] = 371;
	mod_value[8][7][7] = 4;
	mod_value[8][2][5] = 14;
	mod_value[8][4][6] = 29;
	mod_value[8][4][7] = 33;
	mod_value[8][3][3] = 56;
	mod_value[8][5][5] = 59;
	mod_value[8][6][8] = 60;
	mod_value[8][4][4] = 64;
	mod_value[8][2][8] = 74;
	mod_value[8][3][6] = 85;
	mod_value[8][3][7] = 89;
	mod_value[8][5][8] = 119;
	mod_value[8][3][4] = 120;
	mod_value[8][1][2] = 121;
	mod_value[8][4][5] = 123;
	mod_value[8][8][8] = 150;
	mod_value[8][7][8] = 154;
	mod_value[8][1][3] = 177;
	mod_value[8][3][5] = 179;
	mod_value[8][4][8] = 183;
	mod_value[8][1][6] = 206;
	mod_value[8][1][7] = 210;
	mod_value[8][2][2] = 214;
	mod_value[8][3][8] = 239;
	mod_value[8][1][4] = 241;
	mod_value[8][2][3] = 270;
	mod_value[8][6][6] = 285;
	mod_value[8][1][1] = 286;
	mod_value[8][6][7] = 289;
	mod_value[8][2][6] = 299;
	mod_value[8][1][5] = 300;
	mod_value[8][2][7] = 303;
	mod_value[8][2][4] = 334;
	mod_value[8][5][6] = 344;
	mod_value[8][5][7] = 348;
	mod_value[8][1][8] = 360;
	mod_value[9][2][4] = 4;
	mod_value[9][5][6] = 7;
	mod_value[9][2][6] = 11;
	mod_value[9][1][8] = 21;
	mod_value[9][4][9] = 23;
	mod_value[9][2][3] = 29;
	mod_value[9][3][7] = 34;
	mod_value[9][1][5] = 35;
	mod_value[9][7][9] = 41;
	mod_value[9][4][8] = 47;
	mod_value[9][5][9] = 48;
	mod_value[9][2][9] = 52;
	mod_value[9][4][5] = 61;
	mod_value[9][7][8] = 65;
	mod_value[9][5][8] = 72;
	mod_value[9][2][8] = 76;
	mod_value[9][5][5] = 86;
	mod_value[9][2][5] = 90;
	mod_value[9][3][4] = 91;
	mod_value[9][3][6] = 98;
	mod_value[9][8][9] = 105;
	mod_value[9][3][3] = 116;
	mod_value[9][8][8] = 129;
	mod_value[9][3][9] = 139;
	mod_value[9][3][8] = 163;
	mod_value[9][3][5] = 177;
	mod_value[9][6][7] = 236;
	mod_value[9][1][2] = 237;
	mod_value[9][1][7] = 271;
	mod_value[9][2][2] = 292;
	mod_value[9][4][7] = 297;
	mod_value[9][6][6] = 300;
	mod_value[9][7][7] = 315;
	mod_value[9][5][7] = 322;
	mod_value[9][1][1] = 324;
	mod_value[9][2][7] = 326;
	mod_value[9][1][4] = 328;
	mod_value[9][1][6] = 335;
	mod_value[9][6][9] = 341;
	mod_value[9][1][3] = 353;
	mod_value[9][4][4] = 354;
	mod_value[9][9][9] = 355;
	mod_value[9][4][6] = 361;
	mod_value[9][6][8] = 365;
	mod_value[9][1][9] = 376;
	mod_value[10][2][5] = 5;
	mod_value[10][5][10] = 6;
	mod_value[10][1][8] = 11;
	mod_value[10][1][3] = 16;
	mod_value[10][8][8] = 20;
	mod_value[10][3][9] = 47;
	mod_value[10][3][7] = 51;
	mod_value[10][5][9] = 55;
	mod_value[10][5][7] = 59;
	mod_value[10][7][10] = 70;
	mod_value[10][3][8] = 71;
	mod_value[10][3][3] = 76;
	mod_value[10][5][8] = 79;
	mod_value[10][4][5] = 97;
	mod_value[10][1][1] = 108;
	mod_value[10][1][5] = 113;
	mod_value[10][7][9] = 119;
	mod_value[10][7][7] = 123;
	mod_value[10][6][6] = 134;
	mod_value[10][2][6] = 139;
	mod_value[10][7][8] = 143;
	mod_value[10][3][5] = 173;
	mod_value[10][5][5] = 181;
	mod_value[10][2][4] = 203;
	mod_value[10][6][10] = 204;
	mod_value[10][2][10] = 209;
	mod_value[10][2][2] = 211;
	mod_value[10][4][6] = 231;
	mod_value[10][1][6] = 247;
	mod_value[10][6][9] = 253;
	mod_value[10][6][7] = 257;
	mod_value[10][2][9] = 258;
	mod_value[10][2][7] = 262;
	mod_value[10][6][8] = 277;
	mod_value[10][2][8] = 282;
	mod_value[10][2][3] = 287;
	mod_value[10][4][4] = 295;
	mod_value[10][4][10] = 301;
	mod_value[10][9][10] = 306;
	mod_value[10][3][6] = 307;
	mod_value[10][1][4] = 311;
	mod_value[10][5][6] = 315;
	mod_value[10][1][10] = 317;
	mod_value[10][1][2] = 319;
	mod_value[10][8][10] = 326;
	mod_value[10][10][10] = 330;
	mod_value[10][4][9] = 350;
	mod_value[10][4][7] = 354;
	mod_value[10][9][9] = 355;
	mod_value[10][1][9] = 366;
	mod_value[10][1][7] = 370;
	mod_value[10][3][4] = 371;
	mod_value[10][4][8] = 374;
	mod_value[10][8][9] = 375;
	mod_value[10][3][10] = 377;
	mod_value[11][11][11] = 4;
	mod_value[11][4][4] = 8;
	mod_value[11][5][10] = 12;
	mod_value[11][5][11] = 16;
	mod_value[11][4][10] = 20;
	mod_value[11][4][11] = 24;
	mod_value[11][1][9] = 25;
	mod_value[11][2][5] = 30;
	mod_value[11][8][10] = 35;
	mod_value[11][8][11] = 39;
	mod_value[11][3][8] = 48;
	mod_value[11][1][7] = 56;
	mod_value[11][5][5] = 64;
	mod_value[11][10][10] = 66;
	mod_value[11][2][2] = 68;
	mod_value[11][10][11] = 70;
	mod_value[11][1][3] = 71;
	mod_value[11][4][5] = 72;
	mod_value[11][1][4] = 79;
	mod_value[11][6][8] = 86;
	mod_value[11][1][10] = 91;
	mod_value[11][1][11] = 95;
	mod_value[11][7][9] = 106;
	mod_value[11][1][1] = 113;
	mod_value[11][2][8] = 116;
	mod_value[11][3][6] = 117;
	mod_value[11][7][7] = 137;
	mod_value[11][1][5] = 143;
	mod_value[11][5][8] = 150;
	mod_value[11][6][6] = 155;
	mod_value[11][4][8] = 158;
	mod_value[11][7][10] = 172;
	mod_value[11][8][8] = 173;
	mod_value[11][9][9] = 175;
	mod_value[11][7][11] = 176;
	mod_value[11][1][2] = 181;
	mod_value[11][2][6] = 185;
	mod_value[11][5][6] = 219;
	mod_value[11][3][9] = 223;
	mod_value[11][4][6] = 227;
	mod_value[11][1][8] = 229;
	mod_value[11][9][10] = 241;
	mod_value[11][9][11] = 245;
	mod_value[11][3][7] = 254;
	mod_value[11][6][9] = 261;
	mod_value[11][3][3] = 269;
	mod_value[11][3][4] = 277;
	mod_value[11][3][10] = 289;
	mod_value[11][2][9] = 291;
	mod_value[11][6][7] = 292;
	mod_value[11][3][11] = 293;
	mod_value[11][1][6] = 298;
	mod_value[11][7][8] = 310;
	mod_value[11][2][7] = 322;
	mod_value[11][5][9] = 325;
	mod_value[11][6][10] = 327;
	mod_value[11][6][11] = 331;
	mod_value[11][4][9] = 333;
	mod_value[11][2][3] = 337;
	mod_value[11][3][5] = 341;
	mod_value[11][2][4] = 345;
	mod_value[11][8][9] = 348;
	mod_value[11][5][7] = 356;
	mod_value[11][2][10] = 357;
	mod_value[11][2][11] = 361;
	mod_value[11][4][7] = 364;
	mod_value[12][8][8] = 2;
	mod_value[12][1][11] = 3;
	mod_value[12][2][10] = 9;
	mod_value[12][6][11] = 19;
	mod_value[12][12][12] = 21;
	mod_value[12][1][12] = 24;
	mod_value[12][4][6] = 33;
	mod_value[12][5][6] = 37;
	mod_value[12][6][12] = 40;
	mod_value[12][1][7] = 48;
	mod_value[12][1][8] = 50;
	mod_value[12][7][10] = 53;
	mod_value[12][9][9] = 60;
	mod_value[12][8][9] = 62;
	mod_value[12][6][7] = 64;
	mod_value[12][6][8] = 66;
	mod_value[12][3][4] = 77;
	mod_value[12][3][3] = 81;
	mod_value[12][2][5] = 84;
	mod_value[12][4][10] = 86;
	mod_value[12][5][10] = 90;
	mod_value[12][11][11] = 94;
	mod_value[12][2][11] = 103;
	mod_value[12][1][9] = 110;
	mod_value[12][3][6] = 114;
	mod_value[12][11][12] = 115;
	mod_value[12][1][2] = 121;
	mod_value[12][2][12] = 124;
	mod_value[12][6][9] = 126;
	mod_value[12][7][11] = 147;
	mod_value[12][2][7] = 148;
	mod_value[12][2][8] = 150;
	mod_value[12][4][5] = 161;
	mod_value[12][5][5] = 165;
	mod_value[12][3][10] = 167;
	mod_value[12][7][12] = 168;
	mod_value[12][10][10] = 178;
	mod_value[12][4][11] = 180;
	mod_value[12][5][11] = 184;
	mod_value[12][7][7] = 192;
	mod_value[12][7][8] = 194;
	mod_value[12][1][4] = 198;
	mod_value[12][4][12] = 201;
	mod_value[12][1][3] = 202;
	mod_value[12][5][12] = 205;
	mod_value[12][2][9] = 210;
	mod_value[12][2][2] = 221;
	mod_value[12][4][7] = 225;
	mod_value[12][4][8] = 227;
	mod_value[12][5][7] = 229;
	mod_value[12][5][8] = 231;
	mod_value[12][1][6] = 235;
	mod_value[12][9][10] = 238;
	mod_value[12][8][10] = 240;
	mod_value[12][3][5] = 242;
	mod_value[12][6][6] = 251;
	mod_value[12][7][9] = 254;
	mod_value[12][3][11] = 261;
	mod_value[12][10][11] = 272;
	mod_value[12][1][1] = 279;
	mod_value[12][3][12] = 282;
	mod_value[12][4][9] = 287;
	mod_value[12][1][10] = 288;
	mod_value[12][5][9] = 291;
	mod_value[12][10][12] = 293;
	mod_value[12][2][4] = 298;
	mod_value[12][2][3] = 302;
	mod_value[12][6][10] = 304;
	mod_value[12][3][7] = 306;
	mod_value[12][3][8] = 308;
	mod_value[12][9][11] = 332;
	mod_value[12][8][11] = 334;
	mod_value[12][2][6] = 335;
	mod_value[12][9][12] = 353;
	mod_value[12][8][12] = 355;
	mod_value[12][1][5] = 363;
	mod_value[12][3][9] = 368;
	mod_value[12][4][4] = 375;
	mod_value[13][12][12] = 1;
	mod_value[13][1][5] = 5;
	mod_value[13][4][7] = 6;
	mod_value[13][6][8] = 31;
	mod_value[13][1][8] = 36;
	mod_value[13][7][11] = 38;
	mod_value[13][7][12] = 39;
	mod_value[13][5][13] = 42;
	mod_value[13][2][9] = 43;
	mod_value[13][5][7] = 54;
	mod_value[13][11][11] = 55;
	mod_value[13][11][12] = 56;
	mod_value[13][2][2] = 62;
	mod_value[13][4][5] = 63;
	mod_value[13][13][13] = 64;
	mod_value[13][12][13] = 65;
	mod_value[13][3][10] = 66;
	mod_value[13][1][1] = 67;
	mod_value[13][9][9] = 74;
	mod_value[13][3][6] = 83;
	mod_value[13][10][10] = 85;
	mod_value[13][8][8] = 88;
	mod_value[13][4][8] = 94;
	mod_value[13][7][13] = 103;
	mod_value[13][6][9] = 105;
	mod_value[13][1][9] = 110;
	mod_value[13][5][5] = 111;
	mod_value[13][7][7] = 115;
	mod_value[13][11][13] = 120;
	mod_value[13][3][11] = 121;
	mod_value[13][3][12] = 122;
	mod_value[13][2][10] = 128;
	mod_value[13][1][2] = 129;
	mod_value[13][10][11] = 140;
	mod_value[13][10][12] = 141;
	mod_value[13][5][8] = 142;
	mod_value[13][3][4] = 144;
	mod_value[13][2][6] = 145;
	mod_value[13][9][10] = 159;
	mod_value[13][8][9] = 162;
	mod_value[13][4][9] = 168;
	mod_value[13][2][11] = 183;
	mod_value[13][2][12] = 184;
	mod_value[13][3][13] = 186;
	mod_value[13][6][10] = 190;
	mod_value[13][3][3] = 192;
	mod_value[13][1][10] = 195;
	mod_value[13][3][7] = 198;
	mod_value[13][7][8] = 203;
	mod_value[13][10][13] = 205;
	mod_value[13][2][4] = 206;
	mod_value[13][6][6] = 207;
	mod_value[13][1][6] = 212;
	mod_value[13][9][11] = 214;
	mod_value[13][9][12] = 215;
	mod_value[13][5][9] = 216;
	mod_value[13][6][11] = 245;
	mod_value[13][6][12] = 246;
	mod_value[13][8][10] = 247;
	mod_value[13][2][13] = 248;
	mod_value[13][1][11] = 250;
	mod_value[13][1][12] = 251;
	mod_value[13][4][10] = 253;
	mod_value[13][2][3] = 254;
	mod_value[13][3][5] = 255;
	mod_value[13][2][7] = 260;
	mod_value[13][4][6] = 270;
	mod_value[13][1][4] = 273;
	mod_value[13][7][9] = 277;
	mod_value[13][9][13] = 279;
	mod_value[13][3][8] = 286;
	mod_value[13][5][10] = 301;
	mod_value[13][8][11] = 302;
	mod_value[13][8][12] = 303;
	mod_value[13][4][11] = 308;
	mod_value[13][4][12] = 309;
	mod_value[13][6][13] = 310;
	mod_value[13][1][13] = 315;
	mod_value[13][2][5] = 317;
	mod_value[13][5][6] = 318;
	mod_value[13][1][3] = 321;
	mod_value[13][6][7] = 322;
	mod_value[13][1][7] = 327;
	mod_value[13][4][4] = 331;
	mod_value[13][2][8] = 348;
	mod_value[13][5][11] = 356;
	mod_value[13][5][12] = 357;
	mod_value[13][3][9] = 360;
	mod_value[13][7][10] = 362;
	mod_value[13][8][13] = 367;
	mod_value[13][4][13] = 373;
}
string solve(){
	init();
	string s = "";
	for(int i = 1; i < 13; i++){
		for(int j = 0; j < 13; j++){
			s += char('a' + j);
		}
	}
	int n, l = -1, r, x = ask(s + 'a');
	if(x == 12){
		if((x = ask(EDGE_CANDIDATE)) == 6 || x == 7 || x == 8){
			n = 4;
			r = (l = x - 5) + 1;
		}
		else{
			n = 11;
			if(x == 132){
				l = 1;
			}
			else if(x == 59){
				l = 2;
			}
			else{
				l = 3;
			}
			r = l + 8;
		}
	}
	else if(x == gt[13]){
		n = r = 13;
		l = 1;
	}
	else{
		for(int i = 3; i < 13; i++){
			for(int j = 1; j <= i; j++){
				if(x == gt[i] * j % mod){
					if(j == 1){
						int x = ask(CANDIDATE[i + 1]);
						for(int k = 1; k < i + 2; k++){
							if(mod_value[i + 1][k][k] == x){
								l = r = k;
								n = i + 1;
								break;
							}
						}
						if(l == -1){
							l = 1;
							r = n = i;
						}
						i = 13;
						break;
					}
					n = i + 1;
					int x = ask(CANDIDATE[n]);
					for(int L = 1; L <= n; L++){
						for(int R = L; R <= n; R++){
							if(mod_value[n][L][R] == x){
								l = L;
								r = R;
								L = n;
								break;
							}
						}
					}
					i = 13;
					break;
				}
			}
		}
	}
	bool z = false;
	if(l == 1 && r == 1){
		l = r = n;
		z = true;
	}
	string ans = "";
	if(l == 1){
		ans += 'a';
	}
	for(int i = 2; i < n; i++){
		for(int j = 1; j < n; j++){
			ans += char('a' + j);
			if(j == n - i + 1 && l <= i && r >= i){
				ans += 'a';
			}
		}
	}
	if(l == n && r == n){
		ans += "ba";
	}
	else{
		ans += "bc";
		if(r == n){
			ans += 'a';
		}
	}
	if(z){
		reverse(ans.begin(), ans.end());
	}
	return ans;
}
