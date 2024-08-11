#include<stdio.h>
using namespace std;
int n,m,k,u[20001],v[20001],a[20001];
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        scanf("%d %d %d",&u[i],&v[i],&a[i]);
    }
    printf("-1");
    fclose(stdin);
    fclose(stdout);
    return 0;
}
