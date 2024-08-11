#include <bits/stdc++.h>
#define il inline
using namespace std;
il int read(){
    int x=0,c=getchar();
    while(!isdigit(c)) c=getchar();
    while(isdigit(c)) x=x*10+c-48,c=getchar();
    return x;
}
const int M=2005;
bool dp[M][M];
il bool ck(int a[],int n,int b[],int m){//check a>b
    if(a[1]<=b[1] || a[n]<=b[m]) return 0;
    if(n<=2 && m<=2) return 1;
    for(int i=0;i<=n;++i) for(int j=0;j<=m;++j) dp[i][j]=0;
    dp[0][0]=1;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j){
            if(a[i]>b[j]) dp[i][j]|=dp[i-1][j-1]|dp[i-1][j]|dp[i][j-1];
        }
    return dp[n][m];
}
const int N=5e5+5;
int sid,n,m,q,a[N],b[N],c[N],d[N];

int u,v,x,y;
int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    scanf("%d%d%d%d",&sid,&n,&m,&q);
    for(int i=1;i<=n;++i) a[i]=read(),c[i]=a[i];
    for(int i=1;i<=m;++i) b[i]=read(),d[i]=b[i];
    printf("%d",ck(a,n,b,m)|ck(b,m,a,n));
    while(q--){
        scanf("%d%d",&u,&v);
        for(int i=1;i<=n;++i) a[i]=c[i];
        for(int i=1;i<=m;++i) b[i]=d[i];
        while(u--) x=read(),y=read(),a[x]=y;
        while(v--) x=read(),y=read(),b[x]=y;
        printf("%d",ck(a,n,b,m)|ck(b,m,a,n));
    }
    return 0;
}
/*
1101100011110101110101111111111111111110011111111101101100000
*/
