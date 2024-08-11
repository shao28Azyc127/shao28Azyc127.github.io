#include<bits/stdc++.h>
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
        if(m==1)
        {
            cout<<0<<"\n";
            continue;
        }
        if(b*b-4*a*c<0)
        {
            cout<<"NO"<<"\n";
        }
        else if(b*b-4*a*c==0)
        {
            for(int i=10000;i>=10000*-1;i--)
            {
                if(a*i*i+b*i+c==0)
                {
                    cout<<i<<"\n";
                    break;
                }
            }
        }
        else
        {
            for(int i=10000;i>=10000*-1;i--)
            {
                if(a*i*i+b*i+c==0)
                {
                    cout<<i<<"\n";
                    break;
                }
            }
        }
    }
    return 0;
}
