#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d,a1,v1,i,m,sv=0,ms=10001;
    scanf("%d %d",&n,&d);
    int v[n-1],a[n];
    for(i=0;i<n-1;i++){
        scanf("%d",&v1);
        v[i]=v1;
        sv+=v[i];
        if(ms>v1){
            ms=v1;
        }
    }
    for(i=0;i<n;i++){
        scanf("%d",&a1);
        a[i]=a1;
    }
    printf("%d",a[0]*(sv/d));
}
