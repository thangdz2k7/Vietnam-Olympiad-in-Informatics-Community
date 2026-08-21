#include<bits/stdc++.h>
using namespace std;
const int MAXN=4e5+5;
int H[MAXN],pref[MAXN][105],cnt[105];
int f(int k)
{
	int ans=0;
	for(int i=1;i<=100;i++) if(k>=cnt[i]) k-=cnt[i],ans+=cnt[i]*i;
	else
	{
		ans+=k*i;
		break;
	}
	return ans;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
    	cin>>H[i];
    	pref[i][H[i]]++;
    	for(int j=1;j<=100;j++) pref[i][j]+=pref[i-1][j];
	}
	for(int i=1;i<=q;i++)
	{
		int l,r;
		cin>>l>>r;
		if(l==r) cout<<"0\n";
		else
		{
			int sum=0,len=r-l+1,ans=0;
			for(int j=1;j<=100;j++) sum+=(cnt[j]=pref[r][j]-pref[l-1][j])*j*2;
			if(len%2==0) cout<<sum-f(len/2+1)-f(len/2)*2-f(len/2-1)<<"\n";
			else cout<<max(sum-f(len/2+2)-f(len/2)*3,sum-f(len/2+1)*3-f(len/2-1))<<"\n";
		}
	}
}