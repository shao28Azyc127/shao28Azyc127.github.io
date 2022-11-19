#include<iostream>
#include<algorithm>
using namespace std;
#define int long long

signed main(){
    int n,m,maxn=-114514;
    cin>>n>>m;int a[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==1&&j!=1){
                maxn=max(maxn,a[i][j]+a[i][j+1]+a[i+1][j]+a[i][j-1]);
            }else if(j==1&&i!=1){
                maxn=max(maxn,a[i][j]+a[i][j+1]+a[i+1][j]+a[i-1][j]);
            }else if(i==1&&j==1){
                maxn=max(maxn,a[i][j]+a[i][j+1]+a[i+1][j]);
            }else if(i==n&&j!=m){
                maxn=max(maxn,a[i][j]+a[i][j+1]+a[i-1][j]+a[i][j-1]);
            }else if(j==m&&i!=n){
                maxn=max(maxn,a[i][j]+a[i][j-1]+a[i+1][j]+a[i-1][j]);
            }else if(j==m&&i==n){
                maxn=max(maxn,a[i][j]+a[i][j-1]+a[i-1][j]);
            }else{
                maxn=max(maxn,a[i][j]+a[i][j-1]+a[i+1][j]+a[i-1][j]+a[i][j-1]);
            }
        }
    }cout<<maxn;return 0;
}
