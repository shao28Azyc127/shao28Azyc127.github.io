#include<bits/stdc++.h>
using namespace std;
int T,M;
int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
struct Rnum{
    int a,b;
    void upd(){
        int g=gcd(a,b);
        a/=g;
        b/=g;
        if(b<0){
            a*=-1;
            b*=-1;
        }
    }
    Rnum(int x,int y){
        a=x;b=y;
        upd();
    }
    void print(){
        if(b==1) printf("%d",a);
        else printf("%d/%d",a,b);
    }
};
int main(){
    #ifndef JZQ
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    #endif
    scanf("%d%d",&T,&M);
    while(T--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        int delta=b*b-4*a*c;
        if(delta<0) printf("NO");
        else if(delta==0){
            Rnum q=Rnum(-b,2*a);
            q.print();
        }
        else{
            int d=1;
            for(int i=2;i*i<=delta;i++){
                while(delta%(i*i)==0){
                    d*=i;
                    delta/=i*i;
                }
            }
            if(a<0) d*=-1;
            if(delta==1){
                Rnum q=Rnum(-b+d,2*a);
                q.print();
            }
            else{
                Rnum q1=Rnum(-b,2*a),q2=Rnum(d,2*a);
                if(q1.a!=0){
                    q1.print();
                    printf("+");
                }
                if(q2.a!=1) printf("%d*",q2.a);
                printf("sqrt(%d)",delta);
                if(q2.b!=1) printf("/%d",q2.b);
            }
        }
        printf("\n");
    }
    return 0;
}