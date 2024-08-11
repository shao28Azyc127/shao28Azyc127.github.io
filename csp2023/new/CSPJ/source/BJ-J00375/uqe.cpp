#include<bits/stdc++.h>
#define ll long long
using namespace std;
template<typename T>
inline void read(T &x){
    x=0;int f=1;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
    for(;isdigit(c);c=getchar()) x=x*10+(c-'0');
    x*=f;
}
template<typename T>
inline void write(T x){
    if(x>=10) write(x/10);
    putchar(x%10+48);
}
int T,M;
int no_root(int a,int b,int c){
    if(b*b-4*a*c<0) return 1;
    else return 0;
}
int gcd(int x,int y){
    return y==0?x:gcd(y,x%y);
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    read(T);read(M);
    while(T--){
        int a,b,c;
        read(a);read(b);read(c);
        if(no_root(a,b,c)){printf("NO\n");continue;}
        int delta=b*b-4*a*c,t=1;
        for(int i=2;i*i<=delta;++i){
            while(delta%(i*i)==0){
                t*=i;
                delta/=(i*i);
            }
        }


        int af=1;
        if(a<0) af=-1;
        int tmp=abs(a*2);
        if(delta==1){
            int ans,rans;
            if(a<0) ans=abs(-b-t),rans=-b-t;
            else ans=abs(t-b),rans=t-b;
            int f=1;if(rans<0) f=-1;
            int GCD=gcd(tmp,ans);
            tmp/=GCD;
            ans/=GCD;
            f*=af;
            printf("%d",f*ans);
            if(tmp!=1) printf("/%d",tmp);
            printf("\n");
            continue;
        }

        af=1;
        if(a<0) af=-1;
        tmp=abs(a*2);
        int B=abs(b);
        int f=1;if(b>0) f=-1;
        if(B!=0){
            int GCD=gcd(tmp,B);
            B/=GCD;tmp/=GCD;
            f*=af;
            printf("%d",B*f);
            if(tmp!=1) printf("/%d",tmp);
        }

        af=1;
        if(a<0) af=-1;
        tmp=abs(a*2);
        if(delta!=0){
            int GCD=gcd(t,tmp);
            tmp/=GCD;t/=GCD;
            if(B!=0){
                printf("+");
            }
            if(t!=1) printf("%d*",t);
            printf("sqrt(%d)",delta);
            if(tmp!=1) printf("/%d",tmp);
        }
        printf("\n");
    }
    return 0;
}
