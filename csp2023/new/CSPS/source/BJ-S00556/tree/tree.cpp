#include<iostream>
#define int long long
#define rep(i,n) for(int i=1;i<=n;++i)
using namespace std;
const int N=1e5+7;
int a[N],b[N],c[N],n,ans;
int sum(int l,int r){
    return (r-l+1)*(l+r)/2;
}
int erf(int x,int y,int b,int len){
    int l=b,r=1e9,ans=-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(sum(b,mid)*y+(mid-b+1)*x>=len)ans=mid,r=mid-1;
        else l=mid+1;
    }
    return ans;
}
int erF(int x,int y,int L,int R,int len){
    int l=L,r=R,ans=-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(-(sum(L,mid))*y+(mid-L+1)*x>=len)ans=mid,r=mid-1;
        else l=mid+1;
    }
    return ans;
}
main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    rep(i,n)scanf("%lld%lld%lld",a+i,b+i,c+i);
    rep(i,n){
        if(c[i]>=0)
            ans=max(ans,erf(b[i],c[i],i,a[i]));
        else{
            int day=b[i]/(-c[i])+(b[i]%c[i]==0);
            if(day<=i)ans=max(ans,a[i]+i-1);
            else{
            int nans=erF(b[i],c[i],i,day,a[i]);
            if(nans>=0)ans=max(ans,nans);
            else{
                a[i]-=day*b[i]+sum(i,day)*c[i];
                ans=max(ans,day+a[i]);
            }}
        }
    }
    cout<<ans;
    return 0;
}
