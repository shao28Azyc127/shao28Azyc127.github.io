#include<iostream>
#include<cmath>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d,sv=0,sa=0;
    cin>>n>>d;
    int v[n-1],a[n];
    for (int i=0;i<n-1;i++) cin>>v[i];
    cin>>a[0];
    double o=0;
    int ca=a[0];
    for (int i=1;i<n;i++){
        cin>>a[i];
        sv+=v[i-1];
        if (a[i]<=ca){
            sa+=ceil(sv*1.0/d-o)*ca;
            o+=ceil(sv*1.0/d-o)-sv*1.0/d;
            sv=0;
            ca=a[i];
        }
    }
    sa+=ceil(sv*1.0/d-o)*ca;
    cout<<sa;
    return 0;
}