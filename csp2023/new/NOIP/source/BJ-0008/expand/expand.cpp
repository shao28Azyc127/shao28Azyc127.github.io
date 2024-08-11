#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct Node
{
    int pos,val;
    Node(int pos,int val):pos(pos),val(val){}
    bool operator<(const Node &tp)const{return val!=tp.val?val<tp.val:pos<tp.pos;}
};

int _,n,m,q,p,v;
int x[500005],y[500005];
int mn[500005],mx[500005],mp[500005];
int px[500005],vx[500005],py[500005],vy[500005];
set<Node> sx,sy;

inline int sol()
{
    if(1LL*(x[1]-y[1])*(x[n]-y[m])<=0)
        return 0;

    if(x[1]>y[1])
    {
        mx[n]=mn[n]=n;
        for(int i=n-1;i;i--)
        {
            mx[i]=mx[i+1],mn[i]=mn[i+1];
            if(x[mx[i]]<=x[i])
                mx[i]=i;
            if(x[mn[i]]>x[i])
                mn[i]=i;
        }

        mp[m]=y[m];
        for(int i=m-1;i;i--)
            mp[i]=max(mp[i+1],y[i]);

        p=mx[1];

        if(x[p]<=mp[1])
            return 0;

        auto it=sy.begin();
        v=0;

        while(p!=n)
        {
            p=mn[p];

            while(it!=sy.end()&&(*it).val<x[p])
            {
                v=max(v,(*it).pos);
                it++;
            }

            if(v==0)
                return 0;

            p=mx[p];

            if(x[p]<=mp[v])
                return 0;
        }

        mx[1]=mn[1]=1;
        for(int i=2;i<=n;i++)
        {
            mx[i]=mx[i-1],mn[i]=mn[i-1];
            if(x[mx[i]]<=x[i])
                mx[i]=i;
            if(x[mn[i]]>x[i])
                mn[i]=i;
        }

        mp[1]=y[1];
        for(int i=2;i<=m;i++)
            mp[i]=max(mp[i-1],y[i]);

        p=mx[n];

        if(x[p]<=mp[m])
            return 0;

        it=sy.begin();
        v=m+1;

        while(p!=1)
        {
            p=mn[p];

            while(it!=sy.end()&&(*it).val<x[p])
            {
                v=min(v,(*it).pos);
                it++;
            }

            if(v==m+1)
                return 0;

            p=mx[p];

            if(x[p]<=mp[v])
                return 0;
        }

        return 1;
    }
    else
    {
        mx[m]=mn[m]=m;
        for(int i=m-1;i;i--)
        {
            mx[i]=mx[i+1],mn[i]=mn[i+1];
            if(y[mx[i]]<=y[i])
                mx[i]=i;
            if(y[mn[i]]>y[i])
                mn[i]=i;
        }

        mp[n]=x[n];
        for(int i=n-1;i;i--)
            mp[i]=max(mp[i+1],x[i]);

        p=mx[1];

        if(y[p]<=mp[1])
            return 0;

        auto it=sx.begin();
        v=0;

        while(p!=m)
        {
            p=mn[p];

            while(it!=sx.end()&&(*it).val<y[p])
            {
                v=max(v,(*it).pos);
                it++;
            }

            if(v==0)
                return 0;

            p=mx[p];

            if(y[p]<=mp[v])
                return 0;
        }

        mx[1]=mn[1]=1;
        for(int i=2;i<=m;i++)
        {
            mx[i]=mx[i-1],mn[i]=mn[i-1];
            if(y[mx[i]]<=y[i])
                mx[i]=i;
            if(y[mn[i]]>y[i])
                mn[i]=i;
        }

        mp[1]=x[1];
        for(int i=2;i<=n;i++)
            mp[i]=max(mp[i-1],x[i]);

        p=mx[m];

        if(y[p]<=mp[n])
            return 0;

        it=sx.begin();
        v=n+1;

        while(p!=1)
        {
            p=mn[p];

            while(it!=sx.end()&&(*it).val<y[p])
            {
                v=min(v,(*it).pos);
                it++;
            }

            if(v==n+1)
                return 0;

            p=mx[p];

            if(y[p]<=mp[v])
                return 0;
        }

        return 1;
    }
}

int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>_>>n>>m>>q;

    for(int i=1;i<=n;i++)
        cin>>x[i],sx.insert(Node(i,x[i]));

    for(int i=1;i<=m;i++)
        cin>>y[i],sy.insert(Node(i,y[i]));

    cout<<sol();

    while(q--)
    {
        int kx,ky;
        cin>>kx>>ky;

        for(int i=1;i<=kx;i++)
        {
            cin>>px[i]>>vx[i];
            sx.erase(Node(px[i],x[px[i]]));
            swap(vx[i],x[px[i]]);
            sx.insert(Node(px[i],x[px[i]]));
        }

        for(int i=1;i<=ky;i++)
        {
            cin>>py[i]>>vy[i];
            sy.erase(Node(py[i],y[py[i]]));
            swap(vy[i],y[py[i]]);
            sy.insert(Node(py[i],y[py[i]]));
        }

        cout<<sol();

        for(int i=1;i<=kx;i++)
        {
            sx.erase(Node(px[i],x[px[i]]));
            swap(vx[i],x[px[i]]);
            sx.insert(Node(px[i],x[px[i]]));
        }

        for(int i=1;i<=ky;i++)
        {
            sy.erase(Node(py[i],y[py[i]]));
            swap(vy[i],y[py[i]]);
            sy.insert(Node(py[i],y[py[i]]));
        }
    }

    cout<<'\n';

    return 0;
}
