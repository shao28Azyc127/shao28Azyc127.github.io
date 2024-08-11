#include<bits/stdc++.h>
using namespace std;
int n,a[9][6];
int now[6],cnt=0;
int dis(int from,int to){
    return (to+10-from)%10;
}
bool check(){
    for(int step=1;step<=n;step++){
        int cntdif=0,pt[5];
        for(int i=1;i<=5;i++){
            if(a[step][i]!=now[i]){
                pt[++cntdif]=i;
            }
        }
        if(cntdif==0){
            return false;
        }
        if(cntdif==2 and (pt[2]-pt[1]!=1 or dis(a[step][pt[2]],now[pt[2]])!=dis(a[step][pt[1]],now[pt[1]]))){
            return false;
        }
        if(cntdif>2){
            return false;
        }
    }
    return true;
}
void dfs(int step){
    if(step==6){
        if(check()){
            cnt++;
            /*for(int i=1;i<=5;i++){
                cout<<now[i]<<" ";
            }
            cout<<endl;*/
        }
        return;
    }
    for(int i=0;i<=9;i++){
        now[step]=i;
        dfs(step+1);
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
            cin>>a[i][j];
        }
    }
    dfs(1);
    cout<<cnt;
    return 0;
}