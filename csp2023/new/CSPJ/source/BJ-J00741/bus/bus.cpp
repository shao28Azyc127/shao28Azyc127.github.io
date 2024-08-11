#include<iostream>
using namespace std;
int main(){
    int n,m,k,u,v,a,z=1,sum=0;
    cin>>n>>m>>k;
    sum=k;
    int a[n+1][n+1]={};
    for(int i=1;i<=m;i++){
        cin>>u>>v>>a;
        a[u][v]=a+1;
        a[v][u]=a+1;
    }
    while(1){
        for(int i=z+1;i<n;i++){
            if(a[z][i]>0&&a[z][i]-1<=sum){
                 z=i;
                 sum++;
                 break;
        }
        if(z==m){
            if(sum%k==0) cout<<sum;
            else{
                z=1;
               sum=k;
            }
        }
    }
    return 0;
}