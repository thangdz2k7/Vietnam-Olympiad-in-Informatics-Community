#include"testlib.h"
#include<iostream>
using namespace std;
const int MAXN=4e5+5;
const int INF=1e9;
map<int,int> mp;
int A[MAXN],B[MAXN];
int main(int argc,char* argv[])
{
    registerGen(argc,argv,1);
    int lln=atoi(argv[1]),rrn=atoi(argv[2]),q=atoi(argv[3]),mx=atoi(argv[4]),mdiff=atoi(argv[5]);
    bool ck=atoi(argv[6]),saw=atoi(argv[7]);
    int n=rrn;
    if(!ck) n=rnd.wnext(lln,rrn,3);
    cout<<n<<" "<<q<<"\n";
    for(int i=1;i<=mdiff;i++) mp[i]=rnd.next(1,mx);
    for(int i=1;i<=n;i++) A[i]=mp[rnd.next(1,mdiff)];
    if(saw)
    {
    	for(int i=1;i<=n;i++) B[i]=A[i];
    	sort(B+1,B+n+1);
    	int lt=1,rt=n/2+1;
    	for(int i=1;i<=n;i++) if(lt<n/2+1&&rt<n)
    	{
    		if(rnd.next(1,2)==1) A[i]=B[lt++];
    		else A[i]=B[rt++];
		}
		else if(lt<n/2+1) A[i]=B[lt++];
		else A[i]=B[rt++];
	}
	for(int i=1;i<=n;i++)
	{
		cout<<A[i];
		if(i<n) cout<<" ";
	}
    cout<<"\n";
    for(int i=1;i<=q;i++)
    {
        int l=rnd.next(1,n),r=rnd.next(1,n);
        if(l>r) swap(l,r);
        if(rnd.next(1,250)==1) r=min(n,l+rnd.next(0,3));
        cout<<l<<" "<<r<<"\n";
    }
    return 0;
}