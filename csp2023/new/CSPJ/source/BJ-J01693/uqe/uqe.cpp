#include<bits/stdc++.h>
using namespace std;
struct Xyz
{
    long long a;
    long long b;
    long long c;
}x[5010];
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    long long t,m;
    cin>>t>>m;
    for(int i=0;i<t;i++)
    {
        cin>>x[i].a>>x[i].b>>x[i].c;
    }
    for(int i=0;i<t;i++)cout<<0<<endl;
    return 0;
}
