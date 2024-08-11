//I AK CSP-J
//I AK CSP-S
//I AK NOIP
//I AK NOI
//I AK BJOI
//I AK CTSC
//I AK THUPC
//I AK IOI
//I AK ACM-ICPC
//I AK POI
//I AK ABC
//I AK ARC
//I AK AGC
//I love zwh
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
#include <map>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#define int long long

struct node
{
    int a, b, c;
    int delta;
}t[100005];

bool cmp(node x, node y)
{
    return x.delta < y.delta;
}

vector<int> v[100005];

signed main()
{
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> t[i].a >> t[i].b >> t[i].c;
        t[i].delta = t[i].b + t[i].c;
    }
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    node mi;
    mi.delta = 2e18;
    //for (int i = 1; )
    cout << n << endl;
    return 0;
}