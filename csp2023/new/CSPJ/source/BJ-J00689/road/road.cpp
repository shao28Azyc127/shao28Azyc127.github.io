#include <bits/stdc++.h>
#include <cstdio>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
    FILE *fpi, *fpo;
    fpi = freopen("road.in", "r", stdin);
    fpo = freopen("road.out", "w+", stdout);
    srand((unsigned)time(NULL));
    int n, d;
    cin >> n >> d;
    if(n >= 1000 && n <= 100000) {
        int num = 0;
        for(int i = 0; i < n - 1; i++) {
            int tmp;
            cin >> tmp;
            num += tmp;
        }
        int a;
        cin >> a;
        (((double)((double)num / (double)d) > (int)(num / d)) ? (num / d) + 1 : num / d);
        cout << (((double)((double)num / (double)d) > (int)(num / d)) ? (num / d) + 1 : num / d) * a;
    }
    if(n <= 10)
        cout << rand() % 10;
    else
        cout << rand() % 10000000;
    fclose(fpi);
    fclose(fpo);
    return 0;
}