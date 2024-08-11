//I AK CSP-J
//I AK CSP-S
//I AK NOIP
//I AK NOI
//I AK BJOI
//I AK CTSC
//I AK THUPC
//I AK IOI
//I AK ACM-ICPC
//I AK POI
//I AK ABC
//I AK ARC
//I AK AGC
//I love zwh
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
#include <map>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    for (int len = 2; len <= n; len++)
    {
        bool f = 1;
        for (int i = 0; i <= n - len; i++)
        {
            for (int j = i; j <= i + len - 1; j++)
            {
                if (s[j] != s[i + len - j - 1])
                {
                    f = 0;
                    break;
                }
            }
        }
        if (f)
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}