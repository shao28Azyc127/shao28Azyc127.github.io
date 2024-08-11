#include<bits/stdc++.h>
using namespace std;

int gen(int x){
    int l=0,r=10000;
    while (l<=r){
        int mid=(l+r)/2;
        if (mid*mid==x) return mid;
        if (mid*mid>x) r=mid-1;
        else l=mid+1;
    }
    return -1;
}

int gcd(int x,int y){
    x=(int)abs(x), y=(int)abs(y);
    int r=x%y;
    while (r!=0){
        x=y; y=r; r=x%y;
    }
    return y;
}

int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int T,m;
    scanf("%d%d",&T,&m);
    while (T--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if (c==0){
            if (b>=0) printf("0\n");
            else{
                int d=gcd(a,b);
                a/=d; b/=d;
                if (b<0){b=-b; a=-a;}
                printf("%d/%d\n",b,a); 
            }
            continue;
        }
        int delta=b*b-4*a*c;
        if (delta<0){
            printf("NO\n"); continue;
        }

        int ret=gen(delta);
        if (ret!=-1){
                int mx=max(-b+ret,-b-ret),mi=min(-b+ret,-b-ret);
                int bc,c=2*a;
                if (a<0) bc=mi;
                else bc=mx;
                int div=gcd(bc,c);
                bc/=div; c/=div;
                if (bc<0&&c<0){
                    bc=-bc; c=-c;
                }

            if (bc!=0){
                if (c==1) printf("%d",bc);
                else if (c==-1) printf("-%d",bc);
                else{
                    if (c>0) printf("%d/%d",bc,c);
                    else printf("-%d/%d",bc,-c);
                }
            }else printf("0");
            
        }else{
           int bc=-b, c=2*a;
            int div=gcd(bc,c);
            bc/=div; c/=div;
            if (bc<0&&c<0){
                bc=-bc; c=-c;
            }

            if (bc!=0){
                if (c==1) printf("%d",bc);
                else if (c==-1) printf("-%d",bc);
                else{
                    if (c>0) printf("%d/%d",bc,c);
                    else printf("-%d/%d",bc,-c);
                }
                printf("+");
            }
            int dai=1;
            for (int i=m;i>1;i--){
                if (delta%(i*i)==0){
                    dai=i; delta/=(i*i);
                    break;
                }
            }

            if (dai==1){
                printf("sqrt(%d)/%d\n",delta,(int)abs(2*a)); continue;
            }
            
            bc=dai, c=2*a;
            div=gcd(bc,c);
            bc/=div; c/=div;
            if (bc<0&&c<0){
                bc=-bc; c=-c;
            }
            c=(int)abs(c);

            if (bc!=0&&bc!=1){
                if (c==1) printf("%d*sqrt(%d)",bc,delta);
                else{
                    printf("%d*sqrt(%d)/%d",bc,delta,c);
                }
            }else if (bc==1){
                if (c==1) printf("sqrt(%d)",delta);
                else{
                    printf("sqrt(%d)/%d",delta,c);
                }
            }
        }
        printf("\n");
    }
    return 0;
}