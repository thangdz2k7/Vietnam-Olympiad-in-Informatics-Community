#include<bits/stdc++.h>
using namespace std;
const int MAXN=4e5+5;
const int sqr=360;
struct query { int l,r,pos; };
bool comp(query a,query b)
{
    if(a.l/sqr==b.l/sqr)
    {
        if((a.l/sqr)&1) return a.r>b.r;
        return a.r<b.r;
    }
    return a.l/sqr<b.l/sqr;
}
query Q[MAXN];
long long H[MAXN],pref[MAXN],ans[MAXN],sblock[MAXN/sqr+5];
pair<int,int> val[MAXN];
int pos[MAXN],cnt[MAXN],block[MAXN/sqr+5];
void update(int i,int v)
{
	cnt[i]+=v,block[i/sqr]+=v,sblock[i/sqr]+=val[i].first*v;
}
long long get(int k)
{
	long long ans=0;
	for(int i=0;;i++) if(k>=block[i]) k-=block[i],ans+=sblock[i];
	else for(int j=i*sqr;;j++) if(k>=cnt[j])
	{
		k-=cnt[j];
		if(cnt[j]) ans+=val[j].first;
	}
	else return ans;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,q;
    cin>>n>>q;
    block[(n+1)/sqr]=n;
    for(int i=1;i<=n;i++)
    {
    	cin>>H[i];
    	val[i]={H[i],i},pref[i]=pref[i-1]+H[i];
	}
	sort(val+1,val+n+1);
	for(int i=1;i<=n;i++) pos[val[i].second]=i;
    for(int i=1;i<=q;i++)
    {
    	cin>>Q[i].l>>Q[i].r;
    	Q[i].pos=i;
	}
	sort(Q+1,Q+q+1,comp);
	int l=1,r=0;
	for(int i=1;i<=q;i++)
	{
		while(r<Q[i].r) update(pos[++r],1);
		while(r>Q[i].r) update(pos[r--],-1);
		while(l<Q[i].l) update(pos[l++],-1);
		while(l>Q[i].l) update(pos[--l],1);
		int len=r-l+1;
		if(len%2==0) ans[Q[i].pos]=(pref[r]-pref[l-1])*2-get(len/2+1)-get(len/2)*2-get(len/2-1);
		else if(l!=r)
		{
			long long a=(pref[r]-pref[l-1])*2-get(len/2+2)-get(len/2)*3;
			long long b=(pref[r]-pref[l-1])*2-get(len/2+1)*3-get(len/2-1);
			ans[Q[i].pos]=max(a,b);
		}
	}
	for(int i=1;i<=q;i++) cout<<ans[i]<<"\n";
}