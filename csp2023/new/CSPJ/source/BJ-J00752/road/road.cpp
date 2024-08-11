#include<bits/stdc++.h>
using namespace std;
int n,v;
int a[100005];
long long s[100005];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d %d",&n,&v);
    for(int i=2;i<=n;i++){
        int x;
        scanf("%d",&x);
        s[i]+=s[i-1]+x;
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    long long ans=0,d=0;
    int now=1;
    for(int i=2;i<=n;i++){
        if(a[i]<a[now]||i==n){
            if(d<s[i]-s[now]){
                ans+=1ll*ceil(1.0*((s[i]-s[now])-d)/v)*a[now];
                d+=1ll*ceil(1.0*((s[i]-s[now])-d)/v)*v;
                d-=s[i]-s[now];
            }
            now=i;
        }
    }
    printf("%lld",ans);
    return 0;
}
