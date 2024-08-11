#include <bits/stdc++.h>
using namespace std;
vector<int> g[100005];
bool vis[100005];
long long a[100005];int b[100005],c[100005];
long long tr(int i){
    if(c[i]<0){
        if(-c[i]>b[i]) return a[i];
        return a[i]-(b[i]/(-c[i])*(b[i])+(1+b[i]/(-c[i]))*b[i]/(-c[i])/2)+b[i]/(-c[i]);
    }long long good=a[i],bad=0;
    while(good>bad+1){
        int mid=(good+bad)/2;
        if((b+c*(mid+1))*mid>=2*a) good=mid;
        else bad=mid;
    }return good;
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }int now=1,ans=0;
    for(int i=0;i<n;i++){
        ans=max(ans,tr(now)+i);
        vis[now]=1;
        now=vis[g[now][0]]?g[now][1]:g[now][0];
    }cout<<ans;

    return 0;
}