#include<bits/stdc++.h>
using namespace std;
int M,t,a,b,c;
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>M;
    while(t--)
    {
        cin>>a>>b>>c;
        int d=b*b-4*a*c;
        if(d<0)
        {
            cout<<"NO"<<endl;
            continue ;
        }
        int sd=sqrt(d);
        if(sd*sd==d)
        {
            if((-b+sd)%(2*a)==0)
            {
                cout<<(-b+sd)/(2*a)<<endl;
                continue ;
            }
            int u=(-b+sd),dd=2*a;
            for(int i=100;i>=2;i--)
            {
                if(u%i==0 && dd%i==0)
                {
                    u/=i;
                    dd/=i;
                    break ;
                }
            }
            cout<<u<<"/"<<dd<<endl;
            continue ;
        }
        else
        {
            if(b!=0)
            {
                if(b%(a*2)==0)
                {
                    cout<<(-b/a/2);
                }
                else
                {
                    cout<<-b<<"/"<<a*2;
                }
                cout<<"+";
            }
            int m;
            for(int i=2;i<=1000;i++)
            {
                if(d%(i*i)==0)
                {
                    m=i;
                    d/=i*i;
                }
            }
            int u=m,dd=2*a;
            for(int i=100;i>=2;i--)
            {
                if(u%i==0 && dd%i==0)
                {
                    u/=i;
                    dd/=i;
                    break ;
                }
            }
            if(dd!=1)
            {
                if(u!=1) cout<<u<<"*"<<"sqrt("<<d<<")"<<"/"<<dd<<endl;
                else cout<<"sqrt("<<d<<")"<<"/"<<dd<<endl;
            }
            else
            {
                if(u!=1) cout<<u<<"*"<<"sqrt("<<d<<")"<<endl;
                else cout<<"sqrt("<<d<<")"<<endl;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
