#include <bits/stdc++.h>
using namespace std;
long long n, a, b;
long long main(){
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    cin >> n;
    while(n != 0){
            ++a;
        long long t = n % 3;
        long long t2 = n / 3;
        if(t){
            t2 = t2 + 1;
        }
        n = n - t2;
        if(t == 1 && !b){
            b = a;
        }
    }
    cout << a << " " << b;
return 0;
}