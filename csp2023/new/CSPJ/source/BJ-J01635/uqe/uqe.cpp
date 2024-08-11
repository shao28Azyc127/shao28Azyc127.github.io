#include<iostream>
#include<math.h>
using namespace std;
int a,b,c,t,m;
double x,y,z,d,n1,n2,ans;
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    for(int i=1;i<=t;i++)
    {
        cin>>a>>b>>c;
        x=a;
        y=b;
        z=c;
        d=y*y-4*x*z;
        if(d<0)
        {
            cout<<"NO"<<endl;
            continue;
        }
        else
        {
            n1=-1*y+sqrt(d);
            n2=-1*y-sqrt(d);
            if(n1/2/x>=n1/2/x)
            {
                ans=n1/2/x;
            }
            else
            {
                ans=n2/2/x;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}