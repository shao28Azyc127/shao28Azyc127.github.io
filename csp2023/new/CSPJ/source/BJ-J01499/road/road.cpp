#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
long long n,m,money[maxn],oil[maxn],l[maxn],ans=0;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m;
    for(long long i=0;i<n-1;i++) cin>>oil[i];
    l[0]=oil[0];
    for(long long i=1;i<n;i++) l[i]=l[i-1]+oil[i];
    for(long long i=0;i<n;i++) cin>>money[i];
    long long len=0,ol=0;
    while(len!=n-1){
        long long go_to=n-1;
        for(long long i=len+1;i<n;i++){
            if(money[i]<money[len]){
                go_to=i; break;
            }
        }
        long long u=l[go_to-1]-l[len-1];
        if(ol>=u){
            ol-=u; continue;
        }else u-=ol,ol=0;
        if(u%m==0) ans+=u/m*money[len];
        else ans+=(u/m+1)*money[len],ol+=m-u%m;
        len=go_to;
    }
    cout<<ans<<endl;
    return 0;
}
