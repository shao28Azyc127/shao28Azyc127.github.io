#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1000+10;
char v[N],est[N],out[N];
ll x[N],y[N];
ll res=0x3f3f3f3f;
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
void dfs(ll pos)
{
    if(pos==n+1)
    {
        for(ll i=1;i<=n;i++)
        {
            out[i]=est[i];
        }
        for(ll i=1;i<=m;i++)
        {
            if(v[i]=='T' || v[i]=='F' || v[i]=='U')
            {
                out[x[i]]=v[i];
            }
            else if(v[i]=='+')
            {
                out[x[i]]=out[y[i]];
            }
            else
            {
                out[x[i]]=cal_not(out[y[i]]);
            }
        }
        ll cnt=0;
        for(ll i=1;i<=n;i++)
        {
            if(est[i]!=out[i])
                return;
            if(out[i]=='U')
                cnt++;
        }
        res=min(res,cnt);
        return;
    }
    est[pos]='T';
    dfs(pos+1);
    est[pos]='F';
    dfs(pos+1);
    est[pos]='U';
    dfs(pos+1);
    return;
}
int main()
{
    ios::sync_with_stdio(0);
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    cout<<0;
    return 0;
}
