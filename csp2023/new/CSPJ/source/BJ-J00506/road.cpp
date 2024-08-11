#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d,vsum=0,ans;
    int v[100005],a[100005];
    int tot=d*vsum;
    cin>>n>>d;
    for(int i=1;i<=n-1;i++)
        cin>>v[i];
        vsum+=v[i];
    for(int i=1;i<=n;i++)
        cin>>a[i];
        for(int i=2;i<=n;i++)
            if(a[1]<=a[i]){
                ans=tot/a[1];
            }
    cout<<ans;
    return 0;
}
