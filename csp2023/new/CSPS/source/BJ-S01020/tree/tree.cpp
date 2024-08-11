#include<bits/stdc++.h>
using namespace std;
int n,a[100005],b[100005],c[100005],ans=1<<30,h[100005];
bool v[5005][5005];
bool book[100005];
bool check(int x){
    for(int i=1;i<=n;i++){
        if(book[i]&&v[i][x])return 1;
    }
    return 0;
}
void dfs(int x){
    if(x>=ans)return;
    bool pd=1;
    for(int i=1;i<=n;i++){
        if(h[i]==-1){
            pd=0;
            continue;
        }
        h[i]+=max(b[i]+(x-1)*c[i],1);
        if(h[i]<a[i])pd=0;
    }
    if(pd){
        ans=min(ans,x);
        goto tz;
    }
    for(int i=1;i<=n;i++){
        if(h[i]==-1&&!book[i]&&check(i)){
            book[i]=1;
            h[i]=0;
            dfs(x+1);
            h[i]=-1;
            book[i]=0;
        }
    }
    dfs(x+1);
    tz:;
    for(int i=1;i<=n;i++){
        if(h[i]==-1)continue;
        h[i]-=max(b[i]+(x-1)*c[i],1);
    }
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)h[i]=-1;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        v[x][y]=1;
        v[y][x]=1;
    }
    h[1]=0;
    book[1]=1;
    dfs(2);
    cout<<ans-1;
    return 0;
}
