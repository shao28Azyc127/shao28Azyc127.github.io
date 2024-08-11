#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005
int n,d,v[MAXN],a[MAXN],mor,minoil,ans,now;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    minoil=MAXN;
    for(int i=1;i<n;i++)
        cin>>v[i];
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<n;i++){
        if(a[i]<minoil)
            minoil=a[i];
        if((v[i]-mor)%d==0)
            now=(v[i]-mor)/d;
        else
            now=(v[i]-mor)/d+1;
        ans+=now*minoil;
        mor=mor+now*d-v[i];
    }
    cout<<ans;
    return 0;
}