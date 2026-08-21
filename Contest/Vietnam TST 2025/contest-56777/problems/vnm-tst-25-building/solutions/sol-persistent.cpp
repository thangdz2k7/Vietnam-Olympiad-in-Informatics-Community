#include<bits/stdc++.h>
using namespace std;
const int MAXN=4e5+5;
long long H[MAXN],pref[MAXN],segv[MAXN*24];
int segc[MAXN*24],L[MAXN*24],R[MAXN*24],pl[MAXN*4],pr[MAXN*4],pos[MAXN],st[MAXN],cnode;
pair<int,int> val[MAXN];
void build(int l,int r,int pos)
{
	if(l==r) return ;
	int mid=(l+r)/2;
	build(l,mid,L[pos]=pl[pos]=pos*2);
	build(mid+1,r,R[pos]=pr[pos]=pos*2+1);
}
void update(int l,int r,int i,int val,int pos,int p)
{
	if(l==r)
	{
		segc[p]=1,segv[p]=val;
		return ;
	}
	int mid=(l+r)/2;
	L[p]=pl[pos],R[p]=pr[pos];
	if(i<=mid) update(l,mid,i,val,pos*2,L[p]=pl[pos]=++cnode);
	else update(mid+1,r,i,val,pos*2+1,R[p]=pr[pos]=++cnode);
	segc[p]=segc[L[p]]+segc[R[p]];
	segv[p]=segv[L[p]]+segv[R[p]];
}
long long walk(int n,int val,int qr,int ql)
{
	if(segc[qr]-segc[ql]<=val) return segv[qr]-segv[ql];
	int l=1,r=n;
	long long ans=0;
	while(l<r)
	{
		int mid=(l+r)/2;
		if(segc[L[qr]]-segc[L[ql]]<=val) val-=segc[L[qr]]-segc[L[ql]],ans+=segv[L[qr]]-segv[L[ql]],l=mid+1,qr=R[qr],ql=R[ql];
		else r=mid,qr=L[qr],ql=L[ql];
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
    	val[i]={H[i],i},pref[i]=pref[i-1]+H[i];
	}
	sort(val+1,val+n+1);
	for(int i=1;i<=n;i++) pos[val[i].second]=i;
	build(1,n,1);
	cnode=n*4,st[0]=1;
	for(int i=1;i<=n;i++) update(1,n,pos[i],H[i],1,st[i]=++cnode);
	while(q--)
	{
		int l,r;
		cin>>l>>r;
		long long sum=(pref[r]-pref[l-1])*2,len=r-l+1;
		if(len%2==0) cout<<sum-walk(n,len/2+1,st[r],st[l-1])-walk(n,len/2,st[r],st[l-1])*2-walk(n,len/2-1,st[r],st[l-1])<<"\n";
		else if(len>1)
		{
			long long a=sum-walk(n,len/2+2,st[r],st[l-1])-walk(n,len/2,st[r],st[l-1])*3;
			long long b=sum-walk(n,len/2+1,st[r],st[l-1])*3-walk(n,len/2-1,st[r],st[l-1]);
			cout<<max(a,b)<<"\n";
		}
		else cout<<"0\n";
	}
}