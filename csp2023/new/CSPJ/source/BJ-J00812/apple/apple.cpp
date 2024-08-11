#include <bits/stdc++.h>
using namespace std;
int n;
int ans1, ans2;
bool ok = true;
int main()
{
    freopen("apple.in","r", stdin);
    freopen("apple.out","w", stdout);
    scanf("%d", &n);
    while(n > 0)
    {
        ans1 ++;
        if(n % 3 == 1 && ok == true)
        {
            ans2 = ans1;
            ok = false;
        }
        if(n == 1 && ok == true)
        {
            ans2 = ans1;
            break;
        }
        if(n == 2)
        {
            n --;
        }
        else
        {
            if(n % 3 != 0)
            {
                n -= (n / 3 + 1);
            }
            else
            {
                n -= n/3;
            }
        }
    }
    printf("%d %d", ans1, ans2);
    return 0;
}
