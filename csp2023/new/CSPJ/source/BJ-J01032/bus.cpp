#include <bits/stdc++.h>
using namespace std;
int n,m,k,maxn=1e9,tmp;
bool b[10005];
struct node{
    int a,b;//a为到达的点，b为开放时刻
};
vector <node> v[10005];
clock_t ttime,N=CLOCKS_PER_SEC*0.98;
void dfs(int step,int time){
    clock_t r=clock();
    if(r-ttime>=N){
        cout<<maxn;
        exit(0);
    }
    if(step==n){
        if(time%k==0) maxn=min(maxn,time);
        return;
    }
    if(time>=maxn) return;
    for(auto i:v[step]){
        if(!b[i.a]&&time+1>=i.b){
            b[i.a]=true;
            dfs(i.a,time+1);
            b[i.a]=false;
        }
    }
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    ttime=clock();
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        v[x].push_back({y,z});
        tmp=max(tmp,z);
    }
    for(int i=0;i<=tmp;i++){
        if(i%k==0) dfs(1,i);
    }
    if(maxn==1e9) maxn=-1;
    cout<<maxn;
    return 0;
}