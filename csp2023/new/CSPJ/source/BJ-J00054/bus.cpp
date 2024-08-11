#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int n,m,k;
int u,v,a[10000];
int x[10000][10000],y[10000];

int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>a[i];
        if(u>v) swap(u,v);
        x[u][v]=1;
    }
    for(int i=1;i<=n;i++){
        y[i]=pow(10,5);
        for(int j=i+1;j<=n;j++){
            if(x[i][j]==1){
                y[i]=min(y[i],y[j]);
            }
        }
        if(a[i]>y[n]) y[n]=a[i];
    }
    if(y[n]=pow(10,5)) y[n]=-1;
    if(y[n]!=-1){
        if(y[n]%k!=0) y[n]=y[n]+k-(y[n]%k);
    }
cout<<y[n];
    return 0;
}

