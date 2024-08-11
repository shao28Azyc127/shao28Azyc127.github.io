#include <bits/stdc++.h>
using namespace std;
long long a,b,c,T,m;
double t1,t2;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    scanf("%lld%lld",&T,&m);
    while(T--){
        scanf("%d%d%d",&a,&b,&c);
        if(b*b-4.0*a*c<0) printf("NO");
        else{
            t1=-b+sqrt(b*b-4.0*a*c)/(a*2.0);
            t2=-b-sqrt(b*b-4.0*a*c)/(a*2.0);
            printf("%f",max(t1,t2));
        }
    }
    return 0;
}
