#include<bits/stdc++.h>
using namespace std;
const int N=1E5+1;
vector<int> ma[N];
long long a[N],b[N],c[N],cnt[N];
int n,ans=0;
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>b[i]>>c[i];
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        ma[u].push_back(v);
    }
    cout<<n;
    return 0;
}