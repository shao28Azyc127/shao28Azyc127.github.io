#include<bits/stdc++.h>
using namespace std;
int n,d,maxn;
long long id,ans,ye;
int a[100010],v[100010];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<=n-1;i++){
        cin>>v[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    maxn=a[1];
    for(int i=1;i<=n;i++){
        id+=v[i];
        if(i==n) break;
        if(a[i]<maxn){
            ans+=((id-ye)/d)*maxn+1;
            if((id-ye)%d!=0) ans+=maxn;
            maxn=a[i];
            ye+=id/d;
            id=0;
        }
    }
    if(ans==0){
        ans=id/d*maxn;
    }
    cout<<ans<<endl;
    return 0;
}
