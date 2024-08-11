#include <cstdio>
#include <iostream>
#include <cmath>
#include <set>

using namespace std;


int main(){
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n;
    cin >> n;
    int tmp = n;
    int x = n+2;
    int cnt = 0;
    while (x >= 3){
        tmp -= x/3;
        x -= x/3;
        cnt++;
    }
    int tmp2 = n;
    int y = n+2;
    int cnt2 = 1;
    while (tmp2%3 != 1){
        tmp2 -= y/3;
        y -= y/3;
        cnt2++;
    }
    cout << cnt << " " << cnt2;
    return 0;
}