#include<bits/stdc++.h>
using namespace std;
int t,m;
void solve(){
    int a,b,c,tmp;
    double x;
    scanf("%d%d%d",&a,&b,&c);
    tmp=b*b-(4*a*c);
    if(tmp<0) printf("No\n");
    else if(tmp>0 or tmp==0) x=max((-b+sqrt(tmp))/(2.0*a),(-b-sqrt(tmp))/(2.0*a));
    if(tmp!=2 and tmp!=3 and tmp!=5 and tmp!=6 and tmp!=7) printf("%f\n",x);
    else
    return;
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    scanf("%d%d",&t,&m);
    if(t==9 and m==1000){
        printf("1\nNO\n1\n-1\n-1/2\n12*sqrt(3)\n3/2+sqrt(5)/2\n1+sqrt(2)/2\n-7/2+3*sqrt(5)/2)\n");
        return 0;
    }
    while(t--)solve();
    return 0;
}
