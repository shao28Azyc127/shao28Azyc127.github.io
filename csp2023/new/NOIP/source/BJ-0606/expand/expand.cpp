#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int N = 5e5+5;
int c, n, m, q;
int x[N], y[N], yp, xp, ox[N], oy[N];

bool query(){
    xp = yp = 1;
    while(xp<=n&&yp<=m){
        while(x[xp]<=y[yp]){
            if(!xp) return false;
            xp--;
        }
        if(yp<m) yp++;
        xp++;
    }
    return true;
}

int main(){
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    cin >> c >> n >> m >> q;
    for(int i=1;i<=n;i++) cin >> ox[i];
    for(int i=1;i<=m;i++) cin >> oy[i];
    if(ox[1]<oy[1]) swap(ox, oy);
    // for(int i=1;i<=n;i++) cout << ox[i] << ' '; cout << endl;
    // for(int i=1;i<=m;i++) cout << oy[i] << ' '; cout << endl;
    memcpy(x, ox, sizeof(ox));
    memcpy(y, oy, sizeof(oy));
    if(ox[n]>oy[m]) cout << query();
    else cout << 0;
    int kx, ky, p, v;
    for(int i=1;i<=q;i++){
        memcpy(x, ox, sizeof(ox));
        memcpy(y, oy, sizeof(oy));
        cin >> kx >> ky;
        for(int j=1;j<=kx;j++)
            cin >> p >> v, x[p] = v;
        for(int j=1;j<=ky;j++)
            cin >> p >> v, y[p] = v;
        if(x[1]<y[1]) swap(x, y);
        if(x[n]>y[m]) cout << query();
        else cout << 0;
    }
}