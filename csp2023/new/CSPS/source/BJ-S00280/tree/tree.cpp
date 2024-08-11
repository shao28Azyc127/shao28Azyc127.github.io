#include<bits/stdc++.h>
using namespace std;
vector<long long> z[1000005];
long long a[100005],b[100005],c[100005],w[100005];
long long v[1000005];
struct node
{
    long long i,d;
};
bool operator <(node a,node b)
{
    if(a.d!=b.d)
    {
        return a.d<b.d;
    }
    return w[a.i]<w[b.i];
} 
priority_queue<node> p;
long long ans;
long long cv(long long id)
{
    return (long long)((a[id]*1.0/b[id]));
}
void bfs(long long st)
{
    long long k=0;
    p.push(node{st,cv(st)});
    while(!p.empty())
    {
        node c=p.top();
        ans=max(c.d+k,ans);
        v[c.i]=1;
        p.pop();
        for(long long i=0;i<z[c.i].size();i++)
        {
            if(v[z[c.i][i]]==0)
            {
                p.push(node{z[c.i][i],cv(z[c.i][i])});
            }
        }
        k++;
    }
}
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    long long i,j,n,m,k,s=0,x,y,l,r,o;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i]>>c[i];
        b[i]=max(b[i],(long long)1);
    }
    for(i=1;i<n;i++)
    {
        cin>>x>>o;
        z[x].push_back(o);
        w[x]=max(w[x],cv(o));
    }
    bfs(1);
    cout<<ans-3;
    return 0;
}