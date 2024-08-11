#include<bits/stdc++.h>
#define bigg 2147483647
using namespace std;
int s[100001][100001],dis[100001],notfound_num,pre[100001],earliest,n,m,k,now=1;
bool founded[100001];
void early(int x){
    if(x==1){
        return;
    }
    earliest=max(earliest,s[pre[x]][x]-dis[pre[x]]);
    early(pre[x]);
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    memset(s,-1,sizeof(s));
    memset(dis,-1,sizeof(dis));
    scanf("%d %d %d",&n,&m,&k);
    notfound_num=n-1;
    for(int i=1;i<=m;i++){
        int u,v,time;
        scanf("%d %d %d",&u,&v,&time);
        s[u][v]=time;
    }
    while(notfound_num){
        int minn=bigg,minm;
        for(int i=1;i<=n;i++){
            if(!founded[i]&&s[i][now]!=-1){
                if(dis[now]+1<dis[i]||dis[i]==-1){
                    dis[i]=dis[now]+1;
                    pre[i]=now;
                }
                if(dis[i]<minn){
                    minn=dis[i];
                    minm=i;
                }
            }
        }
        notfound_num--;
        founded[minm]=true;
        now=minm;
    }
    early(n);
    printf("%d",(dis[n]+earliest/3*3)/3*3);
    return 0;
}
