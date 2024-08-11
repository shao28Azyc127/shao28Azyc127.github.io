#include<bits/stdc++.h>
using namespace std;
int a,b,c;
int gcd(int a,int b)
{
    if(b>a) swap(a,b);
    if(b==0) return a;
    return gcd(b,a%b);
}
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m;
    cin>>t>>m;
    for(int tt=1;tt<=t;tt++)
    {
        scanf("%d%d%d",&a,&b,&c);
        int der=(b*b)-(4*a*c);
        if(der==0)
        {
            if(-1.0*b/a<0) cout<<"-";
            int ab=abs(b);
            int aa=2*abs(a);
            if(ab==0)cout<<0;
            else
            {
                int gab=gcd(ab,aa);
                ab/=gab;
                aa/=gab;
                if(aa==1) cout<<ab;
                else{
                    cout<<ab<<"/"<<aa;
                }
            }
            cout<<endl;
        }
        else if(der>0)
        {
            int xder=1;
            bool firtrue=1;
            for(int ti=1;ti*ti<=(der+100000);ti++)
            {
                if(der%(ti*ti)==0)
                {
                    xder=ti;
                }
            }
            der/=(xder*xder);
            if(der==1)
            {
                if(a<0) xder*=-1;
                if(1.0*(-1*b+xder)/a<0)
                {
                    cout<<"-";
                }
                int ab=abs(-1*b+xder);
                int aa=2*abs(a);
                if(ab==0) cout<<0;
                else
                {
                    int gab=gcd(ab,aa);
                    ab/=gab;
                    aa/=gab;
                    if(aa==1) cout<<ab;
                    else{
                        cout<<ab<<"/"<<aa;
                    }
                }
            }
            else
            {
                if(-1.0*b/a<0) cout<<"-";
                int ab=abs(b);
                int aa=2*abs(a);
                if(ab==0)firtrue=0;
                else
                {
                    int gab=gcd(ab,aa);
                    ab/=gab;
                    aa/=gab;
                    if(aa==1) cout<<ab;
                    else{
                        cout<<ab<<"/"<<aa;
                    }
                }
                /*if(1.0*(xder*xder*sqrt(der))/a<0) cout<<"-";
                else*/ if(firtrue) cout<<"+";
                int a1b=abs(xder);
                int a1a=2*abs(a);
                if(a1b==0);
                else
                {
                    int g1ab=gcd(a1b,a1a);
                    a1b/=g1ab;
                    a1a/=g1ab;
                    if(a1a==1)
                    {
                        if(a1b==1)cout<<"sqrt("<<der<<")";
                        else cout<<a1b<<"*sqrt("<<der<<")";
                    }
                    else{
                        if(a1b==1)cout<<"sqrt("<<der<<")"<<"/"<<a1a;
                        else cout<<a1b<<"*sqrt("<<der<<")"<<"/"<<a1a;
                    }
                }
            }
            cout<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
