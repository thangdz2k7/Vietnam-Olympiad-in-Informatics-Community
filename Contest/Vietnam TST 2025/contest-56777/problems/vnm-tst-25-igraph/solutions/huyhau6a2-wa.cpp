#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
const int INF=1e9;
pair<int,int> operator+(const pair<int,int>& a,const pair<int,int>& b)
{
	return {min(a.first,b.first),max(a.second,b.second)};
}
struct fp
{
	pair<int,int> fen[MAXN];
	void update(int i,int n,pair<int,int> val) { for(;i<=n;i+=i&-i) fen[i]=fen[i]+val; }
	pair<int,int> get(int i) { pair<int,int> ans={INF,0};for(;i;i-=i&-i) ans=ans+fen[i];return ans; }
};
struct fs
{
	int fen[MAXN];
	void update(int i,int n,int val) { for(;i<=n;i+=i&-i) fen[i]+=val; }
	int get(int i) { int ans=0;for(;i;i-=i&-i) ans+=fen[i];return ans; }
};
struct qp { int idx,pos; };
struct qs { int idx,he,pos; };
struct query { int lx,rx,ly,ry; };
fp f;
fs g;
vector<qp> vp[MAXN];
vector<qs> vq[MAXN];
int A[MAXN],pa[MAXN],pre[MAXN],sum[MAXN],L[MAXN],R[MAXN];
long long ans[MAXN];
query Q[MAXN],pq[MAXN];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
    	cin>>A[i];
    	pa[A[i]]=i;
	}
	int mx=0;
	for(int i=1;i<=q;i++)
	{
		int u,l,r;
		cin>>u>>l>>r;
		L[i]=l,R[i]=r,Q[i]={A[u],A[u],u,u},pre[i]=1,sum[i]=0,mx=max(mx,r);
	}
	for(int t=1;t<=min(36,mx);t++)
	{
		for(int i=1;i<=q;i++)
		{
			pq[i]=Q[i];
			vq[Q[i].rx].push_back({n,1,i});
			vq[n].push_back({Q[i].ry,1,i});
			vq[Q[i].rx].push_back({Q[i].ry,-1,i});
			vq[Q[i].lx-1].push_back({Q[i].ly-1,-1,i});
		}
		for(int i=0;i<=n;i++) g.fen[i]=0;
		for(int i=0;i<=n;i++)
		{
			if(i) g.update(pa[i],n,1);
			for(auto v:vq[i]) sum[v.pos]+=v.he*g.get(v.idx);
			vq[i].clear();
		}
		for(int i=1;i<=q;i++)
		{
			if(t>=L[i]&&t<=R[i]) ans[i]+=1LL*(sum[i]-pre[i])*t;
			pre[i]=sum[i],sum[i]=0;
		}
		for(int i=1;i<=q;i++) vp[pq[i].rx-1].push_back({pq[i].ly+1,i});
		for(int i=0;i<=n;i++) f.fen[i]={INF,0};
		for(int i=0;i<=n;i++)
		{
			if(i) f.update(n-pa[i]+1,n,{i,pa[i]});
			for(auto v:vp[i])
			{
				pair<int,int> res=f.get(n-v.idx+1);
				Q[v.pos].lx=min(Q[v.pos].lx,res.first);
				Q[v.pos].ry=max(Q[v.pos].ry,res.second);
			}
			vp[i].clear();
		}
		for(int i=1;i<=q;i++) vp[pq[i].lx+1].push_back({pq[i].ry-1,i});
		for(int i=0;i<=n;i++) f.fen[i]={INF,0};
		for(int i=n+1;i;i--)
		{
			if(i<=n) f.update(pa[i],n,{pa[i],i});
			for(auto v:vp[i])
			{
				pair<int,int> res=f.get(v.idx);
				Q[v.pos].rx=max(Q[v.pos].lx,res.second);
				Q[v.pos].ly=min(Q[v.pos].ry,res.first);
			}
			vp[i].clear();
		}
	}
	for(int i=1;i<=q;i++) cout<<ans[i]<<"\n";
}
