#include<bits/stdc++.h>
using namespace std;
int n;
int zt[100][100];
int ans=0;
int a[100];
inline void check(){
    int ok=0;
    for(int i=1;i<=n;i++){
        ok=0;
        for(int j=1;j<=5;j++){
            if(a[j]!=zt[i][j]){
                ok++;
                if(j!=5&&(a[j]-zt[i][j]+10)%10==(10+a[j+1]-zt[i][j+1])%10)j++;
            }
        }
        if(ok!=1)return;
    }
    ans++;
}
void dfs(int st){
    if(st>5){
        check();
        return;
    }
    for(int i=0;i<=9;i++){
        a[st]=i;
        dfs(st+1);
    }
    return;
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            cin>>zt[i][j];
        }
    }
    dfs(1);
    cout<<ans<<endl;
    return 0;
}


