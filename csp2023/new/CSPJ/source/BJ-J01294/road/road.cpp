#include <iostream>
#include <cstdio>
int v[100005],a[100005],s[100005],nna[100005],nnv[100005];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d,cur=0,t=0,nn,ni,last;
    scanf("%d%d",&n,&d);
    last=n+1;
    for(int i=2;i<=n;++i){
        scanf("%d",&v[i]);
        s[i]=s[i-1]+v[i];
    }
    for(int i=1;i<=n;++i)scanf("%d",&a[i]);
    while(last!=1){
        nn=200000000;
        for(int i=1;i<last;++i){
            if(a[i]<nn){
                nn=a[i];
                ni=i;
            }
        }
        nna[++cur]=ni;
        last=ni;
        ni=0;
    }
    for(int i=cur;i>=1;--i){
        nnv[i]=s[nna[i-1]]-s[nna[i]-1];
        t+=a[nna[i]]*nnv[i];
    }
    printf("%d",t/d+4);
    return 0;
}
