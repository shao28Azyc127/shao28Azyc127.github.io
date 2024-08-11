#include<bits/stdc++.h>
using namespace std;
int T,M;
int gcd(int a,int b){
    return (!b?a:gcd(b,a%b));
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    scanf("%d%d",&T,&M);
    while(T--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        int x=b*b-4*a*c;
        if(x<0){
            puts("NO");
            continue;
        }
        int p1=-b,p2=1,q=2*a;
        for(int i=2;i*i<=x;i++) while(x%(i*i)==0) p2*=i,x/=i*i;
        if(q<0) p2=-p2;
        if(!b){
            if(x==1){
                int _gcd=gcd(p2,q);
                if(q<_gcd<0) p2=-p2,q=-1;
                if(p2%q==0) printf("%d\n",p2/q);
                else printf("%d/%d\n",p2/_gcd,q/_gcd);
            }
            else if(!x){puts("0");}
            else{
                int _gcd=gcd(p2,q);
                if(q/_gcd<0) p2=-p2,q=-q;
                if(p2==q) printf("sqrt(%d)\n",x);
                else if(q%p2==0) printf("sqrt(%d)/%d\n",x,q/p2);
                else if(q==1) printf("%d*sqrt(%d)\n",p2,x);
                else if(p2%q==0) printf("%d*sqrt(%d)\n",p2/q,x);
                else printf("%d*sqrt(%d)/%d\n",p2/_gcd,x,q/_gcd);
            }
        }
        else if(!x){
            int _gcd=gcd(p1,q);
            if(q/_gcd<0) p1=-p1,q=-q;
            if(p1%q==0) printf("%d\n",p1/q);
            else printf("%d/%d\n",p1/_gcd,q/_gcd);
        }
        else if(x==1){
            int P=p1+p2,Q=q;
            int _gcd=gcd(P,Q);
            if(Q/_gcd<0) P=-P,Q=-Q;
            if(P%Q==0) printf("%d\n",P/Q);
            else printf("%d/%d\n",P/_gcd,Q/_gcd);
        }
        else{
            int _gcd1=gcd(p1,q),_gcd2=gcd(p2,q);
            int f=0;
            if(q/_gcd1<0) p1=-p1,q=-q,f=1;
            if(p1%q==0) printf("%d+",p1/q);
            else printf("%d/%d+",p1/_gcd1,q/_gcd1);
            if(f) q=-q;
            if(q/_gcd2<0) p2=-p2,q=-q;
            if(p2==q) printf("sqrt(%d)\n",x);
            else if(q%p2==0) printf("sqrt(%d)/%d\n",x,q/p2);
            else if(q==1) printf("%d*sqrt(%d)\n",p2,x);
            else if(p2%q==0) printf("%d*sqrt(%d)\n",p2/q,x);
            else printf("%d*sqrt(%d)/%d\n",p2/_gcd2,x,q/_gcd2);
        }
    }
    return 0;
}

