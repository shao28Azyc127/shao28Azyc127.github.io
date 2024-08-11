#include <iostream>
#include <cstring>
using namespace std;

int n;
bool b[1000005];
bool judge()
{
    for (int i = 1; i <= n; i++)
        if (b[i]) return false;
    return true;
}
int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    memset(b, true, sizeof(b));
    int j = 0, k = 0;
    cin >> n;
    while (!judge())
    {
        int q = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!b[i]) continue;
            if (b[i]) q++;
            if ((q - 1) % 3 == 0) b[i] = false;
        }
        if (b[n]) j++;
        k++;
    }
    cout << k << " " << j + 1;
    return 0;
}
