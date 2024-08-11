#include<iostream>

using namespace std;

int a[1000005];

int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        a[i] = 1;
    int nt = n, cnt = 0;
    for(int i = 1; ; i++)
    {
        if(nt == 0) break;
        if(nt % 3 == 0) nt -= nt / 3;
        else nt -= nt / 3 + 1;
        cnt++;
    }
    cout << cnt << ' ';
    if(n % 3 == 1) cout << 1 << endl;
    else
    {
        int ntt = n, ans = 0;
        while(ntt > 0)
        {
            int ct = 0;
            for(int i = 1; i <= n; i++)
            {
                if(a[i] == 1)ct++;
                if(ct % 3 == 1 && a[i] == 1)
                {
                    if(i == n)
                    {
                        cout << ans + 1 << endl;
                        return 0;
                    }
                    a[i] = 0;
                    ntt--;
                }
            }
            ans++;
        }
    }
    return 0;
}
