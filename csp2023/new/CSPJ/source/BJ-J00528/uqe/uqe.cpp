#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m;
    cin>>t>>m;
    while (t--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if (b==0 && c==0)
        {
            cout<<0<<endl;
            continue;
        }
        long long sum;
        sum=b*b-4*a*c;
        if (sum<0)
        {
            cout<<"NO"<<endl;
            continue;
        }
        if (sum==0)
        {
            a*=2;
            int flag=__gcd(b,a);
            if (flag!=1)
            {
                b/=flag;
                a/=flag;
            }
            if (a==1)
                cout<<"-"<<b<<endl;
            else
                cout<<"-"<<b<<"/"<<a<<endl;
        }
        else
            cout<<a<<endl;
    }
    return 0;
}