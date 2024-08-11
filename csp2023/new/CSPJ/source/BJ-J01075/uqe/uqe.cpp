#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m;
    int a,b,c;
    cin >> t >> m;
    for (int i = 1 ; i <= t ; i++)
    {
        cin >> a >> b >> c;
        int temp = b * b - 4 * a * c;
        int ans1 = 0,ans2 = 0;
        if (temp < 0)
        {
            cout << "NO" << endl;
            continue;
        }
        else
        {
            ans1 = (-b + sqrt(temp)) / (2 * a);
            ans2 = (-b - sqrt(temp)) / (2 * a);
        }
        cout << max(ans1,ans2) << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}