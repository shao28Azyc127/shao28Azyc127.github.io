#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);

    int n, ansa = 0, ansn;
    scanf("%d", &n);
    bool apples[n];
    for (int i = 0; i < n; i++) {
        apples[i] = 1;
    }

    int count = -1;

    while (true) {
        count = -1;
        bool isnone = 1;
        for (int i = 0; i < n; i++) {
            isnone = 1;
            if (apples[i] == 1) {
                count++;
                isnone = 0;
            }
            if (count % 3 == 0) {
                apples[i] = 0;
            }
        }
        if (apples[n-1] == 0) {
            ansn = ansa;
        }
        if (isnone == 1) {
            break;
        }
        ansa++;
    }
    printf("%d %d", ansa, ansn);
    return 0;
}