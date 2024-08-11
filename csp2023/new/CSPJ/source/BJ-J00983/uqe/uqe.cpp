#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int k,m;scanf("%d%d",&k,&m);
    while(k--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        int d=b*b-(4*a*c);
        if(d<0){printf("NO\n");continue;}
        printf("%d\n",(0-b+((int)sqrt(d)))/2/a);
    }
}
