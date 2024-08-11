#include <bits/stdc++.h>
using namespace std;
int gcd(int x,int y)
{
    if (y==0)   return x;
    else{
        return gcd(y,x%y);
    }
}
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m;
    cin>>t>>m;
    //cout<<gcd(12,18);
    for (int i=0;i<t;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        int derta=b*b-4*a*c;
        if (derta<0)
        {
            cout<<"NO"<<endl;
            continue;
        }
        double xx=(-b+sqrt(derta))/(2*a);
        double xx1=(-b-sqrt(derta))/(2*a);
        int x=max(xx,xx1);

        if (max(xx,xx1)==x)
        {
            cout<<x<<endl;
        }
        else{

        }
    }
    return 0;
}
