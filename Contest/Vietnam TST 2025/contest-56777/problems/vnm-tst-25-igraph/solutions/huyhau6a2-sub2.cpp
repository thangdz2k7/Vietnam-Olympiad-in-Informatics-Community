#include<bits/stdc++.h>
using namespace std;
const int MAXN=5005;
const int INF=1e9;
pair<int,int> pref[MAXN][MAXN],suff[MAXN][MAXN];
int A[MAXN],cnt[MAXN][MAXN];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,q;
    cin>>n>>q;
    for(int i=0;i<=n+1;i++) for(int j=0;j<=n+1;j++) pref[i][j].first=suff[i][j].second=INF;
    for(int i=1;i<=n;i++)
    {
    	cin>>A[i];
    	cnt[A[i]][i]++;
    	pref[A[i]][i]=suff[A[i]][i]={A[i],i};
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cnt[i][j]+=cnt[i-1][j];
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cnt[i][j]+=cnt[i][j-1];
	for(int i=1;i<=n;i++) for(int j=n;j;j--)
	{
		pref[i][j].first=min(pref[i][j].first,min(pref[i-1][j].first,pref[i][j+1].first));
		pref[i][j].second=max(pref[i][j].second,max(pref[i-1][j].second,pref[i][j+1].second));
	}
	for(int i=n;i;i--) for(int j=1;j<=n;j++)
	{
		suff[i][j].first=max(suff[i][j].first,max(suff[i+1][j].first,suff[i][j-1].first));
		suff[i][j].second=min(suff[i][j].second,min(suff[i+1][j].second,suff[i][j-1].second));
	}
	for(int i=1;i<=q;i++)
	{
		int u,l,r;
		cin>>u>>l>>r;
		int pre=1,lx=A[u],rx=A[u],ly=u,ry=u,ans=0;
		for(int j=1;j<=r;j++)
		{
			int s=n-cnt[lx-1][ly-1]-(cnt[n][n]-cnt[rx][n]-cnt[n][ry]+cnt[rx][ry]);
			if(j>=l) ans+=(s-pre)*j;
			pre=s;
			int plx=lx,prx=rx,ply=ly,pry=ry;
			lx=min(lx,pref[prx-1][ply+1].first);
			ry=max(ry,pref[prx-1][ply+1].second);
			rx=max(rx,suff[plx+1][pry-1].first);
			ly=min(ly,suff[plx+1][pry-1].second);
		}
		cout<<ans<<"\n";
	}
}