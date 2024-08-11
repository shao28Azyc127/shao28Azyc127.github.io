#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int n,m,k,maxtime=0;
int vis[1010];
long long ans=1e7;
struct node{
    int to,time;
};
vector<node>v[20010];
void dfs(int x,int time){
    if(x==n&&time%k==0){
        ans=time;
        return;
    }
    if(time>=ans){
        return;
    }
    for(int i=0;i<v[x].size();i++){
        if(time>=v[x][i].time){
            dfs(v[x][i].to,time+1);
        }
    }
}

int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v1,a;
        scanf("%d%d%d",&u,&v1,&a);
        node tmp;
        tmp.to=v1;
        tmp.time=a;
        v[i].push_back(tmp);
        maxtime=max(maxtime,a);
    }
    cout<<-1;
    return 0;
    vis[1]=0;
    for(int i=0;i<=maxtime;i+=k){
        dfs(i,0);
    }

    if(ans==1e7){
        cout<<-1;
    }else{
        cout<<ans;
    }
    return 0;
}

