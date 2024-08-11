#include<bits/stdc++.h>
using namespace std;
const long long N=200000;
long long n,d,sum,flag,t,v[N],a[N],q[N],minn=N;
double tmp,cnt,ans;
long long f1(long long w){
    return (w-1)/d+1;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    freopen("road.in","w",stdout);
    cin>>n;
    for(int i=1;i<=n-1;i++){
        cin>>v[i];
        sum+=v[i];
        q[i]=f1(v[i]);
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        minn=min(minn,a[i]);
        if(minn==a[i]){
            t=i;
        }
    }
    sum=f1(sum);
    ans+=a[1]*q[1];
    for(int i=2;i<=t;i++){
        ans+=a[i]*q[i]-(v[i-1]%d)/d;
    }
    sum-=ans;
    ans+=sum*a[t];
    return 0;
}
