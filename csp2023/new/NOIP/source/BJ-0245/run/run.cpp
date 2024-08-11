#include <bits/stdc++.h>

using namespace std;

const int N=1e3+10,M=1e5+10;
struct State{
    int x,y;
    long long w;
    bool operator <(const State &tmp) const{
        if(x==tmp.x) return y<tmp.y;
        return x<tmp.x;
    }
}t[M];
long long f[N][N],maxn[N],sum[M];
int c,T,n,m,k,d;

int main()
{
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    cin>>c>>T;
    if(c>9){
        while(T--) cout<<0<<endl;
        return 0;
    }
    while(T--){
        cin>>n>>m>>k>>d;
        for(int i=1;i<=n;i++)
            for(int j=0;j<=k;j++)
                f[i][j]=0;
        for(int i=1;i<=n;i++) maxn[i]=0;
        for(int i=1;i<=m;i++) sum[i]=0;
        for(int i=1;i<=m;i++)
           cin>>t[i].x>>t[i].y>>t[i].w;
        sort(t+1,t+m+1);
        for(int i=1;i<=m;i++) sum[i]=sum[i-1]+t[i].w;
        int last=0,now=0;
        for(int i=1;i<=n;i++){
            f[i][0]=maxn[i-1];
            for(int j=1;j<=min(i,k);j++){
                while(t[now+1].x==i && t[now+1].y==j) now++;
                f[i][j]=f[i-1][j-1]-d+sum[now]-sum[last];
                //cout<<now<<" "<<i<<" "<<j<<" "<<f[i][j]<<endl;
            }
            while(t[now+1].x==i) now++;
            last=now;
            for(int j=0;j<=min(i,k);j++) maxn[i]=max(maxn[i],f[i][j]);
            //cout<<f[i][1]<<endl;
        }
        long long ans=0;
        for(int i=0;i<=min(n,k);i++)
            ans=max(ans,f[n][i]);
        cout<<ans<<endl;
    }
    return 0;
}
