#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,m,i,j,k,a,b,c;
int gcd(int a,int b)
{
    if(b==0) return abs(a);
    return gcd(b,a%b);
}
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t;
    cin>>t>>k;
    while(t--)
    {
        cin>>a>>b>>c;
        if(b*b-4*a*c<0)
        {
            puts("NO");
            continue;
        }
        int d=b*b-4*a*c,t=2*a,sqd=sqrt(d);
        if(t<0&&d-b>0||t>0&&d-b<0) sqd=-sqd;
        if(d==0)
        {
            if((-b)%t==0) cout<<(-b)/t;
            else cout<<(-b)/gcd(-b,t)<<"/"<<t/gcd(-b,t);
        }
        else if(int(sqrt(d))==sqrt(d)) //rational
        {
            //puts("rational");
            if((-b+int(sqd))%t==0)
            {
                cout<<(-b+int(sqd))/t<<endl;
                continue;
            }
            if(b!=0)
            {
                if((-b+sqd)%t!=0) cout<<(-b+sqd)/gcd(-b+sqd,t)<<"/"<<t/gcd(-b+sqd,t)<<endl;
                else cout<<(-b+sqd)/t<<endl;
                continue;
            }
            if(d%t==0) cout<<sqd/t;
            else cout<<sqd/gcd(sqd,t)<<"/"<<t/gcd(sqd,t);
        }
        else //irrational
        {
            if(b!=0)
            {
               // puts("dbg7");
                if(t<0&&-b>0) t=-t,b=-b;
                if((-b)%t!=0) cout<<(-b)/gcd(-b,t)<<"/"<<t/gcd(-b,t);
                else cout<<(-b)/t;
            }
            //factors of d
            int fac=1;
            for(int i=2;i*i<=d;i++)
                while(d%(i*i)==0) fac*=i,d/=(i*i);
            if(fac/gcd(fac,t)==1)
            {
                if(t/gcd(fac,t)==-1)
                {
                 //   puts("dbg3");
                    if(fac/t>0) cout<<"-";
                    else if(fac/t<0&&b) cout<<"+";
                    cout<<"sqrt("<<d<<")"<<endl;
                    continue;
                }
                else if(t/gcd(fac,t)==1)
                {
                   // puts("dbg4");
                    if(fac/t>0&&b) cout<<"+";
                    else if(fac/t<0) cout<<"-";
                    cout<<"sqrt("<<d<<")"<<endl;
                    continue;
                }
              //  puts("dbg6");
                cout<<"sqrt("<<d<<")/"<<abs(t/gcd(fac,t));
            }
            else
            {
                if(t/gcd(fac,t)==-1)
                {
                   // puts("dbg2");
                    if(fac/t>0) cout<<"-";
                    else if(fac/t<0&&b) cout<<"+";
                    cout<<fac/gcd(fac,t)<<"*sqrt("<<d<<")"<<endl;
                    continue;
                }
                else if(t/gcd(fac,t)==1)
                {
                   // puts("dbg");
                    if(fac/t>0&&b) cout<<"+";
                    else if(fac/t<0) cout<<"-";
                    cout<<fac/gcd(fac,t)<<"*sqrt("<<d<<")"<<endl;
                    continue;
                }
                if(b) cout<<"+";
                if(fac%t!=0) cout<<fac/gcd(fac,t)<<"*sqrt("<<d<<")/"<<t/gcd(fac,t);
                else cout<<fac/t<<"*sqrt("<<d<<")";
            }
        }
        cout<<endl;
    }
    return 0;
}
