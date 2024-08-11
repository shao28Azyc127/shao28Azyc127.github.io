#include <bits/stdc++.h>
using namespace std;
int n,d;
int u[100005]={},sum=0,y=0;
int a[100005]={};
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d",&n,&d);
    u[1]=0;
    for(int i=2;i<=n;i++){
        scanf("%d",&u[i]);
        u[i]+=u[i-1];
    }
    for(int i=1;i<=n;i++){
       scanf("%d",&a[i]);
    }
    int i=1;
    int m=min_element(a+1,a+n)-a;
    if(i==m){
        sum=u[n]/d*a[i];
    }
    while(i<n-1){
        int m=min_element(a+1,a+n)-a;
        if(i==m){
            sum+=(u[n]-y-u[i])/d*a[i];
        }
        for(int j=i;j<n;j++){
            if(a[i]>a[j]){
                sum+=(((u[j]-u[i])-y)/d+1)*a[i];
                y-=u[j]-u[i];
                y+=((u[j]-u[i])/d+1)*d;
                if(j==n-1){
                    sum+=(((u[n]-u[j])-y)/d+1)*a[j];
                }
                i=j;
                break;
            }
        }
    }
    cout<<sum;
    return 0;
}
