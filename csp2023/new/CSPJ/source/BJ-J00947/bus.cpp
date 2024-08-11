#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
ll n,k,m,ans,flag;
vector<int>a[10005];
void bfs(){
    queue <int>q;
    int vis[10005]={0};
    q.push(1);
    vis[1]=1;
    while(!q.empty()){
        ans++;
        int jkl=q.front();
        q.pop();
        for(int i=0;i<a[jkl].size();i++){
            if(!vis[a[jkl][i]]){
                q.push(a[jkl][i]);
                vis[a[jkl][i]]=1;
            }
        }
        if(vis[n])break;
    }
    if(vis[n]==0){
        cout<<-1;
        flag=1;
    }
    return;
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    int aa=0,bb,cc;
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&aa,&bb,&cc);
        a[aa].pb(bb);
    }
    ans=k;
    bfs();
    if(flag)return 0;
    cout<<(ans%k==0?ans:(ans/k+1)*k);
    return 0;
}
