#include <iostream>
using namespace std;
int n,d,v[100005],a[100005],mina[100005];
// bu kai long long jian zu zong
long long ans;
//v[i] is i to i+1
int main() {
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    a[0]=0x3f3f3f3f;
    mina[0]=0x3f3f3f3f;
    cin>>n>>d;
    for (int i=1;i<=n-1;i++)
        cin>>v[i];
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        if (a[i]>mina[i-1]) {
            mina[i]=mina[i-1];
        } else {
            mina[i]=a[i];
        }
    }
    int lc=0;
    for (int i=1;i<=n;i++) {
        lc+=v[i];
        if (lc>0) {
            ans+=(lc+d-1)/d*mina[i];
            lc-=(lc+d-1)/d*d;
        }
    }
    cout<<ans;
    return 0;
}
