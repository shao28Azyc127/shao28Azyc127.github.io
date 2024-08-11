#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m,a,b,c;
    cin >> t >> m;
    for(int i=1;i<=t;i++)
    {
        cin >> a >> b >> c;
        if(b*b<4*a*c)
        {
            cout << "NO" << endl;
            continue;
        }
        double x=(-b+sqrt(b*b-4*a*c))/(2*a),y=(-b-sqrt(b*b-4*a*c))/(2*a);
        int x2=x,y2=y;
        if(x2==x||y2==y)
        {
            if(x>y&&x2==x)
            {
                cout << x << endl;
            }
            else if(y>x&&y2==y)
            {
                cout << y << endl;
            }
        }
    }
    return 0;
}
