#include<bits/stdc++.h>
#define LL long long
#define ULL unsigned long long
using namespace std;
const int N = 2010;
int c, n, m, q;
int a[N], b[N];
int main(){
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    scanf("%d %d %d %d", &c, &n, &m, &q);
    if(c == 1){
        for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
        for(int i = 1; i <= m; i++) scanf("%d", &b[i]);
        if(a[1] == b[1]) cout << '0';
        else cout << '1';
        while(q--){
            int kx, ky;
            scanf("%d %d", &kx, &ky);
            for(int i = 1; i <= kx; i++){
                int p, x; scanf("%d %d", &p, &x);
                a[p] = x;
            }
            for(int i = 1; i <= ky; i++){
                int p, y; scanf("%d %d", &p, &y);
                b[p] = y;
            }
            if(a[1] == b[1]) cout << '0';
        else cout << '1';
        }
    }
    if(c == 2){
        for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
        for(int i = 1; i <= m; i++) scanf("%d", &b[i]);
        if((a[1] > b[1] && a[2] > b[2]) || (a[1] < b[1] && a[2] < b[2])) cout << '1';
        else cout << '0';
        while(q--){
            int kx, ky;
            scanf("%d %d", &kx, &ky);
            for(int i = 1; i <= kx; i++){
                int p, x; scanf("%d %d", &p, &x);
                a[p] = x;
            }
            for(int i = 1; i <= ky; i++){
                int p, y; scanf("%d %d", &p, &y);
                b[p] = y;
            }
            if((a[1] > b[1] && a[2] > b[2]) || (a[1] < b[1] && a[2] < b[2])) cout << '1';
            else cout << '0';
        }
    }
    cout << endl;
    return 0;
}
