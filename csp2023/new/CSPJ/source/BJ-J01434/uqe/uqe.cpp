#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m,a,b,c,x,y;
    cin>>t>>m;
    for(int i=1;i<=t;i++)
    {
        cin>>a>>b>>c;
        if(b*b ? 4*a*c<0)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            x=(-1*b+sqrt(b*b-4*a*c))/(2*a);
            y=(-1*b+-1*sqrt(b*b-4*a*c))/(2*a);
            cout<<max(x,y)<<endl;
        }
    }
}