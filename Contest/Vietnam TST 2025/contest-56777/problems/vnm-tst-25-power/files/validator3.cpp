#include <bits/stdc++.h>
#include "testlib.h"
 
using namespace std;
 
int main(int argc, char *argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(1, 20000, "n");
    inf.readEoln();

    string gr = validator.group();
    if (gr == "1") ensure(1 <= n && n <= 5);
    if (gr == "2") ensure(1 <= n && n <= 50);
    if (gr == "3") ensure(1 <= n && n <= 20000);

    inf.readEof();
}