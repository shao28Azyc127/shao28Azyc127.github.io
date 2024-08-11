#include <bits/stdc++.h>
#define N 1000001
//#define N 1001
using namespace std;
bool b[N];
int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n;
    cin >> n;
    int c=1, pointe = 1;
    short d=-1;//d = 0, 1, 2;d=1, shan
    int nn = n;
    int len = n, ans1, ans2 = -1, begi = 1;
    while (true)
    {
        if (b[begi])
        {
            begi ++;;
        }
        if (b[len])
        {
            if (len == n)
            {
                ans2 = c;
            }
            len --;
        }
        if (pointe > len)
        {
            c ++;
            pointe = begi;
            d = -1;
            continue;
        }
        if (b[pointe] == true)
        {
            pointe ++;
            continue;
        }
        if (b[pointe] == false)
        {
            d ++;
            d %= 3;
            if (d == 0)
            {
                nn --;
                b[pointe] = true;
            }
            pointe ++;
        }
        if (nn == 0)
        {
            ans1 = c;
            if (b[n] && ans2 == -1)
            {
                ans2 = c;
            }
            break;
        }
    }
    cout << ans1 << ' ' << ans2 << endl;
    return 0;
}
