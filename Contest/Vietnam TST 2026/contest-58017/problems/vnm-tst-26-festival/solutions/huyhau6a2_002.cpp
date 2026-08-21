#include"festivallib.h"
#include<bits/stdc++.h>
using namespace std;
const int MAXN=205;
vector<int> ds[MAXN];
int dis[MAXN],pos[MAXN];
bool ck[MAXN],kc[MAXN];
bitset<MAXN> bt[MAXN];
bool comp(int a,int b) { return dis[a]>dis[b]; }
void dfs(int i,int d)
{
	dis[i]=d,ck[i]=true;
	for(auto v:ds[i]) if(!ck[v]) dfs(v,d+1);
}
void dfs2(int i,int root)
{
	bt[i][root]=true;
	for(auto v:ds[i]) if(!bt[v][root]) dfs2(v,root);
}
vector<int> solveGenius(int N,int S,const vector<int>& U,const vector<int>& V)
{
	for(int i=0;i<U.size();i++) ds[V[i]].push_back(U[i]),kc[U[i]]=true;
	for(int i=0;i<N;i++) if(!ck[i]&&!kc[i]) dfs(i,0);
	for(int i=0;i<N;i++) pos[i]=i;
	sort(pos,pos+N,comp);
	bitset<MAXN> curr=bt[pos[0]];
	int pre=0,cnt=0;
	vector<int> ans(N);
	for(int i=1;i<N;i++)
	{
		if((curr&bt[pos[i]]).count()||i-pre>=S)
		{
			cnt++;
			for(int j=pre;j<i;j++) ans[pos[j]]=cnt;
			curr=0,pre=i;
		}
		curr|=bt[pos[i]];
	}
	cnt++;
	for(int i=pre;i<N;i++) ans[pos[i]]=cnt;
	int sum=N*(N+1)/2%N;
	for(int i=0;i<N;i++) sum=(sum-ans[i]+N)%N;
	for(int i=N-1;sum;i--) ans[pos[i]]++,sum--;
	return ans;
}
bool solveCitizen(const vector<int>& A,const vector<vector<int>>& history)
{
	int n=A.size()+1,sum=n*(n+1)/2%n;
	for(auto v:A) sum=(sum-v+n)%n;
	if(history.size()==sum) return true;
	return false;
}