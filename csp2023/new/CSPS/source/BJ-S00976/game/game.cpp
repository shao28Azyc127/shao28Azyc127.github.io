#include <iostream>

#define rep(i, a, b) for (int i = a; i <= b; i = -~i) 

using namespace std;

const int maxn = 1e6 + 10;

int n;
char str[maxn];
int f[maxn];

int main()
{
    std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);

    cin >> n;
    cin >> (str + 1);
    
    if (n <= 5005)
    {
        rep(i, 1, n - 1) 
        {
            int j = i, k = i + 1;
            while (j >= 1 && k <= n && str[j] == str[k]) j--, k++;
            f[i] = i - j;
        }
        // rep(i, 1, n - 1) cout << f[i] << " "; cout << "\n";
        int ans = 0;
        rep(i, 1, n)
        {
            rep(j, i + 1, n)
            {
                if ((j - i + 1) & 1) continue;
                int k = i, l = i;
                int flg = 1;
                while (l <= j)
                {
                    while (f[k] < k - l + 1 && k + 1 <= j) k++;
                    if (k >= j) { flg = 0; break; }
                    l += 2 * min(k - l + 1, f[k]), k = l;
                    // cout << l << " ";
                }
                // if (flg) { cout << "|" << i << " " << j << ":"; rep(d, i, j) cout << str[d]; cout << "\n"; }
                ans += flg;
            }
        }
        cout << ans << "\n";
    }
    else
    {
        int ans = 0;
        rep(i, 1, n - 1) 
        {
            int j = i, k = i + 1;
            while (j >= 1 && k <= n && str[j] == str[k]) j--, k++;
            f[i] = i - j;
            ans += f[i];
        }
        cout << ans << "\n";
    }
    return 0;
}