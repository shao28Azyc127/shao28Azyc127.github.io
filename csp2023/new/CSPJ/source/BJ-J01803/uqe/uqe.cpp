#include <iostream>
using namespace std;
int a,b,c,n,m,ans[1005];
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin >> n >> m;
    for (int i=1; i<=n; ++i)
    {
        ans[i] = 1005;
    }
    for (int i=1; i<=n; ++i)
    {
        cin >> a >> b >> c;
        for (int j=m; j>=m-2*m; --j)
        {
            if(a*j*j+b*j+c == 0)
            {
                ans[i] = j;
                break;
            }
        }
    }
    for (int i=1; i<=n; ++i)
    {
        if(ans != 1005)
            cout << ans[i];
        else
            cout << "NO";
    }
    return 0;
}
