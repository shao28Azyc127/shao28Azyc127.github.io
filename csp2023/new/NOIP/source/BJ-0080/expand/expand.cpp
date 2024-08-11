#include<bits/stdc++.h>
using namespace std;
int n,m,q;
int a[500010],b[500010];
int lsta[500010],lstb[500010];
bool vis[500010];
int qzh[2010][2010];
int get_ans()
{
    bool flag=(a[1]<b[1]);
    if(flag)
    {
        for(int i=1; i<=max(n,m); ++i) swap(a[i],b[i]);
        swap(n,m);
    }
    vector<int> now; now.push_back(0);
    for(int i=0; i<n; ++i)
    {
        for(int j:now) vis[j]=1;
        vector<int> gt;
        for(int j:now)
        {
            if(j!=0 && b[j]<a[i+1]) gt.push_back(j);
            int wz=j+1;
            while(wz<=m && b[wz]<a[i+1] && !vis[wz]) gt.push_back(wz),++wz; --wz;
        }
        for(int j:now) vis[j]=0;
        swap(now,gt);
    }
    bool ans=0;
    for(int i:now) ans|=(i==m);
    if(flag)
    {
        for(int i=1; i<=max(n,m); ++i) swap(a[i],b[i]);
        swap(n,m);
    }
    return ans;
}
int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0);
    int testid; cin>>testid>>n>>m>>q;
    for(int i=1; i<=n; ++i) cin>>a[i];
    for(int i=1; i<=m; ++i) cin>>b[i];
    cout<<get_ans();
    while(q--)
    {
        for(int i=1; i<=n; ++i) lsta[i]=a[i];
        for(int i=1; i<=m; ++i) lstb[i]=b[i];
        int k1,k2,x,y; cin>>k1>>k2;
        while(k1--) cin>>x>>y,a[x]=y;
        while(k2--) cin>>x>>y,b[x]=y;
        cout<<get_ans();
        for(int i=1; i<=n; ++i) a[i]=lsta[i];
        for(int i=1; i<=m; ++i) b[i]=lstb[i];
    }
    cout<<'\n';
    return 0;
}
