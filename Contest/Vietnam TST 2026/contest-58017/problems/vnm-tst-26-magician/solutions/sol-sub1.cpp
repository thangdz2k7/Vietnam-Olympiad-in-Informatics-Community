#include"magicianlib.h"
#include<bits/stdc++.h>
using namespace std;
vector<int> solveAlice(vector< vector<int> > adj)
{
	int n=adj.size(),rt=0,tdfs=0;
	vector<bool> ck(n);
	vector<int> vi(n),ans(n);
	for(auto v:adj) for(auto u:v) ck[u]=true;
	for(int i=0;i<n;i++) if(!ck[i]) rt=i;
	queue<int> Q;
	Q.push(rt);
	while(!Q.empty())
	{
		int a=Q.front();
		Q.pop(),vi[a]=++tdfs,ans[a]+=tdfs;
		for(auto v:adj[a]) Q.push(v);
	}
	return ans;
}
vector< vector<int> > solveBob(vector<int> S)
{
	int n=S.size();
	vector< pair<int,int> > vi;
	for(int i=0;i<n;i++) vi.push_back({S[i],i});
	sort(vi.begin(),vi.end());
	vector< vector<int> > ans(n);
	for(int i=1;i<n;i++) ans[vi[i-1].second].push_back(vi[i].second);
	return ans;
}