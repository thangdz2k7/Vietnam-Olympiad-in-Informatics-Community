#include "cpointlib.h"
#include <bits/stdc++.h>
using namespace std;


void rw(string message){
    //quitf(_wa, (message).c_str());
    cout << -1 << "\n" << message << "\n";
    exit(0);
}
 
namespace data {
    const int MX = 1 << 30; // 0 <= a[i] < MX
    const int MX_OP = 100'000;
    int a[64] = {}; // initially is 0
    int Q = 0;
    int numOP = 0;
    void checkBound(int index) { 
        // check if index is in [0, 64)
        if (0 <= index && index < 64) 
            return ;
        rw("WA - invalid query (index out of bound)");
    }
    void add(int i, int j, int k) {
        checkBound(i), checkBound(j), checkBound(k);
        
        int x = a[i], y = a[j];
        int z = (x + y) & (MX - 1); 
        // take sum and use only last 30 bits
 
        a[k] = z;
 
        numOP++;
        if (numOP > MX_OP) {
            rw("WA - too many queries");
        }
    }
    void sub(int i, int j, int k) {
        checkBound(i), checkBound(j), checkBound(k);
        
        int x = a[i], y = a[j];
        int z = (x - y);
 
        if (z < 0) z = 0;
 
        a[k] = z;      
 
        numOP++;
        if (numOP > MX_OP) {
            rw("WA - too many queries");
        }
    }
    void half(int i, int j) {
        checkBound(i), checkBound(j);
        int x = a[i];
        int z = x / 2;
 
        a[j] = z;
        
        numOP++;
        if (numOP > MX_OP) {
            rw("WA - too many queries");
        }
    }
    bool ask(string s) {
        
        // check 64-length binary string
        
        if (s.length() != 64) {
            rw("WA - invalid query (wrong query string length)");
        }
        
        for (char c : s) {
            if (c != '0' && c != '1') {    
                rw("WA - invalid query (query string is not binary)");
            }
        }
 
        Q++;
 
        for (int i = 0; i < 64; i++)
            for (int j = i + 1; j < 64; j++)
                if (s[i] == '1' && s[j] == '1' && a[i] == a[j])
                    return true;
 
        return false;
    }
}
 
void add(int i, int j, int k) { data::add(i, j, k); }
void sub(int i, int j, int k) { data::sub(i, j, k); }
void half(int i, int j) { data::half(i, j); }
bool ask(string s) { return data::ask(s); }
 
vector <int> solve(); 

void process() {
    
    pair<int, int> p[29];
    for (int i = 0; i < 29; i++)
        cin >> p[i].first >> p[i].second;
 
 
    fill_n(data::a, 64, 0);
    data::Q = data::numOP = 0;
 
    for (int i = 0; i < 29; i++) {
        data::a[2*i] = p[i].first;
        data::a[2*i + 1] = p[i].second;
    }
 
    vector <int> ids = solve();
 
    {
        long long sumX, sumY;
        sumX = sumY = 0;
        if (ids.size() != 8) {
            rw("WA - invalid solution (subset size is not 8)");
        }
        // assert(ids.size() == 8);
        sort(ids.begin(), ids.end());
        
        for (int i : ids) {
            if (i < 0 || i >= 29) {
                rw("WA - invalid solution (index out of bound)");
            }
        }
 
        for (int i = 1; i < 8; i++) 
            if (ids[i] == ids[i-1]) {
                rw("WA - invalid solution (duplicated points)");
            }
        
        for (int id : ids) {
            sumX += p[id].first;
            sumY += p[id].second;
        }
 
        if (sumX % 8 != 0 || sumY % 8 != 0) {
            // invalid answer
            rw("WA - invalid solution (invalid subset)");
        }
    }
 
    cout << data::Q << '\n';
    cout << "Okay\n";
}
 
int main(int argc, char *argv[]) {
    
    
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//registerTestlibCmd(argc, argv);
    //	cout << "HELLO THERE?\n";
    //	quitf(_wa, "TEST");
    //	return 0;
    	process();
 
 
 
}
