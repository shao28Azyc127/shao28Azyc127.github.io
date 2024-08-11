#include<bits/stdc++.h>
using namespace std;
int n,d,u[1000000],a[1000000],s,ans;
int b(double x){
    for(double i=x;i<=int(x+1);i+=0.1){
    ans+=i;
    }
    return ans;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    for(int i=1;i<n;i++){
        cin>>u[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        if(u[i]%d==0) u[i]/=d;
        if(u[i]%d>0) {
        u[i]/=d;
        u[i]+=b(u[i]);
        }
        s+=a[i]*u[i];
    }
    for(int i=1;i<=n;i++){
        if(a[i]>a[i-1]){
            if(u[i]%d==0) u[i]/=d;
            if(u[i]%d>0) {
            u[i]/=d;
            u[i]+=b(u[i]);
            }
            s+=a[i]*u[i];
        }
    }
    cout<<s;
return 0;
}
