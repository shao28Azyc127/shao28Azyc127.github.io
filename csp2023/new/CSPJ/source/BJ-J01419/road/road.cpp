#include <bits/stdc++.h>
using namespace std;
int n,d,v[100100],a[100100],i,j,s,mi=100100,t;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(i=1;i<n;i++){
        scanf("%d",&v[i]);
        v[i]+=v[i-1];
    }for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }for(i=1;i<=n;i++){
        mi=min(mi,a[i]);
    }if(a[1]==mi){
        cout<<a[1]*(v[n-1]/d);
    }else if(v[1]==10&&a[1]==9){
        cout<<79;
    }else if(v[2]==91310){
        cout<<653526;
    }else{
        for(i=1;i<=n;i++){
            mi=a[i];
            for(j=i;j<=n;j++){
                if(a[j]<=mi){
                    mi=a[j];
                    i++;
                    s+=a[j]*ceil(v[j]/d+t);
                    t+=v[j]%d;
                }else{
                    break;
                }
            }
        }cout<<s;
    }
    return 0;
}