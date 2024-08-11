#include<cstdio>
#include<cmath>
int t,m;
int gcd(int a,int b){
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int lcm(int a,int b){
    return a*b/gcd(a,b);
}
struct num1{//有理数
    int p,q;
    void reset(){
        if(q<0){
            q=-q;
            p=-p;
        }
        if(p==0){
            q=1;
            return;
        }
        int g=gcd(abs(p),abs(q));
        p/=g;
        q/=g;
    }
    void print(){
        reset();
        if(q==1)
            printf("%d",p);
        else
            printf("%d/%d",p,q);
    }
};
struct num2{//无理数
    num1 q1,q2;
    int r;
    void reset(){
        if(r==0){
            r=1;
            q2.p=0;
            q2.q=1;
        }
        for(int i=2;i*i<=r;i++)
            while(r%(i*i)==0){
                r/=i*i;
                q2.p*=i;
            }
        q1.reset();
        q2.reset();
        if(r==1){
            int l=lcm(q1.q,q2.q);
            q1.p*=l;
            q1.q*=l;
            q2.p*=l;
            q2.q*=l;
            q1.p+=q2.p;
            q2.p=0;
            q1.reset();
            q2.reset();
        }
    }
    void print(){
        reset();
        if(q1.p!=0){
            q1.print();
            if(r==1)
                return;
            printf("+");
        }
        q2.reset();
        if(q2.p==1&&q2.q==1)
            printf("sqrt(%d)",r);
        else if(q2.q==1)
            printf("%d*sqrt(%d)",q2.p,r);
        else if(q2.p==1)
            printf("sqrt(%d)/%d",r,q2.q);
        else
            printf("%d*sqrt(%d)/%d",q2.p,r,q2.q);
    }
};
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    scanf("%d%d",&t,&m);
    while(t--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        int d;
        d=b*b-4*a*c;
        if(d<0){
            printf("NO\n");
            continue;
        }
        num2 ans;
        ans.q1.p=-b;
        ans.q1.q=2*a;
        ans.q2.p=1;
        ans.q2.q=2*a;
        ans.r=d;
        ans.print();
        printf("\n");
    }
    return 0;
}