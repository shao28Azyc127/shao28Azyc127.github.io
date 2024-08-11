#include<bits/stdc++.h>
using namespace std;
long long t,m,a,b,c;
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    while(t--)
    {
        cin>>a>>b>>c;
        long long ans=-4*a*c;
        if(ans<0)cout<<"NO";
        else cout<<"sqrt("a*c")/4";
    }
    return 0;
}
