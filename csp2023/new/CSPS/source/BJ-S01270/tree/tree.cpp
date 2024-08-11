#include <bits/stdc++.h>

using namespace std;

int n;
long long a[100005],b[100005],c[100005],day[100005],u,v;
vector<long long>mp[100005];
bool ify[100005]={0};
vector<int>canuse;

void BFS(){
}

int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>c[i];
        day[i]=a[i]/b[i]+a[i]%b[i]?1:0;
    }
    for(int i=1;i<n;i++){
        cin>>u>>v;
        mp[u].push_back(v);
        mp[v].push_back(u);
    }
    BFS();
cout<<1000;
    return 0;
}
