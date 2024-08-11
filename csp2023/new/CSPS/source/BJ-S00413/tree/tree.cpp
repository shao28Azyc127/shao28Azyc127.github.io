#include <bits/stdc++.h>

using namespace std;

int n;
long long a[20005],b[20005],c[20005],high[20005],ans = 99999999999;
bool pic[20005][20005],finish[20005],tree[20005];

void dfs(long long x,int step){
    if(x>n){
        bool flag = true;
        for(int i = 1;i<=n;i++){
            if(finish[i]==false){
                flag = false;
                break;
            }
        }
        if(flag){
            ans = min(ans,x-1);
            return;
        }
        for(int i = 1;i<=n;i++){
            if(tree[i]){
                high[i]+=max(b[i]+x*c[i],(long long)1);
                if(high[i]>=a[i]){
                    finish[i] = true;
                }
            }
        }
        dfs(x+1,step);
        for(int i = 1;i<=n;i++){
            if(tree[i]){
                high[i]-=max(b[i]+x*c[i],(long long)1);
                if(high[i]<a[i]){
                    finish[i] = false;
                }
            }
        }
        return;
    }
    tree[step] = true;
    high[step] = 0;
    for(int i = 1;i<=n;i++){
        if(tree[i]){
            high[i]+=max(b[i]+x*c[i],(long long)1);
            if(high[i]>=a[i]){
                finish[i] = true;
            }
        }
    }
    if(x==n){
        dfs(x+1,step);
    }
    else{
        for(int i = 1;i<=n;i++){
            if(tree[i]) continue;
            for(int j = 1;j<=n;j++){
                if(pic[i][j]==1&&tree[j]){
                    dfs(x+1,i);
                }
            }
        }
    }
    for(int i = 1;i<=n;i++){
        if(tree[i]){
            high[i]-=max(b[i]+x*c[i],(long long)1);
            if(high[i]<a[i]){
                finish[i] = false;
            }
        }
    }
    tree[step] = false;
    high[step] = 0;
    return;
}
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    memset(high,sizeof(high),0);
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    for(int i = 1;i<n;i++){
        int u,v;
        cin>>u>>v;
        pic[u][v] = true;
        pic[v][u] = true;
    }
    dfs(1,1);
    cout<<ans;
    return 0;
}
