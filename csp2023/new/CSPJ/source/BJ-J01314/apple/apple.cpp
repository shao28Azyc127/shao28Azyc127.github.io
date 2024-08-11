#include <iostream>
using namespace std;
int n , dx , dy , cnt;
int f(int x , int y) {
    while (x > 0) {
        y++;
        x-=(x+2)/3;
    }
    return y-1;
}
int fn(int x , int y) {
    while (x > 0) {
        if (x % 3 == 1)
            break;
        y++;
        x-=(x+2)/3;
    }
    dx = x;
    return y+1;
}
int main () {
    freopen("apple.in" , "r" , stdin);
    freopen("apple.out" , "w" , stdout);
    cin >> n;
    dy = fn(n , 0);
    cnt = f(dx , dy);
    cout << cnt << " " << dy;
    return 0;
}
