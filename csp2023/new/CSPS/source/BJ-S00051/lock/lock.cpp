#include <bits/stdc++.h>
using namespace std;
long long n, tmp, a[9], ans=0, b[6], c[6];
bool check(long long x,long long y){
    for(long long i=1;i<=5;i++) b[i]=x%10, c[i]=y%10, x/=10, y/=10;
    long long cnt=0;
    for(long long i=1;i<=5;i++) if(b[i]!=c[i]) cnt++;
    if(cnt==1) return 1;
    if(cnt==2){
        for(long long i=1;i<=4;i++){
            if(b[i]==c[i]) continue;
            long long aa=b[i]-c[i], bb=b[i+1]-c[i+1], cc=aa-bb;
            return cc==-10||cc==0||cc==10;
        }
    }
    return 0;
}
bool chk(long long x){
    for(long long i=1;i<=n;i++) if(!check(a[i],x)) return 0;
    return 1;
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++){
        a[i]=0;
        for(long long j=1;j<=5;j++){
            scanf("%lld",&tmp);
            a[i]=a[i]*10+tmp;
        }
    }
    for(long long i=1;i<=99999;i++) if(chk(i)) ans++;
    return printf("%lld",ans)&0;
}