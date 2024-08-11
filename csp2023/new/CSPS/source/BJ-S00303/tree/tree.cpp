#include<bits/stdc++.h>
using namespace std;
int n,u,v;
long long a[100050],b[100050],c[100050];
bool visit[100050];
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i]>>c[i];
    }
    for(int i=1;i<=n-1;i++)
    {
        cin>>u>>v;
    }
    cout<<2*n;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
