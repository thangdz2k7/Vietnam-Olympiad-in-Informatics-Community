#include"festivallib.h"
#include<bits/stdc++.h>
using namespace std;
const int MAXN=205;
vector<int> ds[MAXN],sd[MAXN];
int dis[MAXN],pos[MAXN],deg[MAXN];
bool ck[MAXN],kc[MAXN];
struct comp
{
	bool operator()(int a,int b) { return deg[a]>deg[b]; } //meme strat
};
void dfs(int i,int d)
{
	dis[i]=d,ck[i]=true;
	for(auto v:ds[i]) if(!ck[v]) dfs(v,d+1);
}
vector<int> solveGenius(int N,int S,const vector<int>& U,const vector<int>& V)
{
	vector<int> ans(N);
	for(int i=0;i<N;i++) deg[i]=0;
	for(int i=0;i<U.size();i++) ds[V[i]].push_back(U[i]),kc[U[i]]=true,deg[V[i]]++,sd[U[i]].push_back(V[i]);
	for(int i=0;i<N;i++) if(!ck[i]&&!kc[i]) dfs(i,0);
	for(int i=0;i<N;i++) ck[i]=false;
	int cc=0,cnt=0;
	vector<int> pos;
	while(cc<N)
	{
		priority_queue< int,vector<int>,comp > pq;
		vector<int> vv;
		for(int i=0;i<N;i++) if(!ck[i]) pq.push(i);
		while(!pq.empty())
		{
			int a=pq.top();
			pq.pop();
			if(deg[a]==0) vv.push_back(a);
			if(vv.size()>=S) break;
		}
		cnt++;
		for(auto v:vv)
		{
			ck[v]=true,ans[v]=cnt,cc++,pos.push_back(v);
			for(auto u:sd[v]) deg[u]--;
		}
	}
	int sum=N*(N+1)/2%N;
	for(int i=0;i<N;i++) sum=(sum-ans[i]+N)%N;
	for(int i=N-1;sum;i--) ans[pos[i]]++,sum--;
	return ans;
}
bool solveCitizen(const vector<int>& A,const vector<vector<int>>& history)
{
	int n=A.size()+1,sum=n*(n+1)/2%n;
	for(auto v:A) sum=(sum-v+n)%n;
	sum=(sum-1+n)%n;
	if(history.size()==sum) return true;
	return false;
}