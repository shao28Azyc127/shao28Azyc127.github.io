#include <iostream>
using namespace std;

int getout(int k){
    int p, q;
    if (k%3 == 0){
        p = 3 * (k/3) - 2;
    }
    else{
        p = 3 * (k/3 + 1) - 2;
    }
    q = (p+2) / 3;
    return q;
}

int isOut(int k){
    long long q = k+2;
    if(q % 3 == 0) return 1;
    else return 0;
}

int main(){
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n = 1, i = 1, t, cnt = 0;
    int f = 0;
    cin >> n;
    int ttl = n, p = n;
    while (ttl > 0){
        if (f == 0) f = isOut(ttl);
        if(f == 1 && i != 0){
            cnt = i;
            f = 2;
        }
        t = getout(ttl);
        ttl = ttl - t;
        i++;
    }
    cout << i-1 << " " << cnt;
    return 0;
}
