#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n;
    cin >> n;
    int cnt = 0;
    int p = -1;
    while(1){
        if(n == 0){
            break;
        }cnt++;
        if((n + 2) % 3 == 0 && p == -1)
                p = cnt;
        n -= (n + 2) / 3;
    }
    cout << cnt << " " << p;
    return 0;
}

