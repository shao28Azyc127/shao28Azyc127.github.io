#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct node
{
    int before_id, day;
    bool flag = true;
} a[1000010];
int n;

bool cmp(node x, node y)
{
    if (x.flag != y.flag) return x.flag > y.flag;
    return x.before_id < y.before_id;
}

int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
        a[i].before_id = i,a[i].flag = true;
    int cnt = n, d = 0;
    while (cnt > 0 && d <= n)
    { d++;
        sort(a + 1, a + n + 1, cmp);
        for (int i = 1; i <= n; i += 3)
        {
            if (!a[i].flag) break ;
            a[i].flag = false;
            a[i].day = d;
            cnt--;
        }
    }
    cout << d << " ";
    for (int i = 1; i <= n; i++)
        if (a[i].before_id == n)
        {
            cout << a[i].day << endl;
            return 0;
        }
    return 0;
}
