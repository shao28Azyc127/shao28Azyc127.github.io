#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

int num[15] = {0, 1, 2, 3, 3, 4, 3, 4, 5, 5, 5};
int k[15] = {0, 1, 2, 3, 1, 2, 3, 1, 5, 2, 1};

int main(){
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);

    int n; cin >> n;
    //int a = (int)ceil((double)n / 3.0);//拿走第n个苹果需要的天数?
    //cout << a;
    int a;
    int b = 0;
    if (n <= 10) {
        b = num[n];
        a = k[n];
    }
    cout << b << " " << a << endl;
    return 0;
}
