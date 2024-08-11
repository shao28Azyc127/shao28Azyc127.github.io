#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdio>
using namespace std;
void getans(int a,int b,int c)
{
    int d = b * b - 4 * a * c;
    int x;
    if (d < 0){
        cout << "NO" << endl;
        return;
    }

    if (d == 0)
    {
        cout << -b / (2 * a) << endl;
        return;
    }
    else
    {
        if (a < 0) cout << -b/(2 * a) - sqrt(d) << endl;
        else cout << -b/(2 * a) - sqrt(d) << endl;
    }

}
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m;
    cin >> t >> m;
    for (int i = 1;i <= t;i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        getans(a,b,c);
    }
    return 0;
}