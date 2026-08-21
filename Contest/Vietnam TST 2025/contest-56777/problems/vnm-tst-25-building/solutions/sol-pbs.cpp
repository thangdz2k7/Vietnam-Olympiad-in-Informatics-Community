#include<bits/stdc++.h>
using namespace std;
struct query { int l,r,k; };
const int MAXN=4e5+5;
long long H[MAXN],ff[MAXN],F[MAXN*4],pref[MAXN];
pair<int,int> val[MAXN];
int L[MAXN],R[MAXN],fen[MAXN];
query Q[MAXN*4];
void update(int i,int n,int v)
{
	int w=val[i].first*v;
	for(i=val[i].second;i<=n;i+=i&-i) fen[i]+=v,ff[i]+=w;
}
int get(int i)
{
	int ans=0;
	for(;i;i-=i&-i) ans+=fen[i];
	return ans;
}
long long getf(int i)
{
	long long ans=0;
	for(;i;i-=i&-i) ans+=ff[i];
	return ans;
}
void solve(int n,int l,int r,vector<int> vq)
{
	if(l==r)
	{
		update(l,n,1);
		for(auto v:vq) F[v]=getf(Q[v].r)-getf(Q[v].l-1);
		update(l,n,-1);
		return ;
	}
	int mid=(l+r)/2;
	for(int i=l;i<=mid;i++) update(i,n,1);
	vector<int> vl,vr;
	for(auto v:vq) if(get(Q[v].r)-get(Q[v].l-1)<Q[v].k) vr.push_back(v);
	else vl.push_back(v);
	solve(n,mid+1,r,vr);
	for(int i=mid;i>=l;i--) update(i,n,-1);
	solve(n,l,mid,vl);
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
    	val[i]={H[i],i},pref[i]=pref[i-1]+H[i];
	}
	sort(val+1,val+n+1);
	vector<int> vq;
    for(int i=1;i<=q;i++)
    {
    	cin>>L[i]>>R[i];
    	int len=R[i]-L[i]+1;
    	if(len%2==0)
		{
			Q[++cnt]={L[i],R[i],len/2+1},vq.push_back(cnt);
			Q[++cnt]={L[i],R[i],len/2},vq.push_back(cnt);
			Q[++cnt]={L[i],R[i],len/2-1},vq.push_back(cnt);
			cnt++;
		}
		else if(len>1)
		{
			Q[++cnt]={L[i],R[i],len/2+2},vq.push_back(cnt);
			Q[++cnt]={L[i],R[i],len/2+1},vq.push_back(cnt);
			Q[++cnt]={L[i],R[i],len/2},vq.push_back(cnt);
			Q[++cnt]={L[i],R[i],len/2-1},vq.push_back(cnt);
		}
		else cnt+=4;
	}
	solve(n,1,n,vq);
	for(int i=1;i<=q;i++)
	{
		long long sum=pref[R[i]]-pref[L[i]-1],len=R[i]-L[i]+1;
		for(int j=i*4-3;j<=i*4;j++) if(!Q[j].k) F[j]=0;
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