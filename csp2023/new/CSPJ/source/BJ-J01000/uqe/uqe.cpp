#include<iostream>
#include<cstdio>
using namespace std;
int t,m,a,b,c,delta;
int gcd(int x,int y)
{
    if(y==0)
        return x;
    else
        return gcd(y,x%y);
}
int sq(int x)
{
    int ans=1;
    for(int i=1;i*i<=n;i++)
    {

        if(x%(i*i)==0)
            ans*=i;
    }
    return ans;
}
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    cout<<gcd(t,m);
    for(int i=1;i<=t;i++)
    {
        cin>>a>>b>>c;
        delta=b*b-4*a*c;
        if(delta<0)
        {

            cout<<"NO"<<endl;
            continue;
        }
        else{
            if(b!=0)
            {
                if(delta==0)
                {
                    if(2*a/gcd(-b,2*a)!=1)
                            cout<<(-b)/gcd(-b,2*a)<<"/"<<2*a/gcd(-b,2*a)<<endl;
                    else if(2*a/gcd(-b,2*a)==1)
                        cout<<(-b)/gcd(-b,2*a)<<endl;
                }
                else if(delta>0)
                {
                    if(sq(delta)==1)
                    {
                        if(2*a/gcd(-b,2*a)!=1)
                            cout<<(-b)/gcd(-b,2*a)<<"/"<<2*a/gcd(-b,2*a)<<"+sqrt("<<delta<<")/"<<2*a;
                        else if(2*a/gcd(-b,2*a)==1)
                            cout<<(-b)/gcd(-b,2*a)<<"+sqrt("<<delta<<")/"<<2*a;
                    }
                }
            }
        }

    }
    return 0;
}
