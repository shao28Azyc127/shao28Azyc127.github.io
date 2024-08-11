#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin>>n>>d;
    int v[100010],a[100010];
    for(int i=0;i<n-1;i++)cin>>v[i];
    for(int i=0;i<n;i++)cin>>a[i];
    int p=0,ans=0;
    double l=0;
    while(p!=n-1){
        if(p==n)break;
        int np=p,dis=0;
        while(a[np]>=a[p]){
            np++;
            if(np>=n){
                np=n-1;
                break;
            }
            dis+=v[np-1];
        }
        //cout<<dis<<endl;
        int nl;
        nl=floor(dis/d-l)+1;
        l+=nl;
        int money;
        money=nl*a[p];
        ans+=money;
        //cout<<p+1<<' '<<money<<' '<<l<<' '<<nl<<' '<<ans<<" "<<np+1<<endl;
        l-=(double)dis/d;
        p=np;
        
    }
    cout<<ans<<endl;
}