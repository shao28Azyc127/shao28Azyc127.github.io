#include <iostream>
#include <cmath>
using namespace std;

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
        int cnt = b * b - 4 * a * c;
        if (cnt < 0)
        {
            cout << "NO";
        }
        else{
            cout << max((-1 * b + sqrt(cnt)) / (2 * a),(-1 * b - sqrt(cnt)) / (2 * a)) << endl;
        }
    }
return 0;
}
