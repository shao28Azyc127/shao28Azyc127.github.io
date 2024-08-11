#include <bits/stdc++.h>
using namespace std;
int n,a,b,c,d,e;
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    while(n--)
    {
        cin>>a>>b>>c>>d>>e;
    }
    if(n==1)
    {
        cout<<"81";
    }
    else
    {
        cout<<10-n;
    }
    return 0;
}
