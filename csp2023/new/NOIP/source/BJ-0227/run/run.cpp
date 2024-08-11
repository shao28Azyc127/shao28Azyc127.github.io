#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,m,k,d,l[100006],r[100006],v[100006],ans,dp[1005][1005];
struct Nop{
    int ji,vi;
    friend bool operator<(const Nop& x,const Nop& y){
        return x.ji>y.ji;
    }
};
priority_queue<Nop> e[1003];
vector<Nop> f[1003];
/*
1 1 10 3 2 1
5 1 5
5 2 1
5 1 1
*/
signed main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    cin>>c>>t;
    while(t--){
        ans=0;
        cin>>n>>m>>k>>d;
        for(int i=1,y;i<=m;i++){
            cin>>r[i]>>y>>v[i];
            l[i]=r[i]-y+1;
            if(c==17||c==18){
                if(y<=k)ans+=max(0ll,v[i]-d*y);
            }
        }
        if(c==17||c==18){
            cout<<ans<<'\n';
            continue;
        }
        if(c<=9){
            for(int i=0;i<=n;i++){
                for(int j=0;j<=k;j++)dp[i][j]=-998244353ll*998244355ll;
            }
            for(int i=1;i<=n;i++){f[i].clear();}
            for(int i=1;i<=m;i++){
                int y=r[i]-l[i]+1;
                if(y>k)continue;
                e[r[i]].push((Nop){y,v[i]});
            }
            for(int i=1;i<=n;i++){
                while(!e[i].empty()){
                    Nop TT=e[i].top();e[i].pop();
                    f[i].push_back(TT);
                }
            }
            //for(int i=0;i<f[5].size();i++){cout<<f[5][i].ji<<' '<<f[5][i].vi<<" *\n";}
            dp[0][0]=0;
            for(int i=1;i<=n;i++){
                for(int j=0;j<=k;j++){
                    dp[i][0]=max(dp[i][0],dp[i-1][j]);
                }
                int cnt=f[i].size();
                for(int j=1;j<=k;j++){
                    if(j>i)break;
                    dp[i][j]=dp[i-1][j-1]-d;
                }
                int nowj=1,nowv=0,x=0;
                while(nowj<=k){
                    if(nowj>i)break;
                    while(x<cnt&&nowj==f[i][x].ji){
                        nowv+=f[i][x].vi;
                        x++;
                    }
                    dp[i][nowj]+=nowv;
                    nowj++;
                }
                for(int j=0;j<=k;j++){
                    ans=max(ans,dp[n][j]);
                }
            }
            //for(int i=1;i<=n;i++){
                //for(int j=0;j<=k;j++)cout<<dp[i][j]<<' ';
                //cout<<'\n';
            //}
            cout<<ans<<'\n';
        }
    }
    return 0;
}
