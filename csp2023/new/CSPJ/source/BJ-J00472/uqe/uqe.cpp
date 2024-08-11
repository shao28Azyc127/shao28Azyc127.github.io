#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int deta(int a,int b,int c)
{
    if (b*b-4*a*c > 0)
    {
        return 1;
    }
    else if (b*b-4*a*c == 0)
    {
        return 0;
    }
    else{
        return 2;
    }
}
int sqrtt(int a, int c)
{
    int x1 = sqrt(-4*a*c)/(2*a);
    int x2 = -1*sqrt(-4*a*c)/(2*a);
    return max(x1,x2);
}
int n,m,a[1005],b[1005],c[1005];
int main()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i] >> c[i];
    }
    for (int i = 1; i <= n; i++)
    {
        if (b[i]==c[i]&&c[i]==0)
        {
            cout << 0 << endl;
        }
        else if (b[i] == 0)
        {
            if (c[i]<=0)
            {
                cout << sqrtt(a[i],c[i]) << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
        else
        {
            if (deta(a[i],b[i],c[i]) == 2)
            {
                cout << "NO" << endl;
            }
            else if (deta(a[i],b[i],c[i]) == 0)
            {
                double x = (-1*b[i])/(2*a[i]);
                cout << x << endl;
            }
            else
            {
                int x1 = (-1*b[i]+sqrt(b[i]*b[i]-4*a[i]*c[i]))/(2*a[i]);
                int x2 = (-1*b[i]-sqrt(b[i]*b[i]-4*a[i]*c[i]))/(2*a[i]);
                cout << max(x1,x2)<<endl;
            }
        }
    }
    return 0;
}