#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
struct Q{
    int up,dn;
};
int T,M;
int gcd(int a,int b){
    if(b==0)return a;
    else return gcd(b,a%b);
}
Q setq(int a,int b){
    Q q;
    int c=gcd(abs(a),abs(b));
    if(c!=0){
        a=a/c;
        b=b/c;
    }
    else{
        q.up=0;
        q.dn=1;
        return q;
    }
    if(b<0){
        a=-a;
        b=-b;
    }
    q.up=a;
    q.dn=b;
    return q;
}
void outq(Q q){
    if(q.dn==1){
        printf("%d",q.up);
    }
    else printf("%d/%d",q.up,q.dn);
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    scanf("%d%d",&T,&M);
    for(int i=1;i<=T;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        int delta=b*b-4*a*c;
        if(delta<0){
            printf("NO\n");
            continue;
        }
        else{
            int k=gcd(abs(b),abs(2*a));
            Q q1=setq(-1*b,2*a);
            if(delta==0){
                outq(q1);
                printf("\n");
                continue;
            }
            int sqr=1;
            for(int j=2;j*j<=M;j++){
                int cnt=j*j;
                while(delta%cnt==0){
                    delta/=cnt;
                    sqr*=j;
                }
            }
            if(delta==1){
                int t1=(q1.up*k+sqr),t2=abs(2*a);
                int k1=gcd(abs(t1),(t2));
                q1=setq(t1,t2);
                outq(q1);
                printf("\n");
                continue;
            }
            else{
                Q q2=setq(sqr,2*abs(a));
                int r=delta;
                if(q1.up!=0){
                    outq(q1);
                    printf("+");
                }
                bool b1=(q2.up==1),b2=(q2.dn==1);
                if(b1&b2){
                    printf("sqrt(%d)",r);
                }else if(b2){
                    printf("%d*sqrt(%d)",q2.up,r);
                }
                else if(b1){
                    printf("sqrt(%d)/%d",r,q2.dn);
                }else{
                    printf("%d*sqrt(%d)/%d",q2.up,r,q2.dn);
                }printf("\n");
            };
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
