#include<bits/stdc++.h>
using namespace std;
#define endl "\n";

int t, m;

int main()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    cin >> t >> m;
    while(t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if(b * b - 4 * a * c < 0)
            cout << "NO" << endl;
        cout << "-" << b << "/" << 2a << endl;
    }
    return 0;
}
