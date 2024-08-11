#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m;
    cin>>t>>m;
    while(t--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(b*b-4*a*c==0||b*b-4*a*c==1)cout<<"1\n";
        else if(b*b-4*a*c<0)cout<<"NO\n";
    }
    return 0;
}