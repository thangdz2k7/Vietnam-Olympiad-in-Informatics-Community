#include<bits/stdc++.h>
#include"testlib.h"

using namespace std;

int main(int argc, char** argv){

    registerValidation(argc, argv);
    string gr = validator.group();
    int n = inf.readInt(2, 200000, "n");
    inf.readSpace();
    int m = inf.readInt(1, 800000, "m");
    inf.readEoln();

    for(int i = 1; i <= m; ++ i){
        int x = inf.readInt(1, n, "x");
        inf.readSpace();
        int y = inf.readInt(1, n, "y");
        inf.readEoln();
        ensuref(x != y, "x must be different y !");
    }

    if(gr == "1"){
        ensuref(n <= 7 && m <= 20, "wrong limit of n and m");
    }

    if(gr == "2"){
        ensuref(n <= 100 && m <= 400, "wrong limit of n and m");
    }
    
    if(gr == "3"){
        ensuref(n <= 1000 && m <= 4000, "wrong limit of n and m");
    }
    
	inf.readEof();
}