#include <iostream>
#include <cstdio>
using namespace std;
bool flag[10000005];
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,cnt = 0,cur = 0,m = 0,day = 1,num;
    cin >> n;
    for (int i = 1;i <= n;i++) flag[i] = 1;
    while(1)
    {
        if (cnt == n)
        {
            cout << day << " " << num;
            return 0;
        }
        cur++;
        if (cur > n)
        {
            cur = 1;
            day++;
            m = 0;
            continue;
        }
        if (flag[cur] == 1)
            m++;
        else continue;
        if (m % 3 == 1)
        {
            cnt++;
            flag[cur] = 0;
            if (cur == n) num = day;
        }
    }
    return 0;
}
