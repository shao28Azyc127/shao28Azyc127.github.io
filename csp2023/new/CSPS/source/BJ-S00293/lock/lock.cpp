#include<iostream>
using namespace std;
int n,a[10][6],ans=0,p[10],vis[10];
bool cc(int a,int b,int c,int d){
    for(int i=1;i<=10;i++){
        a++;
        a%=10;
        b++;
        b%=10;
        if(a==c&&b==d) return true;
    }
    return false;
}
bool check(){
    for(int i=1;i<=n;i++){
        vis[i]=0;
    }
    for(int i=1;i<=n;i++){
        int u=0;
        for(int j=1;j<=5;j++){
            if(p[j]!=a[i][j]){
                u++;
            }
        }
        if(u==1){
            vis[i]=1;
        }
    }
    for(int i=1;i<=n;i++){
        int v=0;
        for(int j=1;j<=5;j++){
            if(p[j]!=a[i][j]){
                v++;
            }
        }
        if(v!=2) continue;
        int flag=0;
        for(int j=1;j<5;j++){
            if(p[j]!=a[i][j]){
                if(p[j+1]!=a[i][j+1]){
                    if(!cc(p[j],p[j+1],a[i][j],a[i][j+1])){
                        flag=1;
                        break;
                    }
                    break;
                }else{
                    flag=1;
                    break;
                }
            }
        }
        if(flag==0){
            vis[i]=1;
        }
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==0) return false;
    }
    return true;
}
void dfs(int now){
    if(now==6){
        if(check()){
            ans++;
        }
        return;
    }
    for(int i=0;i<=9;i++){
        p[now]=i;
        dfs(now+1);
    }
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
    dfs(1);
    cout<<ans;
    return 0;
}
