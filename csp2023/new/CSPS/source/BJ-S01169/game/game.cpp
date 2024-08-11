#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
typedef long long ll;
const ll N=2e6;
ll n,cnt,head=1,ans,las,vis[N+5],is[N+5];
char s[N+5];
vector< pair<ll,ll> > v;
struct Node
{
    ll pre,nex,id;
}ls[N+5];
void Delete(ll pos)
{
    cnt++;
    if(pos==head) head=ls[pos].nex;
    ls[ls[pos].nex].pre=ls[pos].pre;
    ls[ls[pos].pre].nex=ls[pos].nex;
}
ll Cal(ll len)
{
    ll res=0;
    for(ll i=2;len>=i;i+=2)
    {
        res+=len-i+1;
    }
    return res;
}
ll Cal2(ll len,ll x,ll y)
{
    ll res=0;
    for(ll i=2;len>=i;i+=2)
    {
        ll k=x;
        for(ll l=1;l<=i-1;l++) k=ls[k].nex;
        for(ll j=x/*,k=x+i-1*/;(j<=y)&&(k<=y);j=ls[j].nex,k=ls[k].nex)
        {
            //cout<<i<<" "<<j<<" "<<k<<" "<<is[j]<<" "<<is[k]<<endl;
            if(is[k]==1||is[j]==1) continue;
            vis[k]++;res++;
            v.push_back(make_pair(j,k));
            //cout<<res<<" "<<x<<" "<<y<<" "<<i<<" "<<j<<" "<<k<<endl;
        }
    }
    return res;
}
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%lld%s",&n,(s+1));
    for(ll i=1;i<=n;i++)
    {
        ls[i].id=i,ls[i].pre=i-1,ls[i].nex=i+1;
    }
    while(cnt<n)
    {
        ll op=0;
        //cout<<cnt<<endl;
        for(ll i=head;i!=n+1;i=ls[i].nex)
        {
            ll x=i,c=1;
            //cout<<i<<endl;
            while(i<n)
            {
                //cout<<i<<" ";
                if(s[ls[i].nex]!=s[i]) break;
                c++;op=1;
                i=ls[i].nex;
            }
            //cout<<i<<endl;
            if(c==1)
            {
                if(n>8000)
                {
                    ans+=las*(las+1)/2-las;
                    las=0;
                }
                continue;
            }
            las++;
            if(c%2==1)
            {
                i=ls[i].pre;
            }
            if(n>8000)
                ans+=Cal(c);//cout<<x<<" "<<i<<endl;
            else
            {
                ans+=Cal2(c,x,i);
        //cout<<ans<<" "<<x<<" "<<i<<endl;
            }
            for(ll j=x;j<=i;j=ls[j].nex)
            {
                is[j]=1;
                Delete(j);
            }
        }
        if(las!=0)
        {
            if(n>8000)
                ans+=las*(las+1)/2-las;
        }
        if(op==0) break;
    }
    if(n<=8000)
    {
        //cout<<ans<<endl;
        for(ll i=0;i<v.size();i++)
            ans+=vis[v[i].first-1];
    }
    printf("%lld",ans);
    return 0;
}
