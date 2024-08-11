#include<bits/stdc++.h>
using namespace std;

int t,m,a,b,c;
int ma(int x){
    for(int i=sqrt(x);i>0;i--){
        if(x%(i*i)==0)return i;
    }
}
int gcd(int x,int y){
    if(x<0)x=-x;
    if(y<0)y=-y;
    if(x>y)swap(x,y);
    if(x==0)return y;
    return gcd(y%x,x);
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    scanf("%d%d",&t,&m);
    while(t--){
        scanf("%d%d%d",&a,&b,&c);
        int ch=b*b-4*a*c;
        if(ch<0){
            printf("NO\n");
        }
        else if(ch==0){
            int q1=2*a,q2=-b;
            if(q2%q1){
                int x=gcd(q2,q1);
                printf("%d/%d\n",q2/x,q1/x);
            }
            else printf("%d\n",q2/q1);
        }
        else{
            if(a>0){
                int sqr=ma(ch);
                int q1=-b;
                int q2=2*a;
                if(ch/sqr/sqr==1){
                    q1+=sqr;
                    if(q1%q2==0){
                        printf("%d\n",q1/q2);
                    }
                    else{
                        int x=gcd(q1,q2);
                        printf("%d/%d\n",q1/x,q2/x);
                    }
                }
                else{
                    if(q1%q2==0){
                        if(q1)printf("%d",q1/q2);
                    }
                    else{
                        int x=gcd(q1,q2);
                        printf("%d/%d",q1/x,q2/x);
                    }
                    int x=gcd(sqr,q2);
                    if(q1)printf("+");
                    sqr/=x;
                    q2/=x;
                    ch/=x*x;
                    if(sqr!=1&&q2!=1)printf("%d*sqrt(%d)/%d\n",sqr,ch/sqr/sqr,q2);
                    else if(q2==1)printf("%d*sqrt(%d)\n",sqr,ch/sqr/sqr);
                    else printf("sqrt(%d)/%d\n",ch/sqr/sqr,q2);
                }
            }
            else{
                int sqr=ma(ch);
                int q1=-b;
                int q2=2*a;
                if(ch/sqr/sqr==1){
                    q1+=sqr;
                    if(q1%q2==0){
                        printf("%d\n",q1/q2);
                    }
                    else{
                        int x=gcd(q1,q2);
                        printf("%d/%d\n",q1/x,q2/x);
                    }
                }
                else{
                    if(q1%q2==0){
                        if(q1)printf("%d",q1/q2);
                    }
                    else{
                        int x=gcd(q1,q2);
                        printf("%d/%d",q1/x,q2/x);
                    }
                    int x=gcd(sqr,q2);
                    if(q1)printf("+");
                    sqr/=x;
                    q2/=x;
                    ch/=x*x;
                    if(sqr!=1&&q2!=-1)printf("%d*sqrt(%d)/%d\n",sqr,ch/sqr/sqr,-q2);
                    else if(q2==-1)printf("%d*sqrt(%d)\n",sqr,ch/sqr/sqr);
                    else printf("sqrt(%d)/%d\n",ch/sqr/sqr,-q2);
                }
            }
        }
    }
    return 0;
}
