#include <bits/stdc++.h>
using namespace std;
int n,ans;
char s[2000010],s2[2000010];
//"s"-"a"+1;
bool vis[8010][8010];
void dfs(int f,int l){
   // cout<<f<<" "<<l<<endl;
   if(s[f-1]==s[l+1]&&!vis[f-1][l+1]&&l+1<n&&f-1>=0){
        ans++;
        vis[f-1][l+1]=1;
        dfs(f-1,l+1);
    }
    if(s[f-1]==s[f-2]&&!vis[f-2][l]&&f-1>=0&&f-2>=0){
        vis[f-2][l]=1;
        ans++;
        dfs(f-2,l);
    }
    if(s[l+1]==s[l+2]&&!vis[f][l+2]&&l+2<n&&l+1<n){
        ans++;
        vis[f][l+2]=1;
        dfs(f,l+2);
    }
    for(int i=0;i<=f-3;i++)
        if(vis[i][f-1]&&!vis[i][l]){
            ans++;
            vis[i][l]=1;
            dfs(i,l);
        }
    for(int i=l+3;i<n;i++)
        if(vis[l+1][i]&&!vis[l+1][i]){
            ans++;
            vis[l+1][i]=1;
            dfs(l+1,i);
        }
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n>>s;
    for(int i=0;i<n-1;i++)
        if(s[i]==s[i+1]){
            ans++;
            vis[i][i+1]=1;
            dfs(i,i+1);
        }
    cout<<ans;
    return 0;
}

