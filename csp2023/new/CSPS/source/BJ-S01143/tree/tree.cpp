#include<iostream>
#include<cstdio>
#include<stack>
#include<vector>
using namespace std;
long long a[100005],b[100005],c[100005];
long long che(int i){
    if(c[i]>=0){
        long long l=i,r=min((long long)(1e9),(long long)(a[i]/b[i])+1),ans=0;
        while(l<=r){
            int mid=(l+r)/2;
            if(b[i]*(mid-i+1)+c[i]*(i+mid)*(mid-i+1)/2>=a[i]){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
    long long l=i,r=min((long long)1e9,a[i]),ans=0;
    while(l<=r){
        long long mid=(l+r)/2;
        if(c[i]*mid+b[i]<1){
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    l=i,r=min((long long)1e9,a[i]);
    long long ans2=0;
    while(l<=r){
        long long mid=(l+r)/2;
        if((mid>=ans&&(b[i]*(ans-i)+c[i]*(i+ans-1)*(ans-i)/2+(mid-ans+1)>=a[i]))||(mid<ans&&(b[i]*(mid-i+1)+c[i]*(i+mid)*(mid-i+1)/2>=a[i]))){
            ans2=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    return ans2;
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    int cnt=0;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        if(u==i&&v==i+1)++cnt;
    }
    if(cnt!=n-1)cout<<n+1;
    else{
        long long ans=0;
        for(int i=1;i<=n;i++){
            ans=max(ans,che(i));
           // cout<<ans<<" ";
        }
        cout<<ans;
    }
    return 0;
}
