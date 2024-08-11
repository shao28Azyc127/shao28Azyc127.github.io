#include<bits/stdc++.h>
using namespace std;
const int N=1e9+5;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,a[N],b[N];
    double d,sum=0;
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n-1;i++){
        cin>>b[i];
        sum+=b[i];
    }
    sum=ceil(sum/d);
    cout<<sum*b[1];
    return 0;
}
