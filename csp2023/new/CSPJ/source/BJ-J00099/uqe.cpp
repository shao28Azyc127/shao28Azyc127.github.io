#include<bits/stdc++.h>
using namespace std;

int t,m;

int gcd(int a,int b)
{
    if(a<b)
    {
        a=a+b;
        b=a-b;
        a=a-b;
    }
    if(a%b==0)
        return b;
    gcd(b,a%b);
    return -1;
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
        if(b*b-4*a*c<0)
        {
            cout<<"NO"<<endl;
            continue;
        }
        int x=b*b-4*a*c;
        int fz1=0-b+sqrt(x),fz2=0-b-sqrt(x),fm=2*a;
        if((1.0*fz1/fm)>=(1.0*fz2/fm))
        {
            int tt=gcd(fz1,fm);

            if(tt==1)
            {
                if(fm==1)
                    cout<<fz1<<endl;
                else
                    cout<<fz1<<"/"<<fm<<endl;
            }
            else
            {
                fz1/=tt;
                fm/=tt;
                if(fm<0)
                {
                    fm*=-1;
                    fz1*=-1;
                }
                if(fm==1)
                    cout<<fz1<<endl;
                else
                    cout<<fz1<<"/"<<fm<<endl;
            }
        }
        else
        {
            int tt=gcd(fz2,fm);
            if(tt==1)
            {
                if(fm==1)
                    cout<<fz2<<endl;
                else
                    cout<<fz2<<"/"<<fm<<endl;
            }
            else
            {
                fz2/=tt;
                fm/=tt;
                if(fm<0)
                {
                    fm*=-1;
                    fz2*=-1;
                }
                if(fm==1)
                    cout<<fz2<<endl;
                else
                    cout<<fz2<<"/"<<fm<<endl;
            }
        }
    }


    return 0;
}
