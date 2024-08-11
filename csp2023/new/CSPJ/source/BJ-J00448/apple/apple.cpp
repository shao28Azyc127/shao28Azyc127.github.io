#include <bits/stdc++.h>
using namespace std;

int a[1000001];

int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n;
    scanf("%d", &n);
    int m = n;
    int cnt = 0;
    while(n)
    {
        cnt++;
        n -= (n + 2) / 3;
        for(int i = 1, j = 2;i <= m;i++)
        {
            if(!a[i])
            {
                if(j == 2)
                {
                    a[i] = cnt;
                    j = 0;
                }
                else
                {
                    j++;
                }
            }
        }
    }
    printf("%d %d\n", cnt, a[m]);
    return 0;
}
