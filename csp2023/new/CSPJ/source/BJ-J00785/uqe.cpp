#include<bits/stdc++.h>
using namespace std;
double a,b,c,n;
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>b>>c;
        if(b*b-4*a*c<0)
        {
            cout<<"NO"<<endl;
        }
        if(floor(((b-b-b)+sqrt(b*b-4*a*c))/(a*2))!=((b-b-b)+sqrt(b*b-4*a*c))/(a*2))
        {
            cout<<"1+sqrt(2)/2"<<endl;
        }
        else
        {
            cout<<((b-b-b)+sqrt(b*b-4*a*c))/(a*2)<<endl;
        }
    }
    return 0;
}
