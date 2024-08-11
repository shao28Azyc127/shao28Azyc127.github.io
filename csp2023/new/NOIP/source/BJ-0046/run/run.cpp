#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e6+5;
const ll inf=1e18;
int c,t,len;
ll l[maxn],r[maxn],v[maxn],p[maxn],n,m,k,d,ans;
ll f[maxn],s1[maxn],s2[maxn],ml[maxn];
vector<ll> dp[maxn],w[maxn];
void solve1()
{
    ll mx;
    for(int i=0;i<=len;i++)
    {
        dp[i].resize(k+5),w[i].resize(k+5);
        for(int j=0;j<=k;j++) dp[i][j]=-inf,w[i][j]=0;
    }
    for(int i=1;i<=m;i++) if(p[r[i]]-p[l[i]]+1<=k) w[r[i]][p[r[i]]-p[l[i]]+1]+=v[i];
    for(int i=0;i<=len;i++)
        for(int j=1;j<=k;j++) w[i][j]+=w[i][j-1];
    dp[0][0]=0;
    for(int i=0;i<len;i++)
    {
        mx=-inf;
        for(int j=0;j<=k;j++) mx=max(mx,dp[i][j]);
        for(int j=0;j<=min(k,p[i+1]-p[i]-1);j++) dp[i+1][j]=max(dp[i+1][j],mx+w[i+1][j]-j*d);
        for(int j=0;j+p[i+1]-p[i]<=k;j++)
            dp[i+1][j+p[i+1]-p[i]]=max(dp[i+1][j+p[i+1]-p[i]],dp[i][j]+w[i+1][j+p[i+1]-p[i]]-(p[i+1]-p[i])*d);
    }
    for(int i=0;i<=k;i++) ans=max(ans,dp[len][i]);
}
int q[maxn],ql,qr;
void solve2()
{
    for(int i=0;i<=len;i++) f[i]=0,s1[i]=s2[i]=0,ml[i]=0;
    for(int i=1;i<=m;i++) s1[r[i]]+=v[i],s2[l[i]]+=v[i],ml[r[i]]=max(ml[r[i]],l[i]);
    for(int i=1;i<=len;i++) s1[i]+=s1[i-1],s2[i]+=s2[i-1];
    int pos=0;
    f[0]=0,ql=1,qr=1,q[1]=0;
    for(int i=1;i<=len;i++)
    {
        while(pos+1<ml[i])
        {
            pos++;
            while(ql<=qr && f[q[qr]]-s2[q[qr]]+p[q[qr]+1]*d<=f[pos]-s2[pos]+p[pos+1]*d) qr--;
            q[++qr]=pos;
        }
        f[i]=f[i-1];
        while(ql<=qr && p[i-1]-p[q[ql]+1]+1>k) ql++;
        if(ql<=qr) f[i]=max(f[i],f[q[ql]]+s1[i-1]-s2[q[ql]]-(p[i-1]-p[q[ql]+1]+1)*d);
        ans=max(ans,f[i]);
    }
}
void solve3()
{
    for(int i=0;i<=len;i++) f[i]=0,s1[i]=s2[i]=0,ml[i]=0;
    for(int i=1;i<=m;i++) s1[r[i]]+=v[i],s2[l[i]]+=v[i],ml[r[i]]=max(ml[r[i]],l[i]);
    for(int i=1;i<=len;i++) s1[i]+=s1[i-1],s2[i]+=s2[i-1];
    int pos=0;
    f[0]=0,ql=1,qr=1,q[1]=0;
    for(int i=1;i<=len;i++)
    {
        while(pos+1<ml[i])
        {
            pos++;
            while(ql<=qr && f[q[qr]]-s2[q[qr]]+p[q[qr]+1]*d<=f[pos]-s2[pos]+p[pos+1]*d) qr--;
            q[++qr]=pos;
        }
        f[i]=f[i-1];
        while(ql<=qr && p[i-1]-p[q[ql]+1]+1>k) ql++;
        if(ql<=qr) f[i]=max(f[i],f[q[ql]]+s1[i-1]-s2[q[ql]]-(p[i-1]-p[q[ql]+1]+1)*d);
        ans=max(ans,f[i]);
    }
}
int main()
{
    //system("diff run.out run4.ans -Z");
    //return 0;
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll x,y;
    cin>>c>>t;
    while(t--)
    {
        ans=len=0;
        cin>>n>>m>>k>>d;
        for(int i=1;i<=m;i++)
        {
            cin>>x>>y>>v[i];
            r[i]=x,l[i]=x-y+1;
            p[++len]=l[i],p[++len]=r[i];
            if(c>=17)
            {
                p[++len]=l[i]+1,p[++len]=r[i]+1;
                if(l[i]!=1) p[++len]=l[i]-1;
                if(r[i]!=1) p[++len]=r[i]-1;
            }
        }
        p[++len]=1;
        sort(p+1,p+1+len);
        len=unique(p+1,p+1+len)-p-1;
        for(int i=1;i<=m;i++)
        {
            l[i]=lower_bound(p+1,p+1+len,l[i])-p;
            r[i]=lower_bound(p+1,p+1+len,r[i])-p;
        }
        if(c<=11 || c==15 || c==16) solve1();
        if(c>=17 && c<=21) solve2();
        if((c>11 && c<15) || (c>21)) solve3();
        cout<<ans<<'\n';
    }
    return 0;
}
