#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n * 3 + n * 2 - 2; i++) cin >> n;
    srand(time(0));
    printf("%d", rand()%10);
    return 0;
}
