#include <bits/stdc++.h>
using namespace std;
long long a[100005],v[100005],s[100005],ans;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    long long n,d,k=0,mn=1e5+5,id;cin>>n>>d;
    for(int i=1;i<n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        scanf("%d",&v[i]);s[i]=a[i];
        if(v[i]<mn) id=i,mn=v[i];
        else s[id]+=a[i];
    }
    for(int i=1;i<=n;i++){
        if(k<a[i]) ans+=((s[i]-k)%d?(s[i]-k)/d+1:(s[i]-k)/d)*v[i],k=k+((s[i]-k)%d?(s[i]-k)/d+1:(s[i]-k)/d)*d;
        k-=a[i];
    }
    cout<<ans;
    return 0;
}