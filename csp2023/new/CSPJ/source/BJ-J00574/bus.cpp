#include <bits/stdc++.h>

using namespace std;

int n,m,k,pic[20005][20005],ans = 9999999;
bool visit[20005],flag = true;

void dfs(int tim,int step){
    if(step == n){
        if(tim%k||tim>ans){
            return;
        }
        flag = false;
        ans = tim;
        return;
    }
    if(ans<tim){
        return;
    }
    visit[step] = true;
    for(int i = 1;i<=n;i++){
        if(visit[i]){
            continue;
        }
        if(tim>=pic[step][i]&&pic[step][i]!=0){
            dfs(tim+1,i);
        }
    }
    visit[step] = false;
    return;
}
int main()
{
    int maxa = 0;
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    for(int i = 1;i<=m;i++){
        int s,e;
        cin>>s>>e;
        cin>>pic[s][e];
        if(pic[s][e]==0){
            pic[s][e] = -1;
        }
        maxa = max(maxa,pic[s][e]);
    }
    dfs(0,1);
    dfs(k,1)
    if(flag){
        cout<<-1;
    }
    else{
        cout<<ans;
    }
    return 0;
}
