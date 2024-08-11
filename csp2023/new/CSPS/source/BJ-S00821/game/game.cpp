#include <bits/stdc++.h>
#define lowbit(x) (x&-x)
using namespace std;
typedef unsigned long long ll;
int const N=2e6+3,P=131;
ll pre[N],suf[N],sum[N],base[N],cnt[N];
int tree[N];
int n;
void Update(int x,int k)
{
    while(x<=n)
    {
        tree[x]+=k;
        x+=lowbit(x);
    }
}
int Query(int x)
{
    int sum=0;
    while(x)
    {
        sum+=tree[x];
        x-=lowbit(x);
    }
    return sum;
}
char s[N];
void Init()
{
    base[0]=1;
    for(int i=1;i<=N;i++) base[i]=base[i-1]*P;
}
ll huiwen(int l,int r,bool flag)
{
    if(!flag) return pre[r]-pre[l-1]*base[r-l+1];
    return suf[l]-suf[r+1]*base[r-l+1];
}
bool Solve(int l,int r)
{
    int mid=(l+r)>>1;
    if(huiwen(l,mid,0)==huiwen(mid+1,r,1)){ Update(l,1),Update(r+1,-1);return 1;}
    else if(r-l>1)
    {
        if(Query(r)-Query(l-1)==0) return 1;
        return 0;
    }
    return 0;
}
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    Init();
    ll ans=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
        pre[i]=pre[i-1]*P+s[i]-'a'+1;
        sum[i]=sum[i-1]+i;
    }
    for(int i=n;i>=1;i--)
    {
        suf[i]=suf[i+1]*P+s[i]-'a'+1;
    }
    for(int i=1;i<=n;i++)
        for(int j=i-1;j>=1;j-=2)
        {
            //cout<<"j="<<j<<" i="<<i<<endl;
            //cout<<Solve(j,i)<<endl;
            ans+=Solve(j,i);
        }
    cout<<ans<<endl;
    return 0;
}
