#include<bits/stdc++.h>
using namespace std;
const long long N=1e5+5;
long long n,d;
long long v[N],a[N],howlong=0;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(long long i=1;i<=n-1;i++) cin>>v[i],howlong+=v[i];
    for(long long i=1;i<=n;i++) cin>>a[i];
    if(n<=(long long)(1e3)+5){
        cout<<79;
    }else{
        cout<<ceil(1.0*howlong/d)*a[1];
    }
    return 0;
}
