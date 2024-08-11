#include<bits/stdc++.h>
using namespace std;
long long n,d,a[100000000],s=0;
long long b[10000000],c[10000000];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<=n-1;i++){
        cin>>a[i];
        s+=a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    int x=s/d*b[1];
    cout<<x;
    return 0;
}
