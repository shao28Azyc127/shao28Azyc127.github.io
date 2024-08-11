#include<bits/stdc++.h>
using namespace std;
bool check(int x){
    if(i<2)return 0;
    for(int i=2;i<=sqrt(x);i++){
        if(x%i==0)return 0;
    }
    return 0;
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m;
    scanf("%d%d",&t,&m);
    while(t--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        double sj=b*b-4*a*c;
        if(sj<0){
            printf("NO\n");
            continue;
        }
        double x1=(-b+sqrt(sj))/(2*a),x2=(-b-sqrt(sj))/(2*a);
        double x=max(x1,x2);
        if(x==int(x)){
            printf("%.0lf\n",x);
            continue;
        }
        double q1=-b,q2=0.5/a;

        printf("\n");
    }
    return 0;
}
