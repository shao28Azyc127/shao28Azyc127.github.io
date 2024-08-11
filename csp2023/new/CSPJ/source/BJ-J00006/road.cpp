#include<bits/stdc++.h>

using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d,a[10],b[10],c[10],e[300],mx=-1;
    cin>>n>>d;
    for(int i=0;i<n-1;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>b[i];
    for(int i=0;i<n;i++)c[i]=0;
    for(int i=0;i<pow(2,n-1);i++)e[i]=0;
    for(int i=0;i<pow(2,n-1);i++){
        for(int j=1;j<=n-1;j++){
            if((i/int(pow(2,j))%2)==1)c[j]=1;
        }
       for(int j=0;j<n-1;i++){
            if(c[j]==1){i++;e[i]+=(a[i]+a[i+1])/d;continue;}
            else {i++;e[i]+=a[i]/d;continue;}
        }
        for(int k=0;k<n;k++)c[k]=0;
    }
    for(int i=0;i<n;i++){
        if(e[i]>mx)mx=e[i];
    }
    cout<<mx;
    return 0;
}