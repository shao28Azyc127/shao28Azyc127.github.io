#include<bits/stdc++.h>
using namespace std;
double a,b,c,d,w;
int check(double x){
    double we=x*2*a;
    if(((int)(we/a))==we/a){
        we/=a;
    }
    if(((int)(we/2))==we/2){
        we/=2;
    }
    if(((int)we)!=we){
        return -1;
    }
    return we/x;
}
int zzlww(int x){
    int ans=x;
    for(int i=2;i<=x;++i){
        if(x%i!=0){
            continue;
        }
        int z=0;
        while(x%i==0){
            ++z;
            x/=i;
        }
        if(z&1==1){
            ans/=i;
        }
    }
    return ans;
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int T,qqq;
    scanf("%d%lf",&T,&qqq);
    while(T--){
        scanf("%lf%lf%lf",&a,&b,&c);
        d=b*b-4*a*c;
        if(d<0){
            printf("NO\n");
            continue;
        }
        double x=max((-b-sqrt(d))/2/a,(-b+sqrt(d))/2/a);
        if(((int)x)==x){
            printf("%.0lf\n",x);
            continue;
        }
        int e=check(x);
        if(e!=-1){
            printf("%.0lf/%d\n",x*e,e);
            continue;
        }
        double p=(-b)/2/a;
        if(p!=0){
            e=check(p);
            if(((int)p)==p){
                printf("%.0lf",p);
            }else{
                printf("%.0lf/%d",p*e,e);
            }
            printf("+");
        }
        double q=zzlww((int)d);
        int r=d/q;
        q=sqrt(q)/2/a;
        if(q==1){
            printf("sqrt(%d)\n",r);
            continue;
        }
        if(((int)q)==q){
            printf("%.0lf*sqrt(%d)\n",q,r);
            continue;
        }
        e=check(q);
        if(q*e==1){
            printf("sqrt(%d)/%d\n",r,e);
            continue;
        }
        printf("%.0lf*sqrt(%d)/%d\n",q*e,r,e);
    }
    return 0;
}
