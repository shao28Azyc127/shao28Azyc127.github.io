#include<bits/stdc++.h>
using namespace std;
int t,m;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    scanf("%d%d",&t,&m);
    while(t--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        int s=(b*b)-(4*a*c);
        if(s<0){
            printf("NO\n");
            continue;
        }
        double x1=((-b)+(sqrt(s)))/(2*a);
        double x2=((-b)-(sqrt(s)))/(2*a);
        double x=max(x1,x2);
        int l=x;
        if(x==l){
            printf("%d\n",l);
            continue;
        }
        bool f=0;
        for(int p=-m;p<=m;p++){
            for(int q=1;q<=m;q++){
                if(__gcd(abs(q),abs(p))==1&&(p*1.0)/(q*1.0)==x){
                    printf("%d/%d\n",p,q);
                    f=1;
                    break;
                }
            }
            if(f==1)break;
        }
    }
    return 0;
}
