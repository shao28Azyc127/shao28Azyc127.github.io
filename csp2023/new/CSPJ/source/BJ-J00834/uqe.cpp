#include<iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m;
    cin >> t >> m;
    for (int i = 1; i <= t; i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        if (b * b - 4 * a * c < 0)
        {
            cout << "NO" << endl;
            continue;
        }
        int x = b * b - 4 * a * c;
        cout << (sqrt(x)- b) / (2 * a) << endl;
    }
    return 0;
}
