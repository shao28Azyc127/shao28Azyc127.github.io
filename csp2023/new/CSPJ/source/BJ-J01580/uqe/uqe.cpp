#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    int t,m;
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    for(int i=0;i<t;i++)
    {
        double a,b,c;
        cin>>a>>b>>c;
        double delta=b*b-4*a*c;
        if(delta<0){cout<<"NO\n";break;}
        double x=max((2*b+sqrt(delta))/(2*a),(2*b-sqrt(delta))/(2*a));
        long double y=max((2*b+sqrt(delta))/(2*a),(2*b-sqrt(delta))/(2*a));
        if((long double)x==y){cout<<x<<endl;break;}

        if((0-b)/(2*a)!=0)
        {
            int f=(0-b)/(2*a);
            if((0-b)/(2*a)==(double)f)cout<<(0-b)/(2*a)<<'+';
            else cout<<0-b<<'/'<<2*a<<'+';
        }
        cout<<2*a<<"*sqrt("<<sqrt(delta)<<")\n";
    }
    return 0;
}
