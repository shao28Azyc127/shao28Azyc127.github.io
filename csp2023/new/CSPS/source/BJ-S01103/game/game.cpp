#include<bits/stdc++.h>
using namespace std;
#define N 1005
int n,ans,f[N][N];
char a[N];
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    cin>>a+1;
    for(int i=1;i<n;++i) if(a[i]==a[i+1]) f[i][i+1]=1,ans++;
    for(int l=4;l<=n;++l){
        for(int i=1,j;i+l-1<=n;++i){
            j=i+l-1;
            if(a[i]==a[i+1]) f[i][j]|=f[i+2][j];
            if(a[j-1]==a[j]) f[i][j]|=f[i][j-2];
            if(a[i]==a[j]) f[i][j]|=f[i+1][j-1];
            for(int k=i;k<j;++k) f[i][j]|=(f[i][k]&f[k+1][j]);
            ans+=f[i][j];
        }
    } cout<<ans;
}
