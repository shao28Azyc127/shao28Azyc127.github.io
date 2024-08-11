#include <bits/stdc++.h>
using namespace std;
int a,b,c;
int t,m;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    while(t--)
    {
        cin>>a>>b>>c;
        if(b*b-4*a*c<0)
        {
            cout<<"NO\n";
            continue;
        }
        cout<<1<<'\n';
    }
    return 0;
}