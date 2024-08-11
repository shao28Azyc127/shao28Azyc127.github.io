#include <iostream>
#include <cstring>
using namespace std;
int n,m,k,u[5005][5005][2],ans=9999999,sign[5005];
void dfs(int x,int start,int step){
    if(x==n){
        if(step%k==0){
            ans=min(start+step,ans);
        }
        return;
    }
    for(int i = 1;i<=m;i++){
        if(u[x][i][0]==1&&sign[i]==0){
            if(start+step>=u[x][i][1]){
                sign[i]=1;
                dfs(i,start,step+1);
                sign[i]=0;
            }
        }
    }

}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin >> n >> m >>k;
    memset(u,0x3f,sizeof(u));
    for(int i =1;i<=m;i++){
        int x,y,z;
        cin >> x>>y>>z;
        u[x][y][0]=1;
        u[y][x][0]=1;
        u[x][y][1]=min(u[x][y][1],z);
        u[y][x][1]=min(u[y][x][1],z);

    }
    for(int i = 0;i<=ans;i+=k){
        memset(sign,0,sizeof(sign));
        sign[1]=1;
        dfs(1,i,0);
    }
    cout << ans;
    return 0;
}
