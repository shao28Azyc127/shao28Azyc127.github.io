#include<bits/stdc++.h>
using namespace std;
int a,b,c,t,m,x;
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    while(t--)
    {
        cin>>a>>b>>c;
        x=b*b-4*a*c;
        if(x<0)
        {
            cout<<"No";
        }else
        {
            int ans1,ans2;
            ans1=(-b+sqrt(x))/(2*a);
            ans2=(-b-sqrt(x))/(2*a);
            cout<<max(ans1,ans2);
        }
        cout<<endl;
    }
    return 0;
}
