#include<iostream>
using namespace std;
int n,a[100005],sum,p,d;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    cin>>p;
    cout<<n/d*p;
    return 0;
}
