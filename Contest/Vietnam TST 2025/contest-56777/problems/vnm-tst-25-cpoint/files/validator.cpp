#include <bits/stdc++.h>
#include "testlib.h"
 
using namespace std;

const int MX = 1 << 30;
const int N = 29;

int x[N], y[N];
// all a[i] in [0, MX)
 
int main(int argc, char *argv[]) {
    registerValidation(argc, argv);
    
    
    
    for (int i = 0; i < N; i++) {
        x[i] = inf.readInt(0, MX - 1, "x_i"); inf.readSpace();
        y[i] = inf.readInt(0, MX - 1, "y_i"); inf.readEoln();
    }
 
    inf.readEof();

    if (validator.group() == "sub1") {
        int cnt = 0;
        for (int i = 0; i < N; i++)
            if (x[i] % 8 == 0 && y[i] % 8 == 0)
                cnt++;
        ensuref(cnt >= 8, "There's less than 8 points having x and y a multiple of 8");
    } else if (validator.group() == "sub2") {
        
    }
    
    return 0;
}
