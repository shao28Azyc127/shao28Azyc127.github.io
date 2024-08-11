#include<bits/stdc++.h>
using namespace std;
bool d[8005][8005];
int n,ans;
string a;
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    cin>>a;
    for(int i=1;i<=n;i++)
        if(a[i-1]==a[i]) d[i][i+1]=1;
    for(int l=3;l<=n;l++)
        for(int i=1;i+l-1<=n;i++){
            int j=i+l-1;
            if(a[i-1]==a[j-1]) d[i][j]|=d[i+1][j-1];
            if(d[i][j]) continue;
            for(int k=i+1;k<=j;k++)
                d[i][j]|=d[i][k]&d[k+1][j];
        }
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++) ans+=d[i][j];
    cout<<ans;
    return 0;
}