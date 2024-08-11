#include<bits/stdc++.h>
using namespace std;
const int MAX=1e5+5;
long long n,d,oil,mx=MAX,l=1;
long long ans;
long long dis[MAX],a[MAX];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    scanf("%d %d",&n,&d);
    for(int i=2;i<=n;i++){
        int v;
        scanf("%d",&v);
        dis[i]=dis[i-1]+v;
    }
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
    }
    a[n]=0;
    for(int i=1;i<=n;i++){
        if(a[i]<a[l]){
            if(oil>=dis[i]-dis[l]){
                oil-=dis[i]-dis[l];
                l=i;
            }
            else{
                ans+=(dis[i]-dis[l]-oil+d-1)/d*a[l];
                oil=d-(dis[i]-dis[l]-oil)%d;
                l=i;
            }
        }
    }
    printf("%lld",ans);
    return 0;
}
