#include <bits/stdc++.h>
using namespace std;
double t,m,a,b,c;
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    while(t--)
    {
        cin>>a>>b>>c;
        double num=0;
        num=(b*b-4*a*c)/(2*a);
        if(num<0)
        {
            cout<<"NO"<<endl;
        }
        else if(num==0)
        {
            int ans1=(-b)/(2*a);
            cout<<ans1<<endl;
        }
        else if(num>0)
        {
            int ans1=((-b)+sqrt(num))/(2*a);
            int ans2=((-b)-sqrt(num))/(2*a);
            cout<<ans1<<" "<<ans2<<endl;
        }
    }
    return 0;
}
