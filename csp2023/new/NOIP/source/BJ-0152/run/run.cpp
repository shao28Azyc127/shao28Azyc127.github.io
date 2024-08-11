#include<bits/stdc++.h>
#define p_b push_back
#define m_p make_pair
#define pi pair<int,int>
#define p1 first
#define p2 second
#define up(i,l,r) for(int i=(l);i<=(r);++i)
#define down(i,l,r) for(int i=(l);i>=(r);--i)
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
inline ll read(){
    ll x=0;short t=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')t=-1;ch=getchar();
    }while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x*t;
}int n,m,k;ll d;
ll dp[2][maxn],f[1005][1005];
void slv2(){
    n=read(),m=read(),k=read(),d=read();
    ll res=0;
    while(m--){
        int l=read(),r=read(),v=read();
        if(r>k)continue;
        ll ret=-r*1ll*d+v;
        if(ret>0)res+=ret;
    }printf("%lld\n",res);
}
void slv(){
    n=read(),m=read(),k=read(),d=read();
    up(i,1,n)up(j,0,k)f[i][j]=0;
    up(i,1,m){
        int x=read(),y=read(),w=read();
        if(y>k)continue;
        f[x][y]+=w;
    }
    up(i,1,n)up(j,1,k)f[i][j]+=f[i][j-1];
    up(i,0,1)up(j,0,k)dp[i][j]=-1e18;
    dp[0][0]=0;
    up(i,1,n){
        int op=(i&1);
        up(j,0,k)dp[op][j]=-1e18;
        up(j,1,k){
            dp[op][j]=max(dp[op][j],dp[!op][j-1]-d+f[i][j]);
        }up(j,0,k)dp[op][0]=max(dp[op][0],dp[!op][j]+f[i][0]);
    }ll res=0;
    int op=n&1;
    up(i,0,k)res=max(res,dp[op][i]);
    printf("%lld\n",res);
}int main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    int id=read();
    int t=read();while(t--){
        if(id>=17&&id<=18)slv2();
        else slv();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}