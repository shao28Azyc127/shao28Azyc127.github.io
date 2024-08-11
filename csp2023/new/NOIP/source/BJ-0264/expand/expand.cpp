#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int c;
    cin >> c;
    if (c == 1)
    {
        int n, m;
        cin >> n >> m;
        int q;
        cin >> q;
        int x, y;
        cin >> x >> y;
        if (x != y) cout << 1;
        if (x == y) cout << 0;
        while (q--)
        {
            int kx, ky;
            cin >> kx >> ky;
            int t;
            int newx = x, newy = y;
            if (kx >= 1) cin >> t >> newx;
            if (ky >= 1) cin >> t >> newy;

            if (newx == newy) cout << 0;
            if (newx != newy) cout << 1;
        }
    }
    cout << endl;
    
    fclose(stdin);
    fclose(stdout);
    return 0;
}
