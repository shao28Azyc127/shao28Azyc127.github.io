#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m;
    cin>>t>>m;
    while(t--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        int tri=b*b-4*a*c;
        if(tri<0)
        {
            cout<<"NO";
        }
        else
        {
            double ans1=((-b)+sqrt(tri))/2*a;
            double ans2=((-b)-sqrt(tri))/2*a;
            cout<<max(ans1,ans2);
        }
        cout<<endl;
    }
    return 0;
}