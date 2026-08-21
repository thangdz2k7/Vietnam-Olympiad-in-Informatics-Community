#include"magicianlib.h"
#include<bits/stdc++.h>
using namespace std;
int T[36],dis[36],root[36],pos[36],tdfs=0;
long long dp[9][36][9];
bool ck[36],kc[9][36][9];
vector< vector<int> > vi[9][9];
void backtrack(int i,int n,int m,int pre,vector<int> val)
{
    if(i<=n)
    {
        for(int j=pre;j<=m;j++)
        {
            val.push_back(j);
            backtrack(i+1,n,m,j,val);
            val.pop_back();
        }
    }
    else vi[m][n].push_back(val);
}
long long get(int i,int cnt,int curr)
{
    if(i>8) return 0;
    if(cnt==curr) return dp[i][cnt][curr]=1;
    if(kc[i][cnt][curr]) return dp[i][cnt][curr];
    kc[i][cnt][curr]=true;
    long long ans=0;
    for(int j=1;j<=8&&j<=cnt-curr;j++) ans+=get(i+1,cnt-curr,j)*(long long)vi[curr][j].size();
    return dp[i][cnt][curr]=ans;
}
void init()
{
    dp[0][1][1]=1;
    for(int i=1;i<=8;i++) for(int j=1;j<=8;j++)
    {
        vi[j][i].clear();
        backtrack(1,i,j,1,{});
    }
    for(int i=0;i<=8;i++) for(int j=0;j<=32;j++) for(int k=0;k<=8;k++) dp[i][j][k]=0,kc[i][j][k]=false;
    for(int i=1;i<=32;i++) get(0,i,1);
}
long long C(int k,int n)
{
    long long ans=1;
    for(int i=n;i>n-k;i--) ans=ans*i/(n+1-i);
    return ans;
}
vector<int> solveAlice(vector< vector<int> > adj)
{
    init();
    int n=adj.size();
    for(int i=0;i<n;i++) ck[i]=false;
    for(auto v:adj) for(auto u:v) ck[u]=true;
    int rt=0;
    for(int i=0;i<n;i++) if(!ck[i]) rt=i;
    queue<int> Q;
    tdfs=0,Q.push(rt),dis[rt]=0;
    while(!Q.empty())
    {
        int a=Q.front();
        Q.pop(),pos[T[a]=++tdfs]=a;
        for(auto v:adj[a]) dis[v]=dis[a]+1,root[v]=a,Q.push(v);
    }
    long long k=0;
    int pre=1,c=n;
    tdfs=1;
    for(int i=1;c-pre;i++)
    {
        int cnt=0,nex=0;
        vector< pair<int,int> > vv;
        for(int j=0;j<n;j++) if(dis[j]==i) vv.push_back({T[root[j]],j}),nex++;
        else cnt+=(dis[j]<i-1);
        sort(vv.begin(),vv.end());
        vector<int> vvv;
        for(auto v:vv) vvv.push_back(v.first-cnt),pos[T[v.second]=++tdfs]=v.second;
        for(int j=1;j<nex;j++) k+=dp[i][c-pre][j]*(long long)vi[pre][j].size();
        for(int j=0;j<vi[pre][nex].size();j++)
        {
            if(vi[pre][nex][j]==vvv) break;
            else k+=dp[i][c-pre][nex];
        }
        c-=pre,pre=nex;
    }
    int p=0;
    vector<int> ans(n);
    for(int i=1;i<=n;i++)
    {
        p++;
        while(k>=C(n-i,56-p)) k-=C(n-i,56-p),p++;
        ans[pos[i]]=p;
    }
    return ans;
}
vector< vector<int> > solveBob(vector<int> S)
{
    init();
    int n=S.size(),p=0;
    vector< vector<int> > ans(n);
    vector< pair<int,int> > vx;
    for(int i=0;i<n;i++) vx.push_back({S[i],i});
    sort(vx.begin(),vx.end());
    long long k=0;
    for(int i=0;i<n;i++)
    {
        pos[vx[i].second]=i,p++;
        while(p<vx[i].first) k+=C(n-i-1,56-p),p++;
    }
    int pre=1,c=n,s=0;
    tdfs=1;
    vector< pair<int,int> > vedges;
    for(int i=1;c-pre;i++)
    {
        int nex=1;
        while(k>=dp[i][c-pre][nex]*(long long)vi[pre][nex].size())
            k-=dp[i][c-pre][nex]*(long long)vi[pre][nex].size(),nex++;
        long long res=k/dp[i][c-pre][nex];
        k-=dp[i][c-pre][nex]*res;
        for(auto v:vi[pre][nex][res]) vedges.push_back({vx[s+v-1].second,vx[tdfs++].second});
        c-=pre,s+=pre,pre=nex;
    }
    if(vedges.size()>1) vedges[vedges.size()-1]=vedges[vedges.size()-2];
    for(auto v:vedges) ans[v.first].push_back(v.second);
    return ans;
}
