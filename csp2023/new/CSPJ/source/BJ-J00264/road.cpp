#include <bits/stdc++.h>
using namespace std;

const int N=1e5+5;

int n,d,dsum;

int v,a,ans;

int mina[N],minv[N];

int main() {
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=2;i<=n;i++) {
        scanf("%d",&v);
        dsum+=v;
        minv[i]=(dsum+d-1)/d;
    }
    for(int i=1;i<=n;i++) {
        scanf("%d",&a);
        if(i==1) {
            mina[1]=a;
            continue;
        }
        if(a<mina[i-1]) {
            mina[i]=a;
        } else {
            mina[i]=mina[i-1];
        }
    }
    for(int i=2;i<=n;i++) {
        ans+=mina[i-1]*(minv[i]-minv[i-1]);
    }
    cout<<ans<<endl;
    return 0;
}
//meow
