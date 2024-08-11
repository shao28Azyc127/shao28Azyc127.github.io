#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int mmap[10005][10005];
struct bus{
    int ttime;
    int nnode;
}que[10005];
int head=1,tail=1;
void bfs(int p,int t){
    que[tail].ttime=t;
    que[tail++].nnode=p;
    while(head<tail){
        for(int j=1;j<=n;j++){
            if(mmap[que[head].nnode][j]>=0){
                que[tail].ttime=que[head].ttime+1;
                que[tail].nnode=j;
                if(que[tail].nnode==n&&que[tail].ttime%k==0){
                    cout<<que[tail].ttime;
                    return;
                }
                tail++;
            }
        }
        head++;
    }
    cout<<-1;
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    memset(mmap,-1,sizeof(mmap));
    cin>>n>>m>>k;
    int maxn=0;
    for(int i=1;i<=m;i++){
        int u,v,a;
        cin>>u>>v>>a;
        mmap[u][v]=a;
        maxn=max(maxn,a);
    }
    if(maxn%k){
        maxn=maxn/k*k+k;
    }
    bfs(1,maxn);
    return 0;
}
