#include <bits/stdc++.h>
using namespace std;
long long n,d,vs[100005],as[100005],v,a,money;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(long long i = 0;i<n;i++){
        cin>>v;
        vs[i] = v;
    }
    for(long long i = 0;i<n;i++){
        cin>>a;
        as[i] = a;
    }
    long long avs = 0;
    for(long long i = 0;i<n;i++){
        avs+=vs[i];
    }
    money+=avs/d*as[0];
    cout<<money;
    return 0;
}
