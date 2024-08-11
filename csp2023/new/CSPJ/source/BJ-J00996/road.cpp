#include<bits/stdc++.h>
using namespace std;
long long v[100001],a[100001];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    long long d;
    int n;
    scanf("%d%lld",&n,&d);
    for(int i=1;i<=n-1;i++){
        scanf("%lld",&v[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    int s=1;
    double l=0;
    long long ans=0;
    while(s<n){
        int id=s;
        for(int i=s+1;i<=n-1;i++){
            if(a[id]>a[i]){
                id=i;
                break;
            }
        }
        if(id==s){
            id=n;
        }
        long long sum=0;
        for(int i=s;i<=id-1;i++){
            sum+=v[i];
        }
        sum-=l*d;
        l=0;
        ans+=(sum/d+min(sum%d,1ll))*a[s];
        l+=(sum%d)/(d+0.0);
        s=id;
    }
    printf("%lld",ans);
}
