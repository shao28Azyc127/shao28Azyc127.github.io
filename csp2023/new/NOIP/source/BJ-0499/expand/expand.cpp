#include<iostream>
using namespace std;

int a[500005];
int b[500005];

int e[500005];
int d[500005];

bool check2(int x, int y, int n, int m){
    if(e[1] <= d[1] || e[n] <= d[m]) return false;
    return true;
}
bool check(int x, int y, int n, int m){
    if(a[1] <= b[1] || a[n] <= b[m]) return false;
    return true;
}

int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    int f,n,m,q; cin >> f >> n >> m >> q;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= m; i++){
        cin >> b[i];
    }
    cout << check(1,1,n,m);
    for(int i = 1; i <= q; i++){
        //for(int j = 1; j <= n; i++) e[j] = a[j];
        for(int j = 1; j <= n; j++) e[j] = a[j];
        for(int j = 1; j <= m; j++) d[j] = b[j];
        int x,y; cin >> x >> y;
        for(int j = 1; j <= x; j++){
            int o,k; cin >> o >> k;
            e[o] = k;
        }
        for(int j = 1; j <= y; j++){
            int o,k; cin >> o >> k;
            d[o] = k;
        }
        cout << check2(1,1,n,m);
    }
    return 0;
}