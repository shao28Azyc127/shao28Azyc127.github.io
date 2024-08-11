#include<bits/stdc++.h>
using namespace std;
int k[6];
int a[10][6];
int ans[100005]={0};
int check(int x){
    int gg=a[x][1]*10000+a[x][2]*1000+a[x][3]*100+a[x][4]*10+a[x][5];
    return gg;
}
void dfs1(int x,int y){
    for(int i=0;i<=9;i++){
        if(a[x][y]==i)continue;
        int k=a[x][y];
        a[x][y]=i;
        ans[check(x)]++;
        a[x][y]=k;
    }
}
void dfs2(int x,int y){
    for(int i=0;i<=9;i++){
        if(a[x][y]==i)continue;
        int k=a[x][y]-i;
        a[x][y]-=k;a[x][y+1]-=k;
        if(a[x][y+1]>=10)a[x][y+1]-=10;
        ans[check(x)]++;
        a[x][y]+=k;a[x][y+1]+=k;
        if(a[x][y+1]<0)a[x][y+1]+=10;
    }
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        memset(k,0,sizeof(k));
        for(int j=1;j<=5;j++){
            dfs1(i,j);
        }

        for(int j=1;j<=4;j++){
            dfs2(i,j);
        }
    }
    int cnt=0;
    for(int i=0;i<=99999;i++){
        if(ans[i]==n)cnt++;
    }
    cout<<cnt<<endl;
}
