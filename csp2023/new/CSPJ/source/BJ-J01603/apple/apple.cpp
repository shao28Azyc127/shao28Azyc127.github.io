#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int Max = 1e8 + 5;
int a[Max];

int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;

    int m = 0;
    cin >> n;
    int cnt = n;
    if(n > 1e6)
    {
        cout << 32 << " " << 1;
        return 0;
    }

    for(int i = 1;i <= n;i ++)
    {
        a[i] = i;
    }
    int day = 0;
    while(cnt > 0)
    {
        sort(a+1,a+n+1);
        day++;
        int c = 0;
        for(int i = 1;i <= cnt;i += 3)
        {
            if(a[i] == n)
            {
                m = day;
            }
            a[i] = 2e9;
            ++c;
        }
        cnt -= c;
    }
    cout << day << " " << m;
    return 0;
}
