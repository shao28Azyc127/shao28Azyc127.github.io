#include<bits/stdc++.h>
using namespace std;
int vis[6][10],cnt[6],a[9][6];
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=5;i++)cnt[i]=10;
    for(int j=1;j<=n;j++){
        for(int i=1;i<=5;i++){
            cin>>a[j][i];
            if(vis[i][a[j][i]]==0){
                vis[i][a[j][i]]=1;
                cnt[i]-=1;
            }
        }
    }
    int ans=0;
    if(n==1){
        cout<<81;
    }
    else if(n==2){
        for(int i=1;i<=5;i++){
            if(a[1][i]!=a[2][i])ans+=8;
        }
        for(int i=1;i<5;i++){
            if(a[1][i]==a[2][i]&&a[1][i+1]!=a[2][i+1]||a[1][i]!=a[2][i]&&a[1][i+1]==a[2][i+1])ans+=2;
        }
        cout<<ans;
    }
    else cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}