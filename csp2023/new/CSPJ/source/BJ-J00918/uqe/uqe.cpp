#include<bits/stdc++.h>
using namespace std;
int T,M;
int a,b,c;
bool sml=0;
int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b,a%b);
}
bool delta(int a,int b,int c){
    return b*b>=4*a*c;
}
int sq(int d){
    for(int i=sqrt(d);i>=1;i--){
        if(d%(i*i)==0)return i;
    }
    return 1;
}
void Q(int p,int q){
    if(p==0){
        printf("0");
        return;
    }
    if((p>0&&q>0)||(p<0&&q<0)){
        p=abs(p),q=abs(q);
        int g=gcd(p,q);
        p=p/g;
        q=q/g;
        if(q==1)printf("%d",p);
        else printf("%d/%d",p,q);
    }
    else{
        p=abs(p),q=abs(q);
        int g=gcd(p,q);
        p=p/g;
        q=q/g;
        if(q==1)printf("-%d",p);
        else printf("-%d/%d",p,q);
    }
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);

    scanf("%d%d",&T,&M);
    while(T--){
        scanf("%d %d %d",&a,&b,&c);
        if(a<0)sml=1;
        else sml=0;
        if(!delta(a,b,c)){
            printf("NO\n");
            continue;
        }
        int d=b*b-4*a*c;
        if(int(sqrt(d))==sqrt(d)){
            d=sqrt(d);
            Q(-b+(sml?-d:d),a*2);
        }
        else{
            int q2=sq(d),r=d/q2/q2;
            if(b!=0){
                Q(-b,a*2);
                printf("+");
            }
            if(sml)a=-a;
            a*=2;
            if(q2==a)printf("sqrt(%d)",r);
            else if(q2%a==0)printf("%d*sqrt(%d)",q2/a,r);
            else if(a%q2==0)printf("sqrt(%d)/%d",r,a/q2);
            else{
                int g=gcd(q2,a);
                q2=q2/g;
                a=a/g;
                printf("%d*sqrt(%d)/%d",q2,r,a);
            }
        }
        printf("\n");
    }
    return 0;
}
