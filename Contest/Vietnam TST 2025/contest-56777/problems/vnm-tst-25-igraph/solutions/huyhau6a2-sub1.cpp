#include<bits/stdc++.h>
using namespace std;
const int MAXN=305;
const int INF=1e9;
int dp[MAXN][MAXN],pref[MAXN][MAXN],A[MAXN];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>A[i];
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dp[i][j]=INF*(i!=j);
    for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) if(A[i]>A[j]) dp[i][j]=dp[j][i]=1;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) for(int k=1;k<=n;k++) dp[j][k]=min(dp[j][k],dp[j][i]+dp[i][k]);
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(dp[i][j]>0&&dp[i][j]<=n) pref[i][dp[i][j]]+=dp[i][j];
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) pref[i][j]+=pref[i][j-1];
    for(int i=1;i<=q;i++)
    {
    	int u,l,r;
    	cin>>u>>l>>r;
    	cout<<pref[u][r]-pref[u][l-1]<<"\n";
	}
}