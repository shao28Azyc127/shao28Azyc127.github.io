#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("uqe.in" , "r" , stdin);
    freopen("uqe.out" , "w" , stdout);
    int n , m , a[5003] = {} , b[5003] = {} , c[5003] = {}; cin >> n >> m;
    for (int i = 1 ; i <= n ; i++) cin >> a[i] >> b[i] >> c[i];
    for (int i = 1 ; i <= n ; i++)
    {
        if (b[i] * b[i] < 4 * a[i] * c[i])
        {
            cout << "NO" << endl;
            continue;
        }
        int k = b[i] * b[i] - 4 * a[i] * c[i];
        k = sqrt(k);
        cout << (k - b[i]) / (2 * a[i]) << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}