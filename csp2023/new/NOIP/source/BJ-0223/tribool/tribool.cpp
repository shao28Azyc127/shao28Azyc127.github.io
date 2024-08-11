#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+10;
char ch[N];
ll f[N],zf[N];
bool b[N],vis[N];
ll n,m;
char cal_not(char inpt)
{
    if(inpt=='T')
        return 'F';
    else if(inpt=='F')
        return 'T';
    else
        return 'U';
}
pair<ll,ll> findf(ll x)//test
{
    if(vis[x])
        return make_pair(x,1);
    if(f[x]==x || f[x]==0)
        return make_pair(x,zf[x]);
    vis[x]=1;
    pair<ll,ll> temp=findf(f[x]);
    vis[x]=0;
    if(temp.second==0)
    {
        if(zf[x]==1)
            ch[x]=ch[temp.first];
        else
            ch[x]=cal_not(ch[temp.first]);
    }
    zf[x]=zf[x]*temp.second;
    f[x]=temp.first;
    return make_pair(f[x],zf[x]);
}
int main()
{
    ios::sync_with_stdio(0);
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    ll c,t;
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>m;
        memset(b,0,sizeof(b));
        for(ll i=1;i<=n;i++)
        {
            f[i]=i;
            zf[i]=1;
            ch[i]=0;
        }
        for(ll i=1;i<=m;i++)
        {
            char v;
            ll x,y;
            cin>>v;
            if(v=='T' || v=='F' || v=='U')
            {
                cin>>x;
                f[x]=0;
                zf[x]=0;
                ch[x]=v;
            }
            else if(v=='+')
            {
                cin>>x>>y;
                if(f[y])
                {
                    f[x]=f[y];
                    zf[x]=zf[y];
                    ch[x]=0;
                }
                else
                {
                    f[x]=0;
                    zf[x]=0;
                    ch[x]=ch[y];
                }
            }
            else
            {
                cin>>x>>y;
                if(f[y])
                {
                    f[x]=f[y];
                    zf[x]=-zf[y];
                    ch[x]=0;
                }
                else
                {
                    f[x]=0;
                    zf[x]=0;
                    ch[x]=cal_not(ch[y]);
                }
            }
        }
        for(ll i=1;i<=n;i++)
        {
            findf(i);
        }
        for(ll i=1;i<=n;i++)
        {
            if(f[i]==i && zf[i]==-1)
                b[i]=1;
            else if(f[i]*zf[i]==0 && ch[i]=='U')
                b[i]=1;
        }
        ll res=0;
        for(ll i=1;i<=n;i++)
        {
            if(b[i] || b[f[i]])
                res++;
        }
        cout<<res<<endl;
    }
    return 0;
}
