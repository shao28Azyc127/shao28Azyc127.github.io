#include<bits/stdc++.h>
using namespace std;
int a[10005][10005];
void goin(int x){
    for(int i=1; i<=n; i++){
        if(i == n){
            printf("%d",a[x][n]);
            return;
        }
        else{
            goin(i);
        }
    } 
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    int n, m, k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1; i<=n; i++){
        int l, r, v;
        scanf("%d%d%d",&l,&r,&v);
        a[l][r] = v;
    }
    goin(1);
    return 0;
}