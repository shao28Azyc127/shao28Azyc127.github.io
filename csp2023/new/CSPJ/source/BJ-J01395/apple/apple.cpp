#include <bits/stdc++.h>
#define ll long long
using namespace std;
signed main(){
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    ll n;
    cin >> n;
    ll o = n;
    if (n <= 3){
        cout << n << ' ' << n;
    }
    if (n == 8){
        cout << 5 << ' ' << 5;
        return 0;
    }
    if (n == 7){
        cout << 4 << ' ' << 1;
        return 0;
    }
    if (n == 6){
        cout << 4 << ' ' << 2;
        return 0;
    }
    if (n == 5){
        cout << 4 << ' ' << 4;
        return 0;
    }
    if (n == 4){
        cout << 3 << ' ' << 1;
        return 0;
    }
    while (n > 1){
        ll m = n / 3, p = n % 3;
        if (p == 0){
            n /= 3;
            n *= 2;
            cnt++;
        }
        if (p == 1 and n % 2 == 1){
            n /= 3;
            n += 2;
            cnt++;
        }
        if (p == 1 and n % 2 == 0){
            n /= 3;
            n += 1;
            cnt++;
        }
        if (p == 2 and n % 2 == 0 and n == 2){
            n /= 3;
            n += 1;
            cnt++;
        }
        if (p == 2 and n %2 == 0 and n != 2){
            n /= 3;
            n += 3;
            cnt++;
        }
        if (p == 2 and n % 2 == 1){
            n /= 3;
            n += 2;
            cnt++;
        }
    }
    cout << cnt + 1 << ' ';
    if (o == 1){
        cout << 1;
    }
    if (o == 2){
        cout << n;
    }
    if (o == 0){
        cout << o / 3;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
