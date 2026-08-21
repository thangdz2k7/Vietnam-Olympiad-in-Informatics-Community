#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;
int main(int argc,char** argv)
{
    registerTestlibCmd(argc,argv);
    int n=inf.readInt(),m=inf.readInt();
    bool ck=true;
    for(int i=1;i<=n;i++)
    {
        int a=ouf.readInt(),b=ans.readInt();
        if(b==-1)
        {
            if(a!=-1) quitf(_wa,"Skill issue!");
        }
        else
        {
            if(!(a>=1&&a<=m)) quitf(_wa,"Skill issue!");
            else if(a!=b) ck=false;
            else ck=true;
        }
    }
    if(!ck) quitp(50.0,"So so...");
    else quitf(_ok,"Accepted!");
}
