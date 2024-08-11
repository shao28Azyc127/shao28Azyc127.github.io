#include <iostream>
#include <cstdio>
using namespace std;
int n;
int day, lastFindDay;
bool flag;
int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    scanf("%d", &n);
    while(n != 0)
    {
        day++;
        if((n - 1) % 3 == 0 && !flag)
        {
            lastFindDay = day;
            flag = true;
        }
        n -= (n - 1) / 3 + 1;
    }
    cout << day << " " << lastFindDay << endl;
    return 0;
}
