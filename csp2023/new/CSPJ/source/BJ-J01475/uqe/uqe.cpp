#include <bits/stdc++.h>
using namespace std;
int t,m,a,b,c;
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    while (t--)
    {
        scanf("%d%d%d",&a,&b,&c);
        if (a < 0)
        {
            cout<<"NO\n";
        }
        if (!b && !c)
        {
            cout<<"0\n";
        }
        else if (!b)
        {
            if (c > 0)
            {
                cout<<"NO\n";
            }
            else
            {
                c *= -1;
                double ans = sqrt(c);
                int anss = ans;
                if (ans == anss)
                {
                    cout<<anss;
                }
                else
                {
                    cout<<"sqrt("<<c<<")";
                }
                if (a != 1)
                {
                    cout<<"/"<<"sqrt("<<a<<")";
                }
                cout<<'\n';
            }
        }
        else
        {
            cout<<"NO\n";
        }
    }
    return 0;
}