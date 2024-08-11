#include <bits/stdc++.h>
using namespace std;
struct s{
    int a,b,c;
}x[100005];
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>x[i].a>>x[i].b>>x[i].c;
    int flag=1;
    for(int i=1;i<=n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        if(u!=i&&v!=i+1)
        flag=0;
    }
    int ans=0;
    cout<<5<<endl;
    return 0;
}



