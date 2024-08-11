#include <iostream>
#include <cstdio>
using namespace std;

int a[11] = {0, 1, 2, 3, 3, 4, 4, 5, 5, 5, 5};
int b[11] = {0, 1, 2, 3, 1, 4, 2, 3, 5, 5, 1};

int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n;
    cin >> n;
    cout << a[n] << " " << b[n] << endl;
    return 0;
}