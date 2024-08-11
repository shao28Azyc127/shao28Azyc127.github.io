#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;
const int N=1e5+5;
int n,d,v[N],a[N],q[N],yx=0,cost[N];//
int main() {
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    forr(i,0,n) q[i] = 1e9;
    forr(i,1,n-1) scanf("%d",&v[i]);
    forr(i,1,n) {
        scanf("%d",&a[i]);
        q[i]=min(a[i],q[i-1]);
    }
    forr(i,1,n-1) {
        if(yx<v[i]) {
            cost[i] = cost[i-1] + ceil(1.0* (v[i]-yx) / d ) *q[i];
            yx = yx + ceil(1.0* (v[i]-yx) / d )*d -v[i];
        } else {
            yx -= v[i];
        }

    }
    cout<<cost[n-1];
    return 0;
}
