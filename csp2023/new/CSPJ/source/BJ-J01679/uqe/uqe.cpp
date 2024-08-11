#include<bits/stdc++.h>
using namespace std;
int main()
{

    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m;
    int a,b,c;
    bool f;
    cin>>t>>m;
    for(int i=1;i<=t;i++)
    {
        f=false;
        cin>>a>>b>>c;
        if(b*b-4*a*c<0)
        {
            cout<<"NO"<<endl;
            f=true;
        }
        for(int j=1;j<=m;j++){
            if(j*j*a+j*b+c==0)
            {
                cout<<j<<endl;
                f=true;
                break;
            }
        }
        if(f==true)
        {
            continue;
        }
        if(-b+sqrt(b*b-4*a*c)/(2*a)>-b-sqrt(b*b-4*a*c)/(2*a))
        {
            if(int(sqrt(b*b-4*a*c)/(2*a))==sqrt(b*b-4*a*c)/(2*a))
            {
                cout<<-b+sqrt(b*b-4*a*c)/(2*a)<<endl;
            }
            else
            {
                cout<<-b<<"+";
                if(sqrt(b*b-4*a*c)*sqrt(b*b-4*a*c)==b*b-4*a*c)
                {
                    for(int w=max(sqrt(b*b-4*a*c),2*a);w>=1;w++)
                    {
                        if(2*a%w==0&&sqrt(b*b-4*a*c)%w==0)
                        {
                            cout<<sqrt(b*b-4*a*c)/w<<"/"<<2*a<<endl;
                        }
                    }
                }
                else
                {
                    cout<<"sqrt("<<b*b-4*a*c<<")/"<<2*a<<endl;
                }
            }
        }
        else
        {
            if(int(sqrt(b*b-4*a*c)/(2*a))==sqrt(b*b-4*a*c)/(2*a))
            {
                cout<<-b-sqrt(b*b-4*a*c)/(2*a)<<endl;
            }
            else
            {
                cout<<-b<<"-";
                if(sqrt(b*b-4*a*c)*sqrt(b*b-4*a*c)==b*b-4*a*c)
                {
                    for(int w=max(sqrt(b*b-4*a*c),2*a);w>=1;w++)
                    {
                        if(2*a%w==0&&sqrt(b*b-4*a*c)%w==0)
                        {
                            cout<<sqrt(b*b-4*a*c)/w<<"/"<<2*a<<endl;
                        }
                    }
                }
                else
                {
                    cout<<"sqrt("<<b*b-4*a*c<<")/"<<2*a<<endl;
                }
            }
        }
    }
    return 0;
}
