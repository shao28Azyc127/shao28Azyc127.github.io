#include<bits/stdc++.h>
using namespace std;
#define endl "\n";

long long nx, cnt, cnt1;
double n, tmp;

void solve(double x)
{
    if(x <= 3)
    {
        cnt += x;
        return;
    }
    cnt++;
    x -= ceil(x / 3);
    solve(x);
}

void solve2(double x)
{
    if(x <= 3)
    {
        cnt1 += x;
        return;
    }
    int tmp = (int) x;
    if(tmp % 3 == 1)
    {
        cnt1++;
        return;
    }
    x -= ceil(x / 3);
    cnt1++;
    solve2(x);
}

int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    cin >> n;
    tmp = n;
    nx = (long long)n;
    solve(tmp);
    cout << cnt << " ";
    solve2(n);
    cout << cnt1;
    return 0;
}
