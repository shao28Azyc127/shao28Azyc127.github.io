#include<bits/stdc++.h>
using namespace std;
int a[100005],ju[100005],n,d;
long long ans,t,dis,oil;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d %d",&n,&d);
    for(int i=2;i<=n;i++){
        scanf("%d",&ju[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        dis=0;oil=0;
        int j=i+1;
        dis+=ju[j];
        while(a[j]>a[i]&&j<=n){
            j++;
            dis+=ju[j];
        }
        dis-=t;
        oil=dis/d;
        if(oil*d<dis){
            oil++;
        }
        t=oil*d-dis;
        ans+=oil*a[i];
        i=j-1;
    }
    printf("%lld",ans);
    return 0;
}
