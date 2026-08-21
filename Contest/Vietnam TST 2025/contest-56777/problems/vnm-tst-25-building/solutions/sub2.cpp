#include<bits/stdc++.h>
using namespace std;
const int MAXN=2025;
int H[MAXN],A[MAXN];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>H[i];
    for(int i=1;i<=q;i++)
    {
    	int l,r,cnt=0;
    	cin>>l>>r;
    	for(int j=l;j<=r;j++) A[++cnt]=H[j];
    	sort(A+1,A+cnt+1);
    	long long ans=0;
    	if(cnt%2==0)
    	{
    		for(int i=1;i<=cnt;i++) if(i<=cnt/2) ans-=A[i]*(2-(i==cnt/2));
    		else ans+=A[i]*(2-(i==cnt/2+1));
		}
		else if(cnt>1)
		{
			long long sa=0,sb=0;
			for(int i=1;i<=cnt;i++) if(i<=cnt/2) sa-=A[i]*2;
    		else sa+=A[i]*(2-(i<=cnt/2+2));
    		for(int i=1;i<=cnt;i++) if(i<=cnt/2+1) sb-=A[i]*(2-(i>=cnt/2));
    		else sb+=A[i]*2;
    		ans=max(sa,sb);
		}
    	cout<<ans<<"\n";
	}
}