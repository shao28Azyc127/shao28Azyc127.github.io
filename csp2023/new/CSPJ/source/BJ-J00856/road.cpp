#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,d,v[100001],a[100001],b[100001];
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<=n-1;i++){
        cin>>v[i];
    }
    b[0]=2147483647;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=min(b[i-1],a[i]);
    }
    int tmp=0,ans=0,sum=0;
    for(int i=1;i<=n-1;i++){
        if(b[i]==b[i-1]){
            tmp+=v[i];
        }
        else{
            int x=(tmp-sum+d-1)/d;
            sum=x*d+sum-tmp;
            ans+=x*b[i-1];
            tmp=v[i];
        }
    }
    ans+=(tmp-sum+d-1)/d*b[n-1];
    cout<<ans;
    return 0;
}