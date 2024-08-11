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
}int n,m,q,a[maxn],b[maxn],ta[maxn],tb[maxn],dp[2005][2005];
int qry(){
    if(a[1]==b[1])return 0;
    if(a[1]>b[1]){
        up(i,1,n)up(j,1,m)dp[i][j]=0;
        dp[1][1]=1;
        up(j,1,m)up(i,1,n){
            if(a[i]>b[j])dp[i][j]|=dp[i-1][j],dp[i][j]|=dp[i][j-1],dp[i][j]|=dp[i-1][j-1];
        }return dp[n][m];
    }else {
        up(i,1,n)up(j,1,m)dp[i][j]=0;
        dp[1][1]=1;
        up(j,1,m)up(i,1,n){
            if(a[i]<b[j])dp[i][j]|=dp[i-1][j],dp[i][j]|=dp[i][j-1],dp[i][j]|=dp[i-1][j-1];
        }return dp[n][m];
    }
}
void slv(){
    read();n=read(),m=read(),q=read();
    up(i,1,n)ta[i]=a[i]=read();up(i,1,m)tb[i]=b[i]=read();
    printf("%d",qry());
    up(i,1,q){
        int kx=read(),ky=read();
        up(i,1,n)a[i]=ta[i];up(i,1,m)b[i]=tb[i];
        while(kx--){
            int x=read(),y=read();
            a[x]=y;
        }while(ky--){
            int x=read(),y=read();
            b[x]=y;
        }printf("%d",qry());
    }
}int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    slv();
    fclose(stdin);
    fclose(stdout);
    return 0;
}