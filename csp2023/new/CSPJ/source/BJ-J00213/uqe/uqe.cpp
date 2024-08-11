#include <bits/stdc++.h>
using namespace std;
int SS(int x){
    int tmp=0,i;
    for (i=1; i*i<=x; i++) ;
    return i-1;
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m,a,b,c;
    scanf("%d%d",&t,&m);
    while (t--){
        scanf("%d%d%d",&a,&b,&c);
        int x=b*b-4*a*c;
        if (x<0) printf ("NO\n");
        else printf("%d\n",(-b+SS(x))/(2*a));
    }
    return 0;
}