#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int n,a[10][10],b[10],ans;
bool check(){
    int vis[10],index=0;
    for(int i=1;i<=n;i++){
        memset(vis,0,sizeof(vis));
        int cnt=0;
        for(int j=1;j<=5;j++){
            if(a[i][j]!=b[j]){
                cnt++;
                vis[j]=1;
                index=j;
                if(cnt>1&&!vis[j-1]){
                    return false;
                }
                if(cnt>2){
                    return false;
                }
            }
        }
        if(cnt==0||cnt>2){
            return false;
        }
        if(cnt==1){
            continue;
        }
        if((b[index-1]+(a[i][index]-a[i][index-1]+10)%10)%10!=b[index]){
            return false;
        }
    }
    return true;
}
void dfs(int x){
    if(x==5){
        if(check()){
            ans++;
        }
        return;
    }
    if(x>5){
        return;
    }
    for(int i=0;i<=9;i++){
        b[x+1]=i;
        dfs(x+1);
    }
    return;
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            cin>>a[i][j];
        }
    }
    dfs(0);
    cout<<ans<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
