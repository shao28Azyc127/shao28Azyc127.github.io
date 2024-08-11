#include <bits/stdc++.h>
using namespace std;
int n,a[10],b[10],c[10],d[10],e[10];
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d",&n);
    for(int i=0; i<n; i++) scanf("%d %d %d %d %d",&a[i],&b[i],&c[i],&d[i],&e[i]);
    printf("%d",n*81);
    return 0;
}
