#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
const int NR = 1e6 + 5;
int ans[NR] = {};
int make(int n)
{
    int sum = 0;
    for(int day = 1; sum < n && day <= 100; day++)
    {
        //printf("day%d: ", day);
        int cnt = 0;
        for(int i = 1; i <= n; i++)
            if(ans[i] == 0)
            {
                cnt++;
                if(cnt % 3 == 1){/*cout << i << " ";*/ans[i] = day;sum++;}
            }
        //cout <<endl;
    }
    int mx = 0;


    for(int i = 1; i <= n; i++)
    {
        mx = max(mx, ans[i]);
    }
    return mx;
}
int n;
int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    cin >> n;
    cout << make(n) << " " << ans[n] << endl;
    return 0;
}