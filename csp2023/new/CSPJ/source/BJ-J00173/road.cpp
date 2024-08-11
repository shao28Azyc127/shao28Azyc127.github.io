#include <iostream>
#include <cstdio>
#define int long long
#define N 100010
using namespace std;
int n,d,v[N],a[N],maxx[N],maxid[N],ans;
int fun(int r) {
    if (r==1) return 0;
    int maxd=maxx[r-1],id=maxid[r-1];
    int yu=fun(id);
    int miles=v[r]-v[id]-yu;
    int you=miles/d+((miles%d)>0);
    ans+=you*a[id];
    //cout << 1 << " " << r << " " << id << " " << yu << " " << miles << " " << you << endl;
    return you*d-miles;
}
signed main(void) {
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> d;
    for (int i=2;i<=n;i++) cin >> v[i],v[i]+=v[i-1];
    for (int i=1;i<=n;i++) cin >> a[i];
    maxx[0]=1e18;
    for (int i=1;i<=n;i++) {
        if (maxx[i-1]<=a[i]) {
            maxx[i]=maxx[i-1];
            maxid[i]=maxid[i-1];
        } else {
            maxx[i]=a[i];
            maxid[i]=i;
        }
        //cout << 1 << " " << i << " " << maxx[i ] << " " << maxid[i] << endl;
    }
    fun(n);
    cout << ans;
    return 0;
}
