#include <bits/stdc++.h>
using namespace std;
int c[100000001];
int main(){
    int n, p = 0, q = 0;
    cin >> n;
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    for (int i = 1; i <= n; i += 3){
        c[i] = 1;
    }
    for (int r = 2; r <= n / 2 + 1; r++){
        p = 0;
        for (int i = 1; i <= n; i++){
            if (c[i] == 0){
                p++;
            }
            if (p % 3 == 1 && c[i] == 0){
                c[i] = r;
            }
        }
    }
    for (int i = 1; i <= n; i++){
        q = max(c[i], q);
    }
    cout << q << " " << c[n];
    return 0;
}