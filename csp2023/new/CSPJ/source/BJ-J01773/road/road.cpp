#include<bits/stdc++.h>
using namespace std;
long long s,m,z;
int n,d,u[100005],a[100005],duo;
int hj(int l){
    if(l%d)return l/d+1;
    return l/d;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++){
        cin>>u[i];
        s+=u[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    z+=a[1]*hj(s);m=a[1];
    int y1=hj(u[1]);
    duo=y1*d-u[1];
    s-=(u[1]+duo);
    for(int i=2;i<n;i++){
        if(a[i]<m){
            z=z-m*hj(s)+a[i]*hj(s);m=a[i];
        }
        u[i]-=duo;
        int y=hj(u[i]);
        duo=y*d-u[i];
        s=s-u[i]-duo;
    }
    cout<<z<<endl;
    return 0;
}