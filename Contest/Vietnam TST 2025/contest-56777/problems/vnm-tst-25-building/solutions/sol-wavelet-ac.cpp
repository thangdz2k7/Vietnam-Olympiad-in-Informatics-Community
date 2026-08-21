#include<bits/stdc++.h>
using namespace std;
const int MAXN=4e5+5;
int H[MAXN],cntzero[19][MAXN],A[MAXN],A1[MAXN],A2[MAXN],val[MAXN],C[19];
long long pref[19][MAXN],pf[MAXN];
void build(int n)
{
	for(int i=18;i+1;i--)
	{
		int cnt1=0,cnt2=0;
		for(int j=1;j<=n;j++)
		{
			if(A[j]&(1<<i)) A2[++cnt2]=A[j];
			else A1[++cnt1]=A[j],pref[i][j]=val[A[j]];
			cntzero[i][j]=cnt1,pref[i][j]+=pref[i][j-1];
		}
		for(int j=1;j<=cnt1;j++) A[j]=A1[j];
		for(int j=1;j<=cnt2;j++) A[j+cnt1]=A2[j];
		C[i]=cntzero[i][n];
	}
}
long long get(int n,int l,int r,int k)
{
	l--;
	long long ans=0,v=0;
	for(int i=18;i+1;i--)
	{
		int cnt=cntzero[i][r]-cntzero[i][l];
		if(cnt<=k)
		{
			k-=cnt,v+=(1<<i),ans+=pref[i][r]-pref[i][l];
			l=l-cntzero[i][l]+C[i],r=r-cntzero[i][r]+C[i];
		}
		else l=cntzero[i][l],r=cntzero[i][r];
	}
	return ans+1LL*val[v]*k;
}
long long kth(int n,int l,int r,int k)
{
	l--;
	int v=0;
	for(int i=18;i+1;i--)
	{
		int cnt=cntzero[i][r]-cntzero[i][l];
		if(cnt<k) k-=cnt,v+=(1<<i),l=l-cntzero[i][l]+C[i],r=r-cntzero[i][r]+C[i];
		else l=cntzero[i][l],r=cntzero[i][r];
	}
	return val[v];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,q,cnt=0;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
    	cin>>H[i];
    	val[i]=H[i];
    }
    sort(val+1,val+n+1);
    for(int i=1;i<=n;i++) A[i]=lower_bound(val+1,val+n+1,H[i])-val,pf[i]=pf[i-1]+H[i];
	build(n);
	for(int i=1;i<=q;i++)
	{
		int l,r;
		cin>>l>>r;
		long long sum=pf[r]-pf[l-1],len=r-l+1;
		if(len%2==0)
		{
			long long x=get(n,l,r,len/2+1),y=x-kth(n,l,r,len/2+1),z=y-kth(n,l,r,len/2);
			cout<<sum*2-x-y*2-z<<"\n";
		}
		else if(l!=r)
		{
			long long x=get(n,l,r,len/2+2),y=x-kth(n,l,r,len/2+2),z=y-kth(n,l,r,len/2+1),t=z-kth(n,l,r,len/2);
			cout<<sum*2-min(x+z*3,y*3+t)<<"\n";
		}
		else cout<<"0\n";
	}
}