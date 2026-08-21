#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;
int main(int argc,char** argv)
{
    registerValidation(argc,argv);
    int n=inf.readInt(1,4e5,"n");
    inf.readSpace();
    int q=inf.readInt(1,4e5,"q");
    inf.readEoln();
    vector<int> a;
    for(int i=1;i<=n;i++)
    {
        inf.readInt(1,1e9,"a");
        if(i<n) inf.readSpace();
        else inf.readEoln();
    }
    for(int i=1;i<=q;i++)
    {
        int l=inf.readInt(1,n,"l");
        inf.readSpace();
        int r=inf.readInt(l,n,"r");
        inf.readEoln();
    }
    string gr=validator.group();
    if(gr=="1") ensure(n<=20&&q<=20);
    else if(gr=="2") ensure(n<=2000&&q<=2000);
    else if(gr=="3") ensure(n<=50000&&q<=50000);
    else if(gr=="4") for(auto v:a) ensure(v<=100);
    else if(gr=="5") ensure(n<=150000&&q<=150000);
	inf.readEof();
}