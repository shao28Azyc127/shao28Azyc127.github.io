#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int a[10005][10005];
int main(){
    //freopen("bus.in","r",stdin);
    //freopen("bus.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=1000;i++)
    for(int j=1;j<=1000;j++){
        a[i][j]=100000000;
    }
    for(int i=1;i<=m;i++){
        int a1,b1,c1;
        cin>>a1>>b1>>c1;
        a[a1][b1]=1;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                if(i!=j&&a[i][k]!=0&&a[j][k]!=1)
                    a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
            }
        }
    }


    cout<<a[1][n];
    return 0;
}