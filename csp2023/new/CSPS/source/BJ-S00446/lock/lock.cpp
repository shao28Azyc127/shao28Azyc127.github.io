#include<bits/stdc++.h>
using namespace std;
int vis[10],ans,n,a[10][10],b[10];
void dfs(int now){
    if(now>5){
        for(int i=1;i<=n;i++){
            //a[i][0]~a[i][4] he vis[0]~vis[4]
            int sum=0,f=0;
            for(int j=0;j<5;j++){
                b[j]=(vis[j+1]-a[i][j]+10+10)%10;
                sum+=b[j];
            }
            if(sum==0)return;
            for(int j=0;j<5;j++){
                if(b[j]==sum){
                    f=1;
                    break;
                }
            }
            if(b[0]==b[1]&&b[0]*2==sum)f=1;
            if(b[2]==b[1]&&b[1]*2==sum)f=1;
            if(b[2]==b[3]&&b[2]*2==sum)f=1;
            if(b[3]==b[4]&&b[3]*2==sum)f=1;
            if(f==0)return;
        }
        ans++;
        return;
    }
    for(int i=0;i<10;i++){
        vis[now]=i;
        dfs(now+1);
    }
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=0;j<5;j++)cin>>a[i][j];
    }
    dfs(1);
    cout<<ans;
    return 0;
}
