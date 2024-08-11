#include <bits/stdc++.h>
using namespace std;
FILE *f1=fopen("bus.in","r"),*f2=fopen("bus.out","w");
int n,m,k,u,v,a,step[10005],ans;
vector<int>g[10005];
queue<int>q;
void bfs(){
    q.push(1);
    step[1]=0;
    int x,y,z;
    while(!q.empty()){
        int x=q.front();
        int h=step[x]+1;
        for(int i=0;i<g[x].size();i++){
            y=g[x][i];
            if(step[y]>=1000000000){
                q.push(y);
                step[y]=h;
            }
        }
        q.pop();
    }
    return;
}
int main(){
    memset(step,63,sizeof(step));
    fscanf(f1,"%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        fscanf(f1,"%d%d%d",&u,&v,&a);
        g[u].push_back(v);
    }
    bfs();
    if(step[n]%k==0){
        ans=step[n];
    }else{
        ans=step[n]+step[n]%k;
    }
    fprintf(f2,"%d",ans);
    return 0;
}
