#include <bits/stdc++.h>
using namespace std;
int u[100005];
int a[100005];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin>>n>>d;
    for(int i=1;i<=n-1;i++)
        cin>>u[i];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int ans=0;
    int y=0;
    int i=1;
    while(i<n){
            int w=0;
            int s=0;
        for(int j=i;j<=n;j++){
            if(a[j]<a[i]){
                w=j;
                break;
            }
        }
        for(int j=i;j<w;j++)
            s+=u[j];
        if(y!=0)
            s-=y;
        if(s%d!=0)
        ans+=(s/d+1)*a[i];
           else
        ans+=(s/d)*a[i];
        if(s%d!=0)
            y+=(s/d+1)*d-s;
            //cout<<w<<" "<<s<<" "<<ans<<endl;
        i=w;
    }

    cout<<ans;
    return 0;
}
