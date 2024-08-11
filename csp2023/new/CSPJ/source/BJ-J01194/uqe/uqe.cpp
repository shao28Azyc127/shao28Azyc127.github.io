#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb emplace_back
void otp(int a, int b){
    if (a == 0) return;
    int t = __gcd(a, b);
    a /= t; b /= t;
    if (b < 0) a = -a, b = -b;
    if (b == 1) cout << a;
    else cout << a << '/' << b;
}
 void otp2(int a, int b, int c){ //a * sqrt(b) / c
     int t = __gcd(a, c);
     a /= t; c /= t;
     if (a != 1) cout << a << '*';
     cout << "sqrt(" << b << ')';
     if (c != 1) cout << '/' << c;
 }
int issq(int x){
    int t = sqrt(x);
    if (t * t == x) return t;
    if ((t - 1) * (t - 1) == x) return t - 1;
    if ((t + 1) * (t + 1) == x) return t + 1;
    return -1e9;
}
int main(){
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T, m; cin >> T >> m;
    while (T--){
        int a, b, c; cin >> a >> b >> c;
        if (a < 0) a = -a, b = -b, c = -c;
        int delta = b * b - 4 * a * c;
        if (delta < 0) { cout << "NO\n"; continue; }
        int t = issq(delta);
        if (t != -1e9){
            if (-b + t) otp(-b + t, 2 * a);
            else cout << 0;
            cout << '\n';
        }
        else{
            int k = 1;
            for (int i = 2; i * i <= delta; i++){
                while (delta % (i * i) == 0){
                    delta /= i * i;
                    k *= i;
                }
            }
            otp(-b, 2 * a);
            if (-b) cout << '+';
            otp2(k, delta, 2 * a);
            cout << '\n';
        }
    }
}
/*
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb emplace_back
char name[25];
int Rand(){
    if (RAND_MAX == 32767) return (rand() << 15) + rand();
    else return rand();
}
int issq(int x){
    int t = sqrt(x);
    if (t * t == x) return t;
    if ((t - 1) * (t - 1) == x) return t - 1;
    if ((t + 1) * (t + 1) == x) return t + 1;
    return -1e9;
}
bool subtaskC(int a, int b, int c){
    int delta = b * b - 4 * a * c;
    if (delta < 0){
        if (rand() % 1000 == 0) return 1;
    }
    int t = issq(delta);
    if (t == -1e9) return 0;
    if (a > 0) return (-b + t) % (2 * a) == 0;
    else return (-b - t) % (2 * a) == 0;
}
int M;
void get(int &a, int &b, int &c, int i){
    a = Rand() % M + 1;
    if (Rand() % 2) a = -a;

    if (i == 1 || i == 3 || i == 4) b = 0;
    else b = Rand() % M;
    if (Rand() % 2) b = -b;

    if (i == 1 || i == 5 || i == 6) c = 0;
    else c = Rand() % M;
    if (Rand() % 2) c = -c;
}
int main(){
    srand(time(0));
    for (int i = 1; i <= 10; i++){
        sprintf(name, "uqe%d.in", i);
        freopen(name, "w", stdout);
        int T = 5000 - Rand() % 100;
        if (i == 1) M = 1;
        else if (i == 2) M = 20 - rand() % 3;
        else M = 1000 - rand() % 20;
        cout << T << ' ' << M << '\n';
        while (T--){
            int a, b, c;
            get(a, b, c, i);
            if (i == 1 || i == 3 || i == 5 || i == 6 || i == 7 || i == 8){
                while (!subtaskC(a, b, c)) get(a, b, c, i);
            }
            cout << a << ' ' << b << ' ' << c << '\n';
        }
        fclose(stdout);
    }
}
*/
