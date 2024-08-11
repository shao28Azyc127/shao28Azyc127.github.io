//#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ifstream cin("game.in");
ofstream cout("game.out");

int sta[2000005], stacnt;
int last[2000005], dp[2000005];

int main()
{
    int n;
    string s;
    cin >> n >> s;
    if(n <= 8000)
    {
        long long ans = 0;
        for(int i = 0; i < n; i++)
        {
            stacnt = 0;
            for(int j = i; j < n; j++)
            {
                if(stacnt && s[j] == s[sta[stacnt]])
                {
                    stacnt--;
                } else {
                    sta[++stacnt] = j;
                }
                if(stacnt == 0)
                {
                    ans++;
                }
            }
        }
        cout << ans;
    } else {
        for(int i = 1; i <= n; i++)
        {
            if(stacnt && s[i - 1] == s[sta[stacnt] - 1])
            {
                last[i] = sta[stacnt--];
            } else {
                sta[++stacnt] = i;
            }
        }
        long long ans = 0;
        for(int i = 1; i <= n; i++)
        {
            if(last[i]) dp[i] = dp[last[i] - 1] + 1;
            ans += dp[i];
        }
        cout << ans;
    }
}
