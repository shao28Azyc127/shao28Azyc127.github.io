#include<bits/stdc++.h>
using namespace std;
int T,M;
int a[1001],b[1001],c[1001];
int panbieshi[1001];
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin >> T >> M;
    for (int i = 1;i <= T;i++)
    {
        cin >> a[i] >> b[i] >> c[i];
        panbieshi[i] = b[i] * b[i] - 4 * a[i] * c[i];
    }
    for (int i = 1;i <= T;i++)
    {
        if (b[i] == 0 && c[i] == 0)
        {
            cout << 0 << endl;
        }
        else if (b[i] == 0 && c[i] != 0)
        {
            if (((c[i] > 0) && (a[i] > 0))||((c[i] < 0)&&(a[i] < 0)))
                cout << "NO" << endl;
            else
            {
                cout << "sqrt(" << sqrt((c[i]*-1)/a[i]) << ")" << endl;
            }
        }
        else if (panbieshi[i] < 0)
            cout << "NO" << endl;
        else if (panbieshi[i] == 0)
        {
            if (2*a[i] == 1)
                cout << (b[i]*-1)/2 << endl;
            else if (2*a[i] == -1)
            {
                if (b[i]%2==0)
                    cout << b[i]/2 << endl;
                else
                    cout << b[i] << "/" << 2 << endl;
            }
            else
                cout << (b[i]*-1) << "/" << (2*a[i]);
        }
        else
        {
            cout << (b[i]*-1) << "/" << (2*a[i]) << "+" << "sqrt(" << panbieshi[i] << ")";
        }
    }
    return 0;
}
