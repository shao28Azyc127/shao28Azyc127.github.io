#include<bits/stdc++.h>
using namespace std;
int t,m;
int a,b,c;
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    for(int i=0;i<t;i++)
    {
        cin>>a>>b>>c;
        if(b==0&&c==0)
        {
            cout<<0<<endl;
            continue;
        }
        if(b*b-4*a*c<0)
        {
            cout<<"No"<<endl;
            continue;
        }
        if(b==0)
        {
            cout<<sqrt((-c)/a)<<endl;
            continue;
        }
        if(c==0)
        {
            cout<<max(0,-(a/b))<<endl;
            continue;
        }
        if(b*b-4*a*c==0)
        {
            cout<<0-b/2<<endl;
            continue;
        }
    }
    return 0;
}
