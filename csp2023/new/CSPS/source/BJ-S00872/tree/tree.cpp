#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    int n;
    cin >> n;
    int a, b, c;
    for(int i = 1; i <= n; i++)
    {
        cin >> a >> b >> c;
    }
    int u, v;
    for(int i = 1; i <= n - 1; i++)
    {
        cin >> u >> v;
    }
    return 0;
}
