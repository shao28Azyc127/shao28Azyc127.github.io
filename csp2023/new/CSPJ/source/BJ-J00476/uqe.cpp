#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int T,M;
int a[5001],b[5001],c[5001];
int ans;

int delta(int a, int b, int c)
{
    return b*b-4*a*c;
}

int gcd(int a, int b)
{
    for(int i=min(a,b);i>0;i--) {
        if(a%i==0 && b%i==0)
            return i;
    }
}

int main()
{
    cin>>T>>M;
    for(int i=0;i<T;i++) {
        cin>>a[i]>>b[i]>>c[i];
        int d=delta(a[i],b[i],c[i]);
        if(d<0)
        {
            cout<<"NO"<<endl;
            continue;
        }
        else
        {
            if(d==0)
            {
                int g=gcd(-b[i],2*a[i]);
                if(g==2*a[i])
                {
                    cout<<(-b[i])/2*a[i]<<endl;
                    continue;
                }
                else{
                    cout<<(-b[i])/g<<"/"<<(2*a[i])/g<<endl;
                    continue;
                }
            }
            else
            {
                int t;
                for(int k=1;k*k<=d;k++) {
                    if(d%(k*k)==0) {
                        d/=k*k;
                        t=k;
                    }
                }

                if((b[i]/(-2*a[i])+b[i]%(-2*a[i]))!=0) {
                    int g=gcd(b[i],-2*a[i]);
                    if(g==2*a[i])
                    {
                        cout<<(-b[i])/2*a[i]<<"+";
                    }
                    else{
                        cout<<(-b[i])/g<<"/"<<(2*a[i])/g<<"+";
                    }
                }
                if(2*a[i]==t)
                {
                    cout<<"sqrt(";
                    cout<<d;
                    cout<<")"<<endl;
                }
                else if(((t%(2*a[i])))==0)
                {
                    cout<<(t%(2*a[i]));
                    cout<<"*sqrt(";
                    cout<<d;
                    cout<<")"<<endl;
                }
                else if(((2*a[i])%t)==0)
                {
                    cout<<"sqrt("<<d<<")/"<<((2*a[i])%t)<<endl;
                }
                else {
                    int g=gcd(t,2*a[i]);
                    cout<<t/g<<"*sqrt("<<d<<")/"<<(2*a[i])/g<<endl;
                }
            }
        }
    }
}
