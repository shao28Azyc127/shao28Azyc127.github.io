#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,c,r,q1,q2;
int gcd(int x,int y){
    if(x%y==0){
        return y;
    }
    return gcd(y,x%y);
}
void print(int x,int y){
    if(y==1){
        printf("%d",x);
    }
    else{
        if(x<0&&y<0){
            printf("%d/%d",-x,-y);
        }
        else{
            printf("%d/%d",x,y);
        }
    }
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    scanf("%d %d",&n,&m);
    while(n--){
        scanf("%d %d %d",&a,&b,&c);
        r=b*b-4*a*c;
        if(r<0){
            printf("NO\n");
            continue;
        }
        else if(r>=0){
            q1=-b;q2=2*a;
        }
        if(sqrt(r)*sqrt(r)==r){
            int Gcd=gcd(abs(q1+sqrt(r)),abs(q2));
            q2=q2/Gcd;
            q1=(q1+sqrt(r))/Gcd;
            print(q1,q2);
            printf("\n");
            continue;
        }
        if(q1!=0){
            int Gcd=gcd(abs(q1),abs(q2));
            q2=q2/Gcd;q1=(q1)/Gcd;
            print(q1,q2);
            printf("+");
        }
        if(q1==q2){
            printf("sqrt(%d)",r);
        }
        else if(q1/q2==q1/q2*q2){
            printf("%d*sqrt(%d)",q1/q2,r);
        }
        else if(q2/q1==q2/q1*q1){
            printf("sqrt(%d)/%d",r,q2/q1);
        }
        else{
            int Gcd=gcd(abs(q1),abs(q2));
            q2=q2/Gcd;q1=(q1)/Gcd;
            printf("%d*sqrt(%d)/%d",q1,q2/q1,q2);
        }
        printf("\n");
    }
    return 0;
}
