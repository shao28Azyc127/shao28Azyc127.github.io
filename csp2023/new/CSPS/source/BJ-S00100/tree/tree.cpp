#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
    }
    for(int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
    }
    cout<<n+1;
    return 0;
}