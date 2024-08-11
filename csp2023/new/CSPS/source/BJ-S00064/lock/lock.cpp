#include<bits/stdc++.h>
using namespace std;
int a[10][10];
int t[10];
int ans, n;
void work1(int k)
{
    if(k > 5)
    {
        int T;
        bool f;
        for(int i = 1; i <= n; i ++)
        {
            T = 0;
            f = 0;
            for(int j = 1; j <= 5; j ++)
            {
                if(t[j] != a[i][j])
                {
                    T ++;
                    if(T >= 2 && f)
                    {
                        return;
                    }
                    if(T >= 2 && !f)
                    {
                        if((t[j - 1] - a[i][j - 1] + 10) % 10 == (t[j] - a[i][j] + 10) % 10)
                        {
                            f = 1;
                        }
                        else return;
                    }
                }
            }
            if(T == 0) return;
        }
        ans ++;
        return;
    }
    for(int i = 0; i <= 9; i ++)
    {
        t[k] = i;
        work1(k + 1);
    }
}
int main()
{
	freopen("lock.in", "r", stdin);
	freopen("lock.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; j <= 5; j ++)
        {
            cin >> a[i][j];
        }
    }
    work1(1);
    cout << ans;
    return 0;
}
