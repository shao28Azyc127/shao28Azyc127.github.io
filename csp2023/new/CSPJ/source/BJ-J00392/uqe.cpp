#include<bits/stdc++.h>
using namespace std;
int a,b,c;
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int n,t;
    cin>>n>>t;
    int d;
    for(int i=1;i<=n;i++)
    {
        int ans;
        cin>>a>>b>>c;
        d=b*b-4*a*c;
        if(d<0)
        {
            cout<<"NO"<<endl;;
            continue;
        }
        else
        {
            if(b==0)
                ans=0;
            else
            {
                ans=b*-1;
            }
        }
        ans+=abs(sqrt(d));
        ans/=2*a;
        cout<<ans<<endl;
    }
    return 0;
}