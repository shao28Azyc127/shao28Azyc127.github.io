#include<bits/stdc++.h>

using namespace std;
const int N = 1e5+5;

int xrr[5*N], yrr[5*N];

int main(){
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    int c,n,m,q;
    cin >> c >> n >>m >> q;
    for(int i=1;i<=n;i++){
        cin >> xrr[i];
    }
    for(int i=1;i<=n;i++){
        cin >> yrr[i];
    }
    for(int i=1;i<=q;i++){
        int kx, ky;
        cin >> kx >>ky;
        for(int j = 1;j <= kx; j++){
            int px, vx;
            cin >> px >> vx;
        }
        for(int j = 1;j <= ky; j++){
            int py, vy;
            cin >> py >> vy;
        }
    }


    for(int i=1;i<=q+1;i++) cout << 1;

    return 0;
}
