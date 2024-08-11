#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen ("uqe.in","r",stdin);
    freopen ("uqe.out","w",stdout);
    int t,m;
    cin >>t>>m;
    while (t--)
    {
        int a,b,c;
        cin >>a>>b>>c;
        int af=b*b-4*a*c;
        if (af<0) cout <<"NO"<<endl;
        else
        {
            double ans1=(-b+sqrt(af))/(2*a);
            double ans2=(-b-sqrt(af))/(2*a);
            cout <<max(ans1,ans2)<<endl;
        }
    }

    return 0;
}
