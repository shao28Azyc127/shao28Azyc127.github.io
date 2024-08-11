#include<bits/stdc++.h>
const int N=1e6+3;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d,v[N],a[N],nows=0,od,money=0,o[N];
    double oil=0.0,lastoil;
    scanf("%d%d",&n,&d);
    o[0]=1;
    for(int i=0;i<n-1;i++){
        scanf("%d",&v[i]);
        o[i+1]=o[i]+v[i];
    }
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    while(nows!=n-1){
        lastoil=oil;
        od=nows;
        while(a[nows]<=a[od]&&od<n){
            od++;
        }
        oil+=ceil((double)(o[od]-o[nows]-(lastoil*d))/d);
        money+=((int)ceil((double)(o[od]-o[nows]-(lastoil*d))/d))*a[nows];
        oil-=(double)(o[od]-o[nows])/d;
        nows=od;
    }
    printf("%d",money);
    return 0;
}