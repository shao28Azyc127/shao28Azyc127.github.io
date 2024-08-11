#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n;
    scanf("%d", &n);
    int res = 0, res2 = 0;
    bool flag = true;
    while(n > 0)
    {
        res++;
        int tmp = n / 3;
        if(n % 3 != 0)
        {
            if(flag && n % 3 == 1)
            {
                flag = false;
                res2 = res;
            }
            tmp++;
        }
        n -= tmp;
    }
    printf("%d %d", res, res2);
    return 0;
}
