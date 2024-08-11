#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int a,b,c,t,m;
    cin>>t>>m;
    while(t--)
    {
        cin>>a>>b>>c;
        int t=b*b-4*a*c;
        if(t<0) cout<<"NO\n";
        else cout<<0<<"\n";
    }
    return 0;
}
