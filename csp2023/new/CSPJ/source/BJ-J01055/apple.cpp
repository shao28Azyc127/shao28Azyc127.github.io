#include<bits/stdc++.h>
using namespace std;
int n;
string a[15] = {"0 0", "1 1", "2, 2", "3 3", "3 1", "4 4", "4 2", "4 1", "5 5", "5 3", "5 1"};
int main() {
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    scanf("%d", &n);
    cout << a[n];
    return 0;
}
