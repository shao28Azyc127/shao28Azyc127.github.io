#include<bits/stdc++.h>
using namespace std;

struct X{
    int to,ti,ne;
}a[20010];
int pr[10010],k,dis[10010];
int n,m,p;
void add(int u,int v,int ti){
    a[++k]={v,ti,pr[u]};
    pr[u]=k;
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    scanf("%d%d%d",&n,&m,&p);
    bool f1=1,f2=1;
    for(int i=1,x,y,z;i<=m;i++){
        scanf("%d%d%d",&x,&y,&z);
        add(x,y,z);
        if(x>y)f2=0;
        if(z)f1=0;
    }
    if(k==1){
        queue<int>q;
        q.push(1);
        while(q.size()){
            int u=q.front();
            if(u==n){
                printf("%d",dis[n]);
                return 0;
            }
            q.pop();
            for(int i=pr[u];i;i=a[i].ne){
                int to=a[i].to;
                dis[to]=dis[u]+1;
                q.push(to);
            }
        }
        printf("-1");
        return 0;
    }
    if(f2){
        queue<int>q;
        q.push(1);
        while(q.size()){
            int u=q.front();
            if(u==n){
                if(dis[n]%k==0)printf("%d",dis[n]);
                else printf("-1");
                return 0;
            }
            q.pop();
            for(int i=pr[u];i;i=a[i].ne){
                int to=a[i].to;
                dis[to]=dis[u]+1;
                q.push(to);
            }
        }
        printf("-1");
    }
    else if(f1){

    }
    else printf("-1");
    return 0;
}
