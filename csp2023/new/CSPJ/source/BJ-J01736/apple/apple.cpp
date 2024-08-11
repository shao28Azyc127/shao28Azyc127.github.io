#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n, day = 0, end = 0;
    cin >> n;
    while(n != 0)
    {
        day++;
        int i, j;
        i = n / 3;
        j = n % 3;
        if (j > 1)
        {
            j--;
        }
        if (j == 1)
        {
            if (end == 0)
            {
                end = day;
            }
            j--;
        }
        n = i * 2 + j;
    }
    cout << day << " " << end;
    return 0;
}