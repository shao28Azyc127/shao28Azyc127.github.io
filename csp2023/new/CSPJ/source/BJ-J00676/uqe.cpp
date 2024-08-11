#include<bits/stdc++.h>
using namespace std;
int T,M,an[1000];
int gcd(int x,int y){
    if(x>y){
        swap(x,y);
    }
    if(x==0) return y;
    return gcd(y%x,x);
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    scanf("%d%d",&T,&M);
    for(int i=1;i<1000;++i){
        an[i]=i*i;
    }
    while(T--){
        int a,b,c,del,fu=0,gab,zdel=0,sz,ifh=0,wm=1,num=2;
        scanf("%d%d%d",&a,&b,&c);
        if(a<0){
            a=-a,b=-b,c=-c;
        }
        del=b*b-4*a*c;
        if(del<0){
            printf("NO\n");
            continue;
        }
        sz=-b;
        int sqt=sqrt(del);
        if(sqt*sqt==del){
            sz+=sqt;
            ifh=1;
        }
        if(sz!=0){
            if(sz<0) sz=-sz,fu=1;
            gab=gcd(2*a,sz);
            if(fu) printf("-");
            printf("%d",sz/gab);
            if((2*a)!=gab) printf("/%d",a*2/gab);
        }
        if(ifh){
            printf("\n");
            continue;
        }
        while(num<1000){
            while(del%an[num]==0){
                wm*=num;
                del/=an[num];
            }
            ++num;
        }
        if(sz!=0) printf("+");
        int gac=gcd(2*a,wm);
        wm/=gac;
        a=2*a/gac;
        if(wm>1) printf("%d*",wm);
        printf("sqrt(%d)",del);
        if(a!=1) printf("/%d",a);
        printf("\n");
    }
    return 0;
}

