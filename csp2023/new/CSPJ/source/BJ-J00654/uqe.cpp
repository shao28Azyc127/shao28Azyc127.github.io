#include <bits/stdc++.h>
using namespace std;
int t,m;
int gcd(int a,int b)
{
    if(a%b==0)
        return b;
    return gcd(b,a%b);
}

void p(int a,int b)
{
    if(a<0&&b>0)
     {
     a*=-1;
     cout<<"-";
     }
    if(a>0&&b<0)
     {
        b*=-1;
        cout<<"-";
     }
     int c=gcd(a,b);
    cout<<a/c<<"/"<<b/c;

}
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    while(t--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        int S=b*b-4*a*c;
        if(S<0)
            cout<<"NO\n";
        double x=max(
                     (-b+sqrt(S))/(2*a),
                     (-b-sqrt(S))/(2*a)
                     );
        double xz=max(
                     (-b+sqrt(S)),
                     (-b-sqrt(S))
                     );
        if(ceil(sqrt(S))==sqrt(S))
        {
           int c=gcd(xz,2*a);
           if(c==2*a)
                cout<<x<<endl;
           else
           {
                p(xz,2*a);
                cout<<"\n";
           }
        }
        /*
        else
        {
            if(b!=0)
            {
              p(-b,2*a);
              for(int i=sqrt(S);i>0;i--)
              {
                  if(S%(i*i)==0)
                  {
                    if(2*a<0)
                    {
                        a*=-1;
                        cout<<"-";
                    }
                    else
                        cout<<"+";
                    int c=gcd(a,b);
                    cout<<i/c<<"*sqrt("<<S/(i*i)<<")"<<"/"<<2*a/c<<endl;
                  }

              }
            }
        }
        */

    }
    return 0;

}
