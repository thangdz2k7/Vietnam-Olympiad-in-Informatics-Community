#include<bits/stdc++.h>
using namespace std;
const long long INF=1e18;
long long H[20],dp[(1<<20)+5][20],dis[20][20];
int getlog(long long n) { return 63-__builtin_clzll(n); }
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++) cin>>H[i];
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) dis[i][j]=abs(H[i]-H[j]);
    for(int i=1;i<(1<<n);i++)
    {
    	for(int j=0;j<n;j++) dp[i][j]=-INF;
    	if(__builtin_popcount(i)==1) dp[i][getlog(i)]=0;
    	else for(int j=i;j;j-=j&-j)
    	{
    		int p=getlog(j&-j);
    		for(int k=i-(1<<p);k;k-=k&-k)
    		{
    			int q=getlog(k&-k);
    			dp[i][p]=max(dp[i][p],dp[i-(1<<p)][q]+dis[p][q]);
			}
		}
	}
    for(int i=1;i<=q;i++)
    {
    	int l,r,mask=0;
    	cin>>l>>r;
    	for(int j=l-1;j<r;j++) mask|=(1<<j);
    	long long ans=-INF;
    	for(int j=0;j<n;j++) ans=max(ans,dp[mask][j]);
    	cout<<ans<<"\n";
	}
}