#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int c,n,m,q,a[500010],b[500010],aa[500010],bb[500010],maxx[500010],minn[500010];
bool can1(void) {
    int dd=n;
    for (int i=1;i<=m;i++) {
        int l=1,r=n;
        while (l<=r) {
            int mid=l+r>>1;
            if (minn[mid]<=b[i]) r=mid-1;
            else l=mid+1;
        }
        if (r==0) return 0;
        dd=r;
    }
    return dd==n;
}
bool can2(void) {
    int dd=n;
    for (int i=1;i<=m;i++) {
        int l=1,r=n;
        while (l<=r) {
            int mid=l+r>>1;
            if (maxx[mid]>=b[i]) r=mid-1;
            else l=mid+1;
        }
        if (r==0) return 0;
        dd=r;
    }
    return dd==n;
}
int main(void) {
    FILE *r=freopen("expand.in","r",stdin);
    FILE *d=freopen("expand.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> c >> n >> m >> q;
    minn[0]=1e9;
    for (int i=1;i<=n;i++) cin >> a[i],aa[i]=a[i],maxx[i]=max(maxx[i-1],a[i]),minn[i]=min(minn[i-1],a[i]);
    for (int i=1;i<=m;i++) cin >> b[i],bb[i]=b[i];
    if (can1()||can2()) cout << "1";
    else cout << "0";
    for (int xx,yy;q--;) {
        cin >> xx >> yy;
        for (int i=1,aaa,bbb;i<=xx;i++) {
            cin >> aaa >> bbb;
            a[aaa]=bbb;
        }
        for (int i=1,aaa,bbb;i<=yy;i++) {
            cin >> aaa >> bbb;
            b[aaa]=bbb;
        }
        for (int i=1;i<=n;i++) maxx[i]=max(maxx[i-1],a[i]),minn[i]=min(minn[i-1],a[i]);
        if (can1()||can2()) cout << "1";
        else cout << "0";
        for (int i=1;i<=n;i++) {a[i]=aa[i];b[i]=bb[i];}
    }
    return 0;
}
