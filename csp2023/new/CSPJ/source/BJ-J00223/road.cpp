#include<bits/stdc++.h>
using namespace std;
int n,d,t,s=0;
int v[1000000],a[1000000];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d",&n,&d);
    for(int i=1;i<n;i++){
        scanf("%d",&v[i]);
        s+=v[i];
    }
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    t=s/d*a[1];
    printf("%d",t);
    return 0;
}
