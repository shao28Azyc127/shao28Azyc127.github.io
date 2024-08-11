#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
int ans(int x,int y)
{
    int X=min(x,y),Y=max(x,y);
    for(int i=2;i<=X;i++)
    {
        if(Y%i==0)
        {
            x%=i;
            y%=i;
        }
    }
    cout<<x<<"/"<<y;
    return 0;
}
signed main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m;
    cin>>t>>m;
    for(int i=1;i<=t;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        int r=b*b-4*a*c;
        if(r<0)
        {
            cout<<"NO"<<endl;
            continue;
        }
        double x1=(sqrt(r)-b)/(2.0*a),x2=(-sqrt(r)-b)/(2.0*a);
        int p=sqrt(r),P,Q;
        if(x1>=x2)
        {
            if(p*p==r)
            {
                P=p-b,Q=2*a;
                ans(P,Q);
            }
        }
        else
        {
            if(p*p==r)
            {
                P=-p-b,Q=2*a;
                ans(P,Q);
            }
        }
    }
    return 0;
}