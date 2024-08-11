#include <bits/stdc++.h>
using namespace std;
int v[10005],a[10005],n,d;;
long long sum=0,l=0;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d",&n,&d);
    if(n<=0||d<=0||n>10000||d>10000)
        return 0;
    for(int i=0;i<n-1;i++){
        scanf("%d",&v[i]);
        if(v[i]<=0||v[i]>10000)
            return 0;
    }
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        if(a[i]<=0||a[i]>10000)
            return 0;
    }
    for(int i=0;i<n;i++){
        l+=v[i];
    }
    if(l%4!=0)
        sum=(l/d+1)*a[0];
    else
        sum=(l/d)*a[0];
    printf("%d\n",sum);
    return 0;
}
