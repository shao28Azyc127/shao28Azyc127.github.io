#include<bits/stdc++.h>
using namespace std;
#define N 10
int n,ans=0,a[N][N],b[N];
bool chk(){
    for(int i=1,s,k,d;i<=n;++i){
        s=0;
        for(int j=1;j<=5;++j) if(b[j]==a[i][j]) s++;
        if(s==5) return 0;
        if(s<3) return 0;
        if(s==3){
            k=-1;
            for(int j=1;j<=4;++j) if(b[j]!=a[i][j]&&b[j+1]!=a[i][j+1]) k=j;
            if(k==-1) return 0;
            d=(a[i][k]+10-b[k])%10;
            if((b[k+1]+d)%10!=a[i][k+1]) return 0;
        }
    } return 1;
}
void dfs(int p){
    if(p==6){
        ans+=chk();
        return;
    }
    for(int i=0;i<10;++i){
        b[p]=i;
        dfs(p+1);
        b[p]=0;
    }
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i) for(int j=1;j<=5;++j) cin>>a[i][j];
    dfs(1);
    cout<<ans;
}
