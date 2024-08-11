#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,a[100010],j,x,sum,ans=0,f[100010],v[100010],l,i;
    cin>>n>>m;
    for(i=1;i<=n-1;i++){
        cin>>v[i];
    }
    for(i=1;i<=n;i++){
        cin>>a[i];
    }
    for(i=1;i<=n-1;i++){
            f[i]=5;
        for(j=i+1;j<=n-1;j++){
            if(a[j]<a[i]){
                    f[i]=j; break;
            }
        }

    }
    x=1;
    l=0;
    while(x!=n){
        sum=0-l;
            for(i=x;i<=f[x]-1;i++) sum=sum+v[i];
    if(sum%m==0){
        ans=ans+sum/m*a[x];
        l=0;
    }
        else {
            ans=ans+(sum/m+1)*a[x];
            l=(sum/m+1)*m-sum;
        }
        x=f[x];
    }
    cout<<ans;
    return 0;
}
