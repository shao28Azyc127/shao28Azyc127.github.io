#include<bits/stdc++.h>
using namespace std;
int n;
int a[10][10];
int Now[10];
bool check(int x){
    int flag=0;
    int pos[15];
    for(int i=1;i<=5;i++){
        if(Now[i]!=a[x][i])pos[++flag]=i;
    }
    if(flag==0)return 0;
    if(flag==1)return 1;
    if(flag==2){
        if(abs(pos[2]-pos[1])!=1)return 0;
        if(((Now[pos[1]]-a[x][pos[1]])%10+10)%10!=((Now[pos[2]]-a[x][pos[2]])%10+10)%10)return 0;
        return 1;
    }
    return 0;
}
int ans=0;
void dfs(int step){
    if(step==6){
        int flag=1;
        for(int i=1;i<=n;i++){
            if(check(i)==0)flag=0;
        }
        ans+=flag;
        return ;
    }
    for(int i=0;i<=9;i++)Now[step]=i,dfs(step+1);
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            cin>>a[i][j];
        }
    }
    dfs(1);
    cout<<ans;
}
