#include <iostream>
#include <cmath>
using namespace std;
int t,m;
int main()
{
freopen("uqe.in","r",stdin);
freopen("uqe.out","w",stdout);
    cin>>t>>m;
    while(t--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(b==0 && c==0)
        {
            cout<<0<<endl;
            continue;
        }
        if(b*b-4*a*c<0)
        {
            cout<<"NO"<<endl;
            continue;
        }
        if(b==0 && c!=0)
        {
            cout<<sqrt(c/a)<<endl;
            continue;
        }
        if(t<0) break;
    }
    return 0;
}
