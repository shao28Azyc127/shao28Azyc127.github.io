#include <bits/stdc++.h>
using namespace std;

int c, n, m, q;

int main()
{
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    cin >> c >> n >> m >> q;
    if(c >= 8 && c <= 14)
    {
        long long x[1000005], y[1000005];
        for(int i = 1; i <= n; i++)
        {
            cin >> x[i];
        }
        for(int i = 1; i <= m; i++)
        {
            cin >> y[i];
        }
        if(x[n] > y[m])
            cout << 1;
        else
            cout << 0;
        for(int i = 1; i <= q; i++)
        {
            long long a,b;
            cin >> a >> b;
            for(int j =1 ; j <= a; j++)
            {
                long long temp, temp1;
                cin >> temp >> temp1;
                x[temp] = temp1;
            }
            for(int j = 1; j <= b; j++)
            {
                int temp, temp1;
                cin >> temp >> temp1;
                y[temp] = temp1;
            }
            cout << x[n] << endl;
            cout << y[m] << endl;
            if(x[n] > y[m])
                cout << 1;
            else
                cout << 0;
        }
    }
    if(c == 1)
    {
        int x[5],y[5];
        cin >> x[1] >> y[1];
        if(x[1] > y[1])
            cout << 1;
        else
            cout << 0;
        for(int i = 1; i <= q; i++)
        {
            int a, b;
            cin >> a >> b;
            for(int j =1 ; j <= a; j++)
            {
                int temp, temp1;
                cin >> temp >> temp1;
                x[temp] = temp1;
            }
            for(int j = 1; j <= b; j++)
            {
                int temp, temp1;
                cin >> temp >> temp1;
                y[temp] = temp1;
            }
            if(x[1] > y[1])
                cout << 1;
            else
                cout << 0;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
