#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2005;
const int M=1e5+5;
const int INF=1e9+9;
int f[N][N];
int jl[N][N];
int ff[M];
int l[M],r[M],cc[M];
int S[M];
int max_x[M],qmax[M],qid[M];
int fmaxx[M];
int ll=1,rr=0;
int c,T;
signed main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    cin>>c>>T;
    if(c<=9){
        while(T--){
            int n,m,k,d;
            scanf("%lld%lld%lld%lld",&n,&m,&k,&d);
            for(int i=1;i<=n;i++){
                for(int j=0;j<=n;j++){
                    jl[i][j]=0;
                }
            }
            for(int i=1;i<=m;i++){
                int pos,y,c;
                scanf("%lld%lld%lld",&pos,&y,&c);
                jl[pos][y]+=c;
            }
            for(int i=1;i<=n;i++){
                for(int j=1;j<=i;j++){
                    jl[i][j]+=jl[i][j-1];
                }
            }
            for(int i=0;i<=n;i++){
                for(int j=0;j<=n;j++){
                    f[i][j]=-INF;
                }
            }
            f[0][0]=0;
            for(int i=0;i<n;i++){
                int limit=min(i,k);
                for(int j=0;j<=limit;j++){
                    if(j+1<=k)f[i+1][j+1]=max(f[i+1][j+1],f[i][j]+jl[i+1][j+1]-d);
                    f[i+1][0]=max(f[i][j],f[i+1][0]);
                }
            }
            /*for(int i=1;i<=n;i++){
                for(int j=0;j<=n;j++){
                    cout<<f[i][j]<<" ";
                }
                cout<<"\n";
            }*/
            int max_x=0;
            for(int i=0;i<=k;i++)max_x=max(max_x,f[n][i]);
            cout<<max_x<<"\n";
        }
        return 0;
    }
    if(c==17||c==18){
        while(T--){
            int n,m,k,d;
            scanf("%lld%lld%lld%lld",&n,&m,&k,&d);
            int ans=0;
            for(int i=1;i<=m;i++){
                int pos,y,c;
                scanf("%lld%lld%lld",&pos,&y,&c);
                if(y>k)continue;
                ans+=max(0ll,c-y*d);
            }
            cout<<ans<<"\n";
        }
        return 0;
    }
    /*if(19<=c&&c<=21){
        while(T--){
            int n,m,k,d;
            scanf("%lld%lld%lld%lld",&n,&m,&k,&d);
            int ans=0;
            for(int i=1;i<=m;i++){
                int pos,y,c;
                scanf("%lld%lld%lld",&pos,&y,&c);
                l[i]=pos-y+1;
                r[i]=pos;
                cc[i]=c;
                S[i]=S[i-1]+cc[i];
            }
            ff[0]=0;
            for(int i=1;i<=m;i++){
                ff[i]=0;
            }
            ll=1;
            rr=0;
            fmaxx[0]=0;
            for(int i=1;i<=m;i++){
                //max_x=max(max_x,ans+l[i]*d-S[i-1]);
                max_x[i]=fmaxx[i-1]+l[i]*d-S[i-1];
                while(ll<=rr&&max_x[i]>qmax[rr])rr--;
                qmax[++rr]=max_x[i];
                qid[rr]=i;
                while(ll<=rr&&r[i]-l[qid[ll]]+1>k)ll++;
                if(ll<=rr){
                    ff[i]=max(ff[i],S[i]-(r[i]+1)*d+qmax[ll]);
                }
                fmaxx[i]=max(fmaxx[i-1],ff[i]);
                ans=max(ans,ff[i]);
            }
            cout<<ans<<"\n";
            for(int i=0;i<=m;i++){
                qmax[i]=qid[i]=0;
                fmaxx[i]=0;
                ff[i]=0;
                ll=1;
                rr=0;
                S[i]=0;
                l[i]=r[i]=cc[i]=0;
            }
        }
        return 0;
    }*/
    return 0;
}