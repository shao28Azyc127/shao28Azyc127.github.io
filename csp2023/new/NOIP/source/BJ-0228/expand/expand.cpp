#include<bits/stdc++.h>
using namespace std;
const int N = 5;
int O,n,m,q,a[N],b[N],c[N],d[N];
bool check(int A[],int B[]){
    if(n == 1 && m == 2){
        if(A[1] < B[1] && A[1] < B[2]) return 1;
        if(A[1] > B[1] && A[1] > B[2]) return 1;
        return 0;
    }
    if(n == 2 && m == 1){
        if(A[1] < B[1] && A[2] < B[1]) return 1;
        if(A[1] > B[1] && A[2] > B[1]) return 1;
        return 0;
    }
    if(A[1] > B[1] && A[2] > B[2]) return 1;
    if(A[1] < B[1] && A[2] < B[2]) return 1;
    return 0;
}
int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    scanf("%d%d%d%d",&O,&n,&m,&q);
    for(int i = 1;i <= n;i++)
        scanf("%d",&a[i]);
    for(int i = 1;i <= m;i++)
        scanf("%d",&b[i]);
    if(O == 1) printf("%d",a[1] != b[1]);
    if(O == 2) printf("%d",check(a,b));
    for(int o = 1;o <= q;o++){
        int kx,ky; scanf("%d%d",&kx,&ky);
        memcpy(c,a,sizeof(c)); memcpy(d,b,sizeof(d));
        for(int i = 1;i <= kx;i++){
            int x,v; scanf("%d%d",&x,&v);
            c[x] = v;
        }
        for(int i = 1;i <= ky;i++){
            int x,v; scanf("%d%d",&x,&v);
            d[x] = v;
        }
        if(O == 1) printf("%d",c[1] != d[1]);
        if(O == 2) printf("%d",check(c,d));
    }
    printf("\n");
    return 0;
}