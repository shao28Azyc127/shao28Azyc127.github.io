#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        long long y=b*b-(4*a*c);
        if(y<0) cout<<"NO"<<endl;
        if(y==0)
        {
            int x=__gcd(b,2*a);
            cout<<-b/(2*a)<<endl;
        }
        if(y>0)
        {
            if(b==0)
            {
                cout<<"sqrt("<<-a*c<<")/"<<a<<endl;
            }
            if(c==0)
            {
                if(-b/a>0)
                {
                    if(__gcd(b,a)==1) cout<<-b<<"/"<<a<<endl;
                    if(__gcd(b,a)!=1&&b%a!=0) cout<<-b/__gcd(b,a)<<"/"<<a/__gcd(b,a)<<endl;
                    if(b%a==0) cout<<-b/a<<endl;
                }
                if(-b/a<0) cout<<0<<endl;
            }
            if(b!=0&&c!=0)
            {
                if(-b%(2*a)==0) cout<<-b/(2*a)<<"+sqrt("<<y<<")/"<<2*a<<endl;
                if(-b%(2*a)!=0) cout<<-b<<"/"<<2*a<<"+sqrt("<<y<<")/"<<2*a<<endl;
            }
        }
    }
    return 0;
}
