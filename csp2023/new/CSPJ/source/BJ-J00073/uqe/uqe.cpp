#include <iostream>
#include <cmath>
using namespace std;
int T, m, a, b, c;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    scanf("%d%d",&T,&m);
    while(T--){
        scanf("%d%d%d",&a,&b,&c);
        int delta=b*b-4*a*c;
        if(delta<0) puts("NO");
        else printf("%d\n",max(int(-b+sqrt(delta))/2/a,int(-b-sqrt(delta))/2/a));
    }
    return 0;
}