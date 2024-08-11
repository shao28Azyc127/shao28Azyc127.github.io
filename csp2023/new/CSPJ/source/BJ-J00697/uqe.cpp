#include <bits/stdc++.h>
using namespace std;
int main ()
{
    freopen ("uqe.in","r",stdin);
    freopen ("uqe.out","w",stdout);
    int T,M,a,b,c,der,dd;
    double x1,x2,d;
    cin>>T>>M;
    for (int i=1;i<=T;i++)
    {
        cin>>a>>b>>c;
        der=b*b-4*a*c;
        if (der<0) cout<<"No"<<endl;
        else
        {
            x1=(-b+sqrt(der))/(2*a);
            x2=(-b-sqrt(der))/(2*a);
            if (x1>x2) d=x1;
            else d=x2;
            dd=d;
            if (dd!=d)cout<<d*fabs(1/d)<<"/"<<fabs(1/d)<<endl;
            else cout<<d<<endl;
        }
    }
    return 0;
}
