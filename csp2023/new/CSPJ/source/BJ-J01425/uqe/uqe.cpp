#include<bits/stdc++.h>
using  namespace std;
int main()
{
    freopen("upe.in","r",stdin);
    freopen("upe.out","w",stdout);
    int t,m;
    cin>>t>>m;
    char x1=0,x2=0;
    for(int i=1;i<=t;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        int d=b*b-4*a*c;
        if(d<0)
        {
            cout<<"NO"<<endl;
            return 0;
        }
        else
        {
            if(d=0)
            {
                x1=x2=2*a/(-b+sqrt(d));
                cout<<x1;
            }
            if(d>0)
            {
                x1=2*a/(-b+sqrt(d));
                x2=2*a/(-b-sqrt(d));
                if(x1>x2)
                {
                    cout<<x1;
                }
                else
                {
                    cout<<x2;
                }
            }
        }
    }
    return 0;
}

