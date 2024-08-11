#include<bits/stdc++.h>
using namespace std;
long long n,a[100005],b[100005],c[100005],u,vv,mp1[100005],mp2[100005],ans=1000000009,vis[100005];
vector<long long>v[100005];
queue<long long>q;
deque<long long>q1;
int cmpa(long long x,long long y)
{
    return 0;
}
int cmpd(long long x,long long y)
{
    if(a[x]-(b[x]+c[x])>a[y]-(b[y]+c[y]))return 1;
    return 0;
}
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    int ca=1,cb=1,cc=0,cd=1;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i]>>c[i];
        if(c[i]>0)ca=0;
    }
    for(int i=1;i<n;i++)
    {
        cin>>u>>vv;
        v[u].push_back(vv);
        v[vv].push_back(u);
        if(u!=1)cd=0;
        if(vv!=u+1||u!=i)cb=0;
    }
    if(cd)
    {
        sort(v[1].begin(),v[1].end(),cmpd);
        v[1].push_back(0);
        for(int i=n-1;i>=0;i--)v[1][i+1]=v[1][i];
        v[1][0]=1;
        for(long long d=1;d==d;d++)
        {
            int fl=1;
            for(int i=0;i<=min(d,n);i++)
            {
                mp2[v[1][i]]+=max(b[v[1][i]]+d*c[v[1][i]],(long long)1);
                if(mp2[v[1][i]]<a[v[1][i]])fl=0;
            }
            if(d>=n&&fl==1)
            {
                cout<<d;
                return 0;
            }
        }
        return 0;
    }
    if(cb)
    {
        for(long long d=1;d==d;d++)
        {
            int fl=1;
            for(int i=1;i<=min(d,n);i++)
            {
                mp2[i]+=max(b[i]+d*c[i],(long long)1);
                if(mp2[i]<a[i])fl=0;
            }
            if(d>=n&&fl==1)
            {
                cout<<d;
                return 0;
            }
        }
        return 0;
    }
    if(ca)
    {
        q.push(1);
        while(!q.empty())
        {
            long long qf=q.front();
            vis[qf]=1;
            q.pop();
            for(int i=0;i<v[qf].size();i++)
            {
                if(!vis[v[qf][i]])
                q1.push_back(v[qf][i]);
            }
            sort(q1.begin(),q1.end(),cmpa);
        }
    }
    //caseB,caseD,caseA
    return 0;
}
