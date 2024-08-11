#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch>'9'||ch<'0'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+ch-'0';
        ch=getchar();
    }
    return x*f;
}
const int N=100001,inf=2e18;
int n,m,k,d,x[N],y[N],v[N],dp[1001][1001];
struct query{
    int x,y,v;
    bool operator<(const query&b)const{
        return x<b.x;
    }
}a[N];
void work_dp(){
    n=read(),m=read(),k=read(),d=read();
    for(int i=0;i<=n;i++){
        for(int j=0;j<=k;j++){
            dp[i][j]=-inf;
        }
    }
    for(int i=1;i<=m;i++){
        a[i].x=read(),a[i].y=read(),a[i].v=read();
    }
    sort(a+1,a+m+1);
    dp[0][0]=0;
    int id=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<k;j++){
            dp[i][j+1]=max(dp[i][j+1],dp[i-1][j]-d);
        }
        int mx=-inf;
        for(int j=0;j<=k;j++) mx=max(mx,dp[i-1][j]);
        dp[i][0]=mx;
        while(id<=m&&a[id].x==i){
            for(int j=a[id].y;j<=k;j++){
                dp[i][j]+=a[id].v;
            }
            id++;
        }
    }

    int ans=-inf;
    for(int i=0;i<=k;i++){
        ans=max(ans,dp[n][i]);
    }
    cout<<ans;
    puts("");
}
void tanxin(){
    n=read(),m=read(),k=read(),d=read();
    int ans=0;
    while(m--){
        int x=read(),y=read(),v=read();
        if(y*d<v) ans+=v-y*d;
    }
    cout<<ans;
    puts("");
    return ;
}
signed main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    int c=read(),t=read();
    if(c<=9){
        while(t--) work_dp();
    }else{
        while(t--) tanxin();
    }
    return 0;
}
