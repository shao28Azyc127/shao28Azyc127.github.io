#include <bits/stdc++.h>
using namespace std;
int n;
int a[10][10];
int ans=0,as2=0;
int dig[10];
int f[10][10];
int sm[10];
void dfs(int cur){
    if(cur==6){
        int x[10],cnt=0;
        bool flag=true,vis=false;;
        for(int i=1;i<=n;i++){
            cnt=0;
            for(int j=1;j<=5;j++){
                if(f[j][i]==1) x[++cnt]=j;
            }
            if(cnt>2||cnt==0){
                flag=false;
                break;
            }
            else if(cnt==2){
                if(x[1]-x[2]!=1&&x[1]-x[2]!=-1){
                    flag=false;
                    break;
                }
                else if((9-a[i][x[1]]+dig[x[1]])%10!=(9-a[i][x[2]]+dig[x[2]])%10){
                    flag=false;
                    break;
                }
                else vis=true;
            }
        }
        if(flag){
            ans++;
        }
        return ;
    }
    for(int i=0;i<=9;i++){
        bool flag=true;
        for(int j=1;j<=n;j++){
            if(i!=a[j][cur]) f[cur][j]=1;
        }
        dig[cur]=i;
        if(cur>=3){
            for(int j=1;j<=n;j++){
                if(f[cur][j]==1&&f[cur-1][j]==1){
                   if((9-a[j][cur]+dig[cur])%10!=(9-a[j][cur-1]+dig[cur-1])%10) flag=false;
                }
            }
        }
        if(flag==false ){
            for(int j=1;j<=n;j++){
                if(i!=a[j][cur]) f[cur][j]=0;
            }continue;
        } 
        dfs(cur+1);
        for(int j=1;j<=n;j++){
            if(i!=a[j][cur]) f[cur][j]=0;
        }
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
}