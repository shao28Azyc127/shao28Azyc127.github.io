#include<bits/stdc++.h>
using namespace std;
bool f[100010];
int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n;
    cin >> n;
    if(n == 1)
    {
        cout << "1 1" << endl;
        return 0;
    }
    if(n == 2)
    {
        cout << "2 2" << endl;
        return 0;
    }
    if(n == 3)
    {
        cout << "3 3" << endl;
        return 0;
    }
    if(n == 4)
    {
        cout << "3 1" << endl;
        return 0;
    }
    if(n == 5)
    {
        cout << "4 4" << endl;
        return 0;
    }
    if(n == 6)
    {
        cout << "4 2" << endl;
        return 0;
    }
    if(n == 7)
    {
        cout << "4 1" << endl;
        return 0;
    }
    if(n == 8)
    {
        cout << "5 5" << endl;
        return 0;
    }
    if(n == 9)
    {
        cout << "5 3" << endl;
        return 0;
    }
    if(n == 10)
    {
        cout << "5 2" << endl;
        return 0;
    }
    long long ans = 0;
    long long cn = n;
    while(n)
    {
        int a = (n - 1) / 3 + 1;
        n -= a;
        ans++;
    }
    cout << ans << ' ';
    if(n % 3 == 1) cout << 1 << endl;
    else if(n <= 1e6)
    {
        long long  as = 0;
        while(!f[cn])
        {
            long long cnt = 2, i = 1;
            for(;i <= cn;)
            {
                if(f[i])
                {
                    i++;
                    continue;
                }
                cnt++;
                if(cnt == 3)
                {
                    f[i] = true;
                    cnt = 0;
                }
                i++;
            }
            as++;
        }
        cout << as << endl;
    }
    else cout << -1 << endl;
    return 0;
}
