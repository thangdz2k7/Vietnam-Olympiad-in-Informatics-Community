#include"festivallib.h"
#include<bits/stdc++.h>
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int Rand(int l,int r) { return uniform_int_distribution<int>(l,r)(rng); }
const int MAXN=205;
vector<int> ds[MAXN],sd[MAXN];
int dis[MAXN],deg[MAXN];
bool ck[MAXN],kc[MAXN],cc[MAXN];
bool comp(pair< vector<int>,vector<int> > a,pair< vector<int>,vector<int> > b)
{
	return a.second.size()>b.second.size();
}
bool cmp(int a,int b) { return sd[a].size()>sd[b].size(); }
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
	vector< pair< vector<int>,vector<int> > > state;
	vector<int> a,b;
	for(int i=0;i<N;i++) a.push_back(deg[i]);
	state.push_back({a,{}});
	while(true)
	{
		vector< pair< vector<int>,vector<int> > > vi;
		for(auto v:state)
		{
			vector<int> dg=v.first,pos;
			for(int i=0;i<N;i++) cc[i]=false;
			for(auto u:v.second) cc[u]=true;
			for(int i=0;i<N;i++) if(!dg[i]&&!cc[i]) pos.push_back(i);
			int sz=pos.size();
			sort(pos.begin(),pos.end(),cmp);
			for(int t=0;t<100;t++)
			{
				for(int j=0;j<5;j++) swap(pos[Rand(0,sz-1)],pos[Rand(0,sz-1)]);
				vector<int> np=v.second;
				dg=v.first;
				int ct=min(sz,S);
				for(int j=0;j<ct;j++)
				{
					np.push_back(pos[j]);
					for(auto u:sd[pos[j]]) dg[u]--;
				}
				vi.push_back({dg,np});
			}
		}
		sort(vi.begin(),vi.end(),comp);
		while(vi.size()>10) vi.pop_back();
		state=vi;
		if(state[0].second.size()==N) break;
	}
	a=state[0].second;
	int cnt=0;
	vector<int> vv;
	for(int i=0;i<N;i++)
	{
		bool ck=false;
		if(!deg[a[i]])
		{
			if(vv.size()<S) vv.push_back(a[i]);
			else ck=true;
		}
		else ck=true;
		if(ck)
		{
			cnt++;
			for(auto v:vv)
			{
				ans[v]=cnt;
				for(auto u:sd[v]) deg[u]--;
			}
			vv.clear(),vv.push_back(a[i]);
		}
	}
	cnt++;
	for(auto v:vv) ans[v]=cnt;
	int sum=N*(N+1)/2%N;
	for(int i=0;i<N;i++) sum=(sum-ans[i]+N)%N;
	for(int i=N-1;sum;i--) ans[a[i]]++,sum--;
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