#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N=10,L=1e6+5;
int n;
int a[N],POW10[N];
int vis[L];
ll ans=0;
void check(int num){
    vis[num]++;
    if(vis[num]==n)ans++;
}

int getnum(int num, int x){
    return (num/POW10[x])%10;
}

int turn(int num,int i,int x){
    int y=getnum(num,i),tmp=(y+x)%10-y;
    return num+tmp*POW10[i];
}

void solve(int num){
    for(int i=0;i<5;i++){
        for(int j=1;j<=9;j++){
            check(turn(num,i,j));
        }
    }
    for(int i=0;i<4;i++){
        for(int j=1;j<=9;j++){
            int tmp=turn(num,i,j);
            check(turn(tmp,i+1,j));
        }
    }
}

int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    POW10[0]=1;
    for(int i=1;i<N;i++)POW10[i]=POW10[i-1]*10;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            int x;scanf("%d",&x);
            a[i]=a[i]*10+x;
        }
    }
    for(int i=1;i<=n;i++)solve(a[i]);
    printf("%lld",ans);
    return 0;
}