#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=200010;
int n,d,a[MAXN],u[MAXN];
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld%lld",&n,&d);
    for(int i=1;i<n;i++){
        scanf("%lld",&u[i]);
        u[i]=u[i-1]+u[i];
    }
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    int now=a[1],sum=0,id=1,x=0;
    for(int i=2;i<=n;i++){
        if(a[i]<now){
            if(sum>=u[i-1]-u[id-1]){
                sum-=u[i-1]-u[id-1];
                now=a[i];id=i;
            }
            else{
                x+=((u[i-1]-u[id-1]-sum-1)/d+1)*now;
                sum=((u[i-1]-u[id-1]-sum-1)/d+1)*d+sum-(u[i-1]-u[id-1]);
                now=a[i];id=i;
            }
        }
    }
    if(sum>=u[n-1]-u[id-1]){
        sum-=u[n-1]-u[id-1];
    }
    else{
        x+=((u[n-1]-u[id-1]-sum-1)/d+1)*now;
        sum=((u[n-1]-u[id-1]-sum-1)/d+1)*d+sum-(u[n-1]-u[id-1]);
    }
    printf("%lld",x);
    fclose(stdin);
    fclose(stdout);
    return 0;
}

//zycakioi