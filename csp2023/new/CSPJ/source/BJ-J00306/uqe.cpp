#include<bits/stdc++.h>
using namespace std;
long long n,m,a[114514],b[114514],c[114514],si,so,s,st;
int gcd(long long a,long long b)
{
    for(int i=min(abs(a),abs(b));i>0;i--)
    {
        if(a%i==0&&b%i==0)
        {
            return i;
        }
    }
}
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i]>>b[i]>>c[i];
    }
    for(int i=0;i<n;i++)
    {
        if(b[i]==0)
        {
            s=-4*a[i]*c[i];
        }
        s=b[i]*b[i]-4*a[i]*c[i];
        if(s<0)
        {
            cout<<"NO"<<endl;
        }
        else if(s==0)
        {
            int t=gcd(2*a[i],-b[i]);
            if(2*a[i]/t==1)
            {
                cout<<(-b[i])/t<<endl;
            }
            else
            {
                cout<<(-b[i])/t<<"/"<<(2*a[i])/t<<endl;
            }
        }
        else if(s>0)
        {
            int t=gcd(2*a[i],-b[i]);
            for(int j=1;;j++)
            {
                if(j*j>=s)
                {
                    st=j;
                    break;
                }
            }
            for(int j=st;j>0;j--)
            {
                if(s%(j*j)==0)
                {
                    so=j;
                    si=s/(j*j);
                    break;
                }
            }
            if(si==1)
            {
                int add=so-b[i];
                t=gcd(add,2*a[i]);
                if(2*a[i]/t==1)
                {
                    cout<<add/t<<endl;
                }
                else
                {
                    cout<<add/t<<"/"<<(2*a[i])/t<<endl;
                }
            }
            else
            {
                if(2*a[i]/t==1)
                {
                    cout<<(-b[i])/t<<"+";
                }
                else
                {
                    cout<<(-b[i])/t<<"/"<<(2*a[i])/t<<"+";
                }
                t=gcd(so,2*a[i]);
                if(2*a[i]/t==1)
                {
                    if(so/t==1)
                    {
                        cout<<"sqrt("<<si<<")"<<endl;
                    }
                    else
                    {
                        cout<<so/t<<"*sqrt("<<si<<")"<<endl;
                    }
                }
                else
                {
                    if(so/t==1)
                    {
                        cout<<"sqrt("<<si<<")"<<"/"<<(2*a[i])/t<<endl;
                    }
                    else
                    {
                        cout<<so/t<<"*sqrt("<<si<<")"<<"/"<<(2*a[i])/t<<endl;
                    }
                }
            }
        }
    }
    return 0;
}
