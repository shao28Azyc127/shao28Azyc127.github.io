#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n, m, a, cnt = 0, day = 0;
    cin >> n;
    a = n;
    while(n > 0)
    {
        m = (n - 1) / 3 + 1;
        n -= m;
        cnt++;
        day++;
    }
    if(a % 3 == 1)
    {
        day = 1;
    }
    cout << cnt << " " << day;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
