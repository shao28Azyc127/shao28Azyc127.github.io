#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,n;
    cin>>t>>n;
    for(int i=0;i<t;i++)
    {
        double a,b,c;
        cin>>a>>b>>c;
        double aleph=b*b-4*a*c;
        if(aleph<0)
        {
            cout<<"NO"<<endl;
            continue;
        }
        double x1,x2;
        x1=(-b+sqrt(aleph))/2/a;
        x2=(-b-sqrt(aleph))/2/a;
        cout<<max(x1,x2)<<endl;
    }
    return 0;
}