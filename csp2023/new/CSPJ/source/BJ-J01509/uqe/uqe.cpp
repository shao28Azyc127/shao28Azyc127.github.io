#include<bits/stdc++.h>
using namespace std;
int n,k,a,b,c,i,j;
bool t;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;i++){
        t=0;
        scanf("%d%d%d",&a,&b,&c);
        for(j=1;j<=k;j++){
            if(a*j*j+b*j+c==0){
                t=1;
                printf("%d\n",j);
                break;
            }
        }
        for(j=-1;j>=-k;j--){
            if(t)break;
            if(a*j*j+b*j+c==0){
                t=1;
                printf("%d\n",j);
                break;
            }
        }
        if(!t)puts("NO");
    }
    return 0;
}
