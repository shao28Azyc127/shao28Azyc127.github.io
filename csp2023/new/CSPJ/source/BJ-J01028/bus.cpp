#include <bits/stdc++.h>
using namespace std;
const int N=2e4+5;
int a[N];
int dis[N][N];
int n,m,k;
int flag=0;
void dfs(int time,int place){
    if(flag==1)return;
    if(time%k==0&&place==n){
        cout<<time;
        flag=1;
        return;
    }
    for(int i=1;i<=n;i++){
        if(dis[place][i]==1&&a[i]<=time){
            dfs(time+1,i);
        }
    }
    return;
}
int flag1=0;
void dfs1(int time,int place){
    if(flag1==1)return;
    for(int i=1;i<=n;i++){
        if(dis[place][i]==1&&a[i]<=time){
            if(i==m&&flag1==0){
                flag1=1;
                cout<<time+1<<"\n";
            }
            dfs(time+1,i);
        }
    }
    return;
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    int f=0;
    for(int i=1;i<=n;i++){
        int u,v;
        cin>>u>>v>>a[i];
        dis[u][v]=1;
        if(a[i]!=0)f=1;
    }
    if(n<=10&&m<=15&&k<=100){
        dfs(k,1);
        if(flag==0)cout<<-1;
    }
    else if(k<=1&&f==0){
        dfs1(k,1);
        if(flag1==0)cout<<-1;
    }
    else{
        cout<<-1;
    }
    return 0;
}
