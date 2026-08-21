#include<bits/stdc++.h>
using namespace std;
struct query { int l,r,k; };
const int MAXN=4e5+5;
const int sqr=360;
long long H[MAXN],pref[MAXN],F[MAXN*4];
pair<int,int> val[MAXN];
int L[MAXN],R[MAXN],pf[MAXN];
bool ck[MAXN*4];
query Q[MAXN*4];
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
    	val[i]={H[i],i};
	}
	sort(val+1,val+n+1);
    for(int i=1;i<=q;i++)
    {
    	cin>>L[i]>>R[i];
    	int len=R[i]-L[i]+1;
    	if(len%2==0)
		{
			Q[++cnt]={L[i],R[i],len/2+1};
			Q[++cnt]={L[i],R[i],len/2};
			Q[++cnt]={L[i],R[i],len/2-1};
			ck[++cnt]=true;
		}
		else if(len>1)
		{
			Q[++cnt]={L[i],R[i],len/2+2};
			Q[++cnt]={L[i],R[i],len/2+1};
			Q[++cnt]={L[i],R[i],len/2};
			Q[++cnt]={L[i],R[i],len/2-1};
		}
		else cnt+=4,ck[cnt-3]=ck[cnt-2]=ck[cnt-1]=ck[cnt]=true;
	}
	for(int i=1;i<=n;i+=sqr)
	{
		int t=0;
		for(int j=1;j<=n;j++) pref[j]=pf[j]=0;
		for(int j=1;j<i+sqr&&j<=n;j++) pf[val[j].second]=1,pref[val[j].second]=val[j].first,t=j;
		for(int j=1;j<=n;j++) pref[j]+=pref[j-1],pf[j]+=pf[j-1];
		for(int j=1;j<=cnt;j++) if(!ck[j])
		{
			if(pf[Q[j].r]-pf[Q[j].l-1]>=Q[j].k)
			{
				ck[j]=true,F[j]=pref[Q[j].r]-pref[Q[j].l-1];
				int res=pf[Q[j].r]-pf[Q[j].l-1]-Q[j].k;
				for(int k=t;k&&res;k--) if(Q[j].l<=val[k].second&&val[k].second<=Q[j].r) F[j]-=val[k].first,res--;
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		long long sum=pref[R[i]]-pref[L[i]-1],len=R[i]-L[i]+1;
		if(len%2==0) cout<<sum*2-F[i*4-3]-F[i*4-2]*2-F[i*4-1]<<"\n";
		else if(len>1)
		{
			long long a=sum*2-F[i*4-3]-F[i*4-1]*3;
			long long b=sum*2-F[i*4-2]*3-F[i*4];
			cout<<max(a,b)<<"\n";
		}
		else cout<<"0\n";
	}
}