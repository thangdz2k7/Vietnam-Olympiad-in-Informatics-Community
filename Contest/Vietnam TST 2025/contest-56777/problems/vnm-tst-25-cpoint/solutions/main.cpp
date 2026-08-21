#include "cpointlib.h"
#include<bits/stdc++.h>
using namespace std;
//0-57 are for points
//58 - 62 are for the 5 points to bin search
//63 are free, we'll use that for mod calculation
void calmod(int p, int k)
{
    //Calculate p mod 2^k and store in place 63
    sub(63, 63, 63);
    add(p, 63, 63);
    for(int i = 1; i <= k; i++) half(63, 63);
    for(int i = 1; i <= k; i++) add(63, 63, 63);
    sub(p, 63, 63);
}
void mpoint(int p, int i, int k)
{
    //We will take point p, and create a mask in place i+58 mod 2^k
    i += 58; sub(i, i, i);
    calmod(2*p, k); add(i, 63, i);
    for(int j = 1; j <= k; j++) add(i, i, i);
    calmod(2*p+1, k); add(i, 63, i);
}
void addp(int i, int j, int k)
{
    add(2*i, 2*j, 2*k);
    add(2*i+1, 2*j+1, 2*k+1);
}
string createstr(int l, int r)
{
    string s = "0000000000000000000000000000000000000000000000000000000000000000";
    for(int i = l; i <= r; i++) s[i+58] = '1';
    return s;
}
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
vector<int> solve()
{
    //76 queries solution
    vector<vector<int>> tray, result;
    for(int i = 0; i <= 28; i++) tray.push_back({i});
    vector<int> targetsz = {13, 5, 1};
    for(int it = 0; it < 3; it++){
        shuffle(tray.begin(), tray.end(), rng);
        vector<vector<int>> window;
        int state = 0;
        //0 = no distinct; 1 = two - distinct; 2 = three - distinct
        for(int i = 0; i < tray.size(); i++){
            window.push_back(tray[i]);
            mpoint(tray[i][0], window.size()-1, it+1);
            int tl = -1, tr = -1;
            if(window.size() < 3) continue;
            else if(window.size() == 3){
                if(state == 1){
                    if(ask(createstr(0, 2)) == 1){
                        tr = 2;
                        if(ask(createstr(1, 2)) == 1) tl = 1;
                        else tl = 0;
                        state = 0;
                    }
                    else state = 2;
                }
            }
            else if(window.size() == 4){
                if(state != 2 && ask(createstr(0, 2)) == 1){
                    if(ask(createstr(0, 1)) == 1){tl = 0; tr = 1;}
                    else if (ask(createstr(1, 2)) == 1){tl = 1; tr = 2;}
                    else{tl = 0; tr = 2;}
                    state = 0;
                }
                else{
                    tr = 3;
                    int l = 0, r = 3;
                    while(l < r){
                        int mid = (l+r)/2+1;
                        if(ask(createstr(mid-1, tr)) == 0) r = mid-1;
                        else l = mid;
                    }
                    tl = l-1; state = 1;
                }
            }
            else{
                //We know the other four are pairwise distinct
                tr = 4;
                int l = 0, r = 3;
                while(l < r){
                    int mid = (l+r)/2+1;
                    if(ask(createstr(mid, tr)) == 0) r = mid-1;
                    else l = mid;
                }
                tl = l; state = 2;
            }
            if(tl > -1){
                //cerr<<"B"<<tl<<" "<<tr<<endl;
                //Merge the two points and add it to the result
                vector<int> target;
                if(window[tl][0] > window[tr][0]) swap(window[tl], window[tr]);
                addp(window[tl][0], window[tr][0], window[tl][0]);
                /*debug(window[tl][0]);
                debug(window[tr][0]);*/
                for(int j : window[tl]) target.push_back(j);
                for(int j : window[tr]) target.push_back(j);
                sort(target.begin(), target.end());
                result.push_back(target);
                vector<vector<int>> nw;
                for(int j = 0; j < window.size(); j++) if(j != tr){
                    nw.push_back(window[j]);
                    if(j > tr){
                        sub(j-1+58, j-1+58, j-1+58);
                        add(j-1+58, j+58, j-1+58);
                    }
                }
                window = nw; nw.clear();
                for(int j = 0; j < window.size(); j++) if(j != tl){
                    nw.push_back(window[j]);
                    if(j > tl){
                        sub(j-1+58, j-1+58, j-1+58);
                        add(j-1+58, j+58, j-1+58);
                    }
                }
                window = nw;
                /*for(int i : target) cerr<<"C"<<i<<" ";
                debug(target[0]);*/
                if(result.size() == targetsz[it]) break;
            }
        }
        //cerr<<"A"<<result.size()<<endl;
        tray = result; result.clear();
    }
    return tray[0];
}

