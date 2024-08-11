#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m;
    cin>>t>>m;
    if(m==1)
    {
        for(int i=1;i<=t;i++)
        {
            cout<<"0"<<endl;
        }
        return 0;
    }
    for(int i=1;i<=t;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(b*b<4*a*c)
        {
            cout<<"NO"<<endl;
            continue;
        }
        int x=(-b+sqrt(b*b-4*a*c))/2*a;
        int y=(-b-sqrt(b*b-4*a*c))/2*a;
        if(x==1)
        {
            cout<<y<<endl;
            continue;
        }
        if(y==1)
        {
            cout<<x<<endl;
            continue;
        }
        if(x>y)
        {
            cout<<y<<" "<<x<<endl;
        }
        else
        {
            cout<<x<<" "<<y<<endl;
        }
    }
    return 0;
}