#include<bits/stdc++.h>
#ifdef BJC
#define dlog(...) fprintf(stderr,__VA_ARGS__)
#else
#define dlog(...) (void)0
#endif
int up(int x,int d){
    return (x/d+(x%d==0?0:1));
} 
typedef int int32;
#define int long long
using namespace std;
int a[100001],v[100001],sum[100001],n,d,you;
int f(int idi,int idj){
    if(idi==1){
        you=up(v[1],d)*d-v[1];
        dlog("%lld\n",up(v[1],d)*a[1]);
        return up(v[1],d)*a[1];
    }
    int idx=1,minn=1e9;
    for(int i=1;i<idi;i++){
        if(a[i]<minn){
            minn=a[i];
            idx=i;
        }
    }
    if(idi==n) return f(idx,idi);
    int l=f(idx,idi);
    you=up(sum[idj-1]-sum[idi-1],d)*d+you-(sum[idj-1]-sum[idi-1]);
    int x=up(sum[idj-1]-sum[idi-1]-you,d)*a[idi]+l;
    dlog("%lld\n",x);
    return x;
}
int32 main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++){
        cin>>v[i];
        sum[i]=sum[i-1]+v[i];
    }
    for(int i=1;i<=n;i++) cin>>a[i];
    cout<<f(n,n)<<endl;
    return 0;
}