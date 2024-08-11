#include <iostream>

#define reg register

using namespace std;

const int maxn = 1e7 + 10;

int n;
int p[maxn];

bool check(int k)
{
    for (reg int i = 1; i <= k; i = -~i) if (!p[i]) return true;
    return false;
}

int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    
    cin >> n;
    int cnt = 0;
    while (check(n)) 
    {
        ++cnt;
        int tot = 0;
        for (reg int j = 1; j <= n; j = -~j)
            if (!p[j])
            {
                if (tot % 3 == 0) p[j] = cnt;
                tot++;
            }
    }
    // for (int i = 1; i <= n; i++) cout << p[i] << " ";
    cout << cnt << " " << p[n] << "\n";
    return 0;
}