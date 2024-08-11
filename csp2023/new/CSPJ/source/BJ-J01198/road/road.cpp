#include <bits/stdc++.h>
using namespace std;
int n,d,u[100005]={ },a[100005],minn=2e9,ans=0;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<=n-1;i++){
        cin>>u[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]<minn){
            minn=a[i];
        }
        ans=ans+(u[i]/d*minn);
    }
    cout<<ans;
    return 0;
}