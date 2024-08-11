#include<bits/stdc++.h>
using namespace std;
int n,a[10][10],now[10],d[10][10],buc[10],tmp[10][10],ans;

void dfs(int col){
    if(col==6){
        for(int i=1;i<=n;i++)
            if(buc[i]>2||!buc[i])return;
        ans++;
        return;
    }
    for(int i=1;i<=n;i++)tmp[col][i]=buc[i];
    for(int x=0;x<10;x++){
        now[col]=x;
        for(int i=1;i<=n;i++)
            d[i][col]=(a[i][col]-now[col]+10)%10;
        bool flag=1;
        for(int i=1;i<=n;i++)
            if(d[i][col]){
                if(!buc[i])buc[i]++;
                else{
                    if(buc[i]==1&&d[i][col-1]==d[i][col])buc[i]++;
                    else {
                        flag=0;
                        break;
                    }
                }
            }
        if(flag)dfs(col+1);
        for(int i=1;i<=n;i++)buc[i]=tmp[col][i];
    }
}

signed main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=5;j++)cin>>a[i][j];
    dfs(1);
    cout<<ans<<endl;
    return 0;
}