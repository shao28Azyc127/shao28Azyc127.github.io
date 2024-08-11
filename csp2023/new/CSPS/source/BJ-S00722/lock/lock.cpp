#include <iostream>
#include <cstdio>
using namespace std;
int a[15][7];
int c[7];
int n;
int check(int o)
{
    int diff = 0;
    int flag[7] = {0, 0, 0, 0, 0, 0};
    for(int i = 1; i <= 5; i++)
    {
        flag[i] = a[o][i] - c[i];
        if(flag[i] < 0) flag[i] += 10;
        diff += (flag[i] != 0);
    }
    if(diff > 2) return false;
    if(diff == 1) return 1;
    if(diff < 1) return false;
    for(int i = 1; i <= 4; i++)
        if(flag[i] && flag[i] == flag[i+1]) return 2;
    return false;
}
int main()
{
    // freopen("lock2.in", "r", stdin);
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    cin >> n;
//cout << n << endl;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i][1] >> a[i][2] >> a[i][3] >> a[i][4] >> a[i][5];
    }
    int ans = 0;
    int cnt1 = 0;
    int cnt2 = 0;

    for(c[1] = 0; c[1] <= 9; c[1]++)
    for(c[2] = 0; c[2] <= 9; c[2]++)
    for(c[3] = 0; c[3] <= 9; c[3]++)
    for(c[4] = 0; c[4] <= 9; c[4]++)
    for(c[5] = 0; c[5] <= 9; c[5]++)
    {
        int flag = 1;
        for(int i = 1; i <= n && flag; i++)
            flag = check(i);
        if(flag)
        {
            ans++;
//printf("%d %d %d %d %d = %d\n", c[1], c[2], c[3], c[4], c[5], flag);
            if(flag == 1) cnt1++;
            else cnt2++;
        }
    }
/*
    while(true)
    {
        cin >> c[1] >> c[2] >> c[3] >> c[4] >> c[5];
        for(int i = 1; i <= n; i++)
        {
            int ck = check(i);
            if(ck == 0) printf("%d: Worng\n", i);
            else if(ck == 1) printf("%d: 1\n", i);
            else printf("%d 2\n", i);
        }
    }
*/
    cout << ans << endl;
//cout << cnt1 << " " << cnt2 <<endl;
    return 0;
}
