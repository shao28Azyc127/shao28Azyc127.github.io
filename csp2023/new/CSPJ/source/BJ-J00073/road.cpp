#include <iostream>
using namespace std;
int n, d, v[100005], a[100005], tot=0, s, t=0, oil=0;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d",&n,&d);
    for(int i=1;i<=n-1;i++) scanf("%d",&v[i]);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) tot+=a[i];
    s=(tot+d-1)/d*a[1];
    for(int i=1;i<=n-1;i++){
        while(oil<v[i]) t+=a[i], oil+=d;
        oil-=v[i];
    }
    printf("%d",min(s,t));
    return 0;
}
