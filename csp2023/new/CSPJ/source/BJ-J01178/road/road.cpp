#include <bits/stdc++.h>
using namespace std;
int n,d,v[100005],a[100005],sum=0;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<=n-1;i++) cin>>v[i];
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n-1;i++) sum+=v[i];
    if(sum%d==0) sum=sum/d;
    else sum=sum/d+1;
    cout<<a[1]*sum;
    return 0;
}
