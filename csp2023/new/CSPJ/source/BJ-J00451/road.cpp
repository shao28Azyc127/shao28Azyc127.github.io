#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

long long n,k,v[100010],a[100010],minn=1e18,c=0;

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>k;
    for(long long i=1;i<=n;i++){
        cin>>v[i];
    }
    for(long long i=1;i<=n;i++){
        cin>>a[i];
        minn=min(a[i],minn);
    }
    if(a[1]==minn){
        for(long long i=1;i<=n;i++){
            c+=v[i];
        }
        long long d=c/k;
        if(c%k!=0){
            d++;
        }
        cout<<a[1]*d;
    }
    return 0;
}
