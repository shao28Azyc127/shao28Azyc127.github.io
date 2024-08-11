#include<bits/stdc++.h>
using namespace std;
int b[10001][10001],need1[100001],dis[100001],price[100001];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin>>n>>d;
    for(int i=2;i<=n;i++) scanf("%d",&dis[i]);
    for(int i=1;i<=n;i++) scanf("%d",&price[i]);
    for(int i=2;i<=n;i++) need1[i]=need1[i-1]+dis[i];
    for(int i=2;i<=n;i++){
        if((need1[i]/d)*d==need1[i]) need1[i]/=d;
        else need1[i]=(need1[i]+d)/d;
    }
    for(int i=2;i<=n;i++) b[1][i]=need1[i]*price[1];
    for(int i=2;i<n;i++){
        b[i][i+1]=min(b[i-1][i]+(need1[i+1]-need1[i])*price[i],b[i-1][i+1]);
        for(int j=i+2;j<=n;j++){
            b[i][j]=min(b[i][j-1]+(need1[j]-need1[j-1])*price[j-1],b[i-1][i]+(need1[j]-need1[i])*price[i]);
            b[i][j]=min(b[i][j],b[i-1][j]);
        }
    }
    cout<<b[n-1][n];
    return 0;
}
