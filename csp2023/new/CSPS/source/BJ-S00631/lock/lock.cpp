#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define per(i,x,y) for(int i=x;i>=y;i--)
#define LL long long
#define mem(a,n) memset(a,n,sizeof(a))

inline int read(){
    int s=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
    for(;isdigit(c);c=getchar()) s=s*10+c-'0';
    return s*f;
}

const int N=12;
int f[N][N][N][N][N];

int a[7];
int n,ans;
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    n=read();
    rep(i,1,n){
        rep(j,1,5) a[j]=read();
        rep(k,1,9){
            f[(a[1]+k)%10][a[2]][a[3]][a[4]][a[5]]++;
            f[a[1]][(a[2]+k)%10][a[3]][a[4]][a[5]]++;
            f[a[1]][a[2]][(a[3]+k)%10][a[4]][a[5]]++;
            f[a[1]][a[2]][a[3]][(a[4]+k)%10][a[5]]++;
            f[a[1]][a[2]][a[3]][a[4]][(a[5]+k)%10]++;
            f[(a[1]+k)%10][(a[2]+k)%10][a[3]][a[4]][a[5]]++;
            f[a[1]][(a[2]+k)%10][(a[3]+k)%10][a[4]][a[5]]++;
            f[a[1]][a[2]][(a[3]+k)%10][(a[4]+k)%10][a[5]]++;
            f[a[1]][a[2]][a[3]][(a[4]+k)%10][(a[5]+k)%10]++;
        }
    }
    rep(i,0,9) rep(j,0,9) rep(k,0,9) rep(h,0,9) rep(w,0,9){
        if(f[i][j][k][h][w]==n) ans++;
    }

    printf("%d\n",ans);
    return 0;
}

