#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n;
    cin >> n;
    int nr = n;
    int cnt = 0;
    while(n)
    {
        int t = (n + 2) / 3;
        n -= t;
        cnt ++;
    }
    cout << cnt << " ";
    int id = 1;
    while(nr)
    {
        if(nr % 3 == 1)
        {
            break;
        }
        int t = (nr + 2) / 3;
        nr -= t;
        id ++;
    }
    cout << id << endl;
    return 0;
}
