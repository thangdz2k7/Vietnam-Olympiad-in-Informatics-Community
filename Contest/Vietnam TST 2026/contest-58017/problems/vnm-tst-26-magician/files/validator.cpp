#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;
int dsu[36],cnt[36],cc=0,mx=0;
vector<int> ds[36];
bool ck[36];
int root(int i)
{
	if(!dsu[i]) return i;
	return dsu[i]=root(dsu[i]);
}
bool merge(int i,int j)
{
	if((i=root(i))==(j=root(j))) return false;
	dsu[j]=i;
	return true;
}
void dfs(int i,int pre,int d)
{
	cnt[d]++,cc++,mx=max(mx,d);
	for(auto v:ds[i]) dfs(v,i,d+1);
}
int main(int argc,char** argv)
{
    registerValidation(argc,argv);
    int testcase=inf.readInt(1,100,"t");
    inf.readEoln();
    string gr=validator.group();
    while(testcase--)
    {
    	int n=inf.readInt(1,32,"n"),sum=0;
    	inf.readEoln();
    	for(int i=0;i<n;i++)
    	{
    		int c=inf.readInt(0,n-1,"c");
    		if(!c) inf.readEoln();
    		else inf.readSpace();
    		for(int j=0;j<c;j++)
    		{
    			int res=inf.readInt(0,n,"res");
    			ensure(merge(i+1,res+1)==true);
    			if(j!=c-1) inf.readSpace();
    			else inf.readEoln();
    			ds[i].push_back(res),ck[res]=true;
			}
			sum+=c;
		}
		ensure(sum==n-1);
		for(int i=0;i<n;i++) if(!ck[i])
		{
			dfs(i,i,0);
			break;
		}
		ensure(cc==n&&mx<=8);
		for(int i=0;i<=mx;i++) ensure(cnt[i]<=8);
		if(gr=="1") for(int i=0;i<=mx;i++) ensure(cnt[i]==1);
		for(int i=0;i<=n;i++) ck[i]=false,cnt[i]=dsu[i]=0,ds[i].clear();
		mx=cc=0;
	}
	inf.readEof();
}