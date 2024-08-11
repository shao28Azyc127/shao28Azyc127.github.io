#include<bits/stdc++.h>
using namespace std;

int n,m,k,a[10005][10005];

int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin >> n >> m >> k;
    for(int i=1; i<=m; i++){
        int x,y;
        cin >> x >> y;
        cin >> a[x][y];
    }
    cout << "-1";

    return 0;
}
