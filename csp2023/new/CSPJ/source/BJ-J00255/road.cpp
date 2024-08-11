#include <bits/stdc++.h>
using namespace std;
long long n,m;
int v[100005],a[100005];
unsigned long long ans=0;
long long minn=2e18;
long long minid;
unsigned long long lc=0;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >>n >>m;
    for(int i=1;i<n;i++) cin >>v[i];
    for(int i=1;i<=n;i++) cin >>a[i];
    minn=a[1];
    minid=1;
    if(v[1]%m==0) ans+=(v[1]/m)*a[1],lc=0;
    else ans+=(v[1]/m)*a[1]+a[1],lc=m-(v[1]%m);
    for(int i=2;i<n;i++){
        if(minn>a[i]){
            minn=a[i];
            minid=i;
            v[i]-=lc;
            lc=0;
            if(v[i]%m==0){
                ans+=(v[i]/m)*a[minid];
            }else{
                lc=m-(v[i]%m);
                ans+=(v[i]/m)*a[minid]+a[minid];
            }
        }else{
            v[i]-=lc;
            lc=0;
            if(v[i]%m==0){
                ans+=(v[i]/m)*a[minid];
            }else{
                lc=m-(v[i]%m);
                ans+=(v[i]/m)*a[minid]+a[minid];
            }
        }
    }
    cout <<ans <<'\n';
    return 0;
}
