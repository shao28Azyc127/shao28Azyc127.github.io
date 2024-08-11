#include<iostream>
using namespace std;
int n,d,a[10000],v[10000],m=0;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++){
        cin>>v[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int minx=a[1];
    for(int i=1;i<n;i++){
        if(a[i]<minx) minx=a[i];
        m+=v[i]*minx;
    }
    cout<<m;
    return 0;
}
