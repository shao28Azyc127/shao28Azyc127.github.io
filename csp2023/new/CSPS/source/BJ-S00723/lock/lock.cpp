#include<bits/stdc++.h>
using namespace std;
const int N=15,M=1e5+5;
int n,cnt[M],a[N][N],b[N],ans;
bool vis[M];
inline int getans(){
    int sum=0;
    for(int i=1;i<=5;i++)  sum=sum*10+b[i];
    return sum;
}
inline void find(int u){
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=5;i++)   b[i]=a[u][i];
    for(int i=1;i<=5;i++){
        for(int j=1;j<=9;j++){
            int t=b[i];
            b[i]=(b[i]+j)%10;
            vis[getans()]=1;
            b[i]=t;
        }
    }
    for(int i=1;i<5;i++){
        for(int j=1;j<=9;j++){
            int t1=b[i],t2=b[i+1];
            b[i]=(b[i]+j)%10;
            b[i+1]=(b[i+1]+j)%10;
            vis[getans()]=1;
            b[i]=t1,b[i+1]=t2;
        }
    }
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=5;j++)   scanf("%d",&a[i][j]);
    for(int i=1;i<=n;i++){
        find(i);
        for(int j=0;j<=99999;j++)   cnt[j]+=vis[j];
    }
    for(int j=0;j<=99999;j++)   if(cnt[j]==n)   ans++;
    printf("%d\n",ans);
    return 0;
}
