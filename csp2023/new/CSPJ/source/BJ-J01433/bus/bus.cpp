#include<bits/stdc++.h>
using namespace std;
struct edge{
    int head,nxt,val;
}e[100100];
long long dis[100100];
int cnt=1,n,m,k;
priority_queue<int>q;
void add(int a,int b,int c){
    e[cnt]={a,b,c};
    cnt++;
}
void djstl(int n){
    for(int i=1;i<=n;i++){
        dis[i]=1e18;
    }
    dis[1]=0;
    q.push(1);
    while(!q.empty()){

    }
    if(dis[n]!=1e18&&dis[n]&&k==0){
        printf("%lld",dis[n]);
    }else{
        printf("-1");
    }
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c);
    }
    return 0;
}
