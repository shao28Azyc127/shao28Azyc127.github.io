include <bits/stdc++.h>
#define maxn 1010
using namespace std;
int a[maxn][maxn];
int dfs(int t,int j,int k,int n){
    if((t%k)==0&&j==n){
        return t;
    }
    if(n==j&&t%k!=0){
        return -1;
    }
    for(int i=1;i<=n;i++){
        if(a[j][i]>=2&&t>=a[j][i]-2){
            t++;
            dfs(t,i,k,n);
            t--;
        }
    }


}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);

    int m,n,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u1,u2,n1;
        cin>>u1>>u2>>n1;
        a[u1][u2]=n1+2;
    }
    cout<<dfs(k,1,k,n);



    return 0;
}

