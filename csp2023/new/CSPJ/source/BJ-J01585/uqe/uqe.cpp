#include <iostream>
#include <stdlib.h>
#include <cmath>

using namespace std;

double a[5005];
double b[5005];
double c[5005];
int t,m;
double x;

int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    for(int i=0;i<t;i++)
    {
        cin>>a[i]>>b[i]>>c[i];
        double a1=a[i];
        double b1=b[i];
        double c1=c[i];
        double delta=b1*b1-4*a1*c1;
        if(delta<0)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            double x1=(-1.0*b1+sqrt(delta))/(2.0*a);
            double x2=(-1.0*b1-sqrt(delta))/(2.0*a);
            if(x1>=x2)
            {
                x=x1;
            }
            else
            {
                x=x2;
            }
        }
        cout<<x<<endl;
    }
    return 0;
}
