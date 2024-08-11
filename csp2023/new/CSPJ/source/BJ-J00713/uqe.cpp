#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
long long p[1000050],sqp[1000050],cnt;
bool isp[1000050];
void pre(){
    memset(isp,1,sizeof(isp));

    isp[1]=0;cnt=0;
    for(long long i=2;i<=1000050;i++){
        if(!isp[i])continue;
        else{
            p[++cnt]=i;
            sqp[cnt]=i*i;
            for(long long k=i+i;k<=1000050;k+=i){
                isp[k]=0;
            }
        }
    }
}
long long gcd(long long x,long long y){
    if(x<y)swap(x,y);
    if(x%y==0)return y;
    return gcd(y,x-y);
}
long long abss(long long p){
    if(p<0)return -p;
    else return p;
}
void op(long long x,long long y){
    if(x==0){
        printf("0");
        return ;
    }
    long long op=1;
    if(x<0)op=-op;
    if(y<0)op=-op;
    x=abss(x);y=abss(y);
    long long ggcd=gcd(x,y);
    x=x/ggcd;y=y/ggcd;
    if(y==1){
        printf("%lld",op*x);
    }else{
        printf("%lld/%lld",op*x,y);
    }
}
long long wk(long long num){
    long long ret=1;
    for(long long i=1;i<=cnt;i++){
        if(num==1)return ret;
        if(sqp[i]>num)return ret;
        if(p[i]>1000){
            ret=ret*sqrt(num);
            return ret;
        }
        while(num%sqp[i]==0){
            num=num/sqp[i];
            ret=ret*p[i];
        }
        while(num%p[i]==0){
            num=num/p[i];
        }
    }
    return ret;
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    pre();
    long long t,inf;
    cin>>t>>inf;
    while(t--){
        long long a,b,c;
        scanf("%lld%lld%lld",&a,&b,&c);
        long long dlt=b*b-4*a*c;
        if(dlt<0){
            cout<<"NO"<<'\n';
            continue;
        }
        if(dlt==0){
            if(b==0){
                cout<<0<<'\n';
                continue;
            }
            op(-b,a*2);printf("\n");
            continue;
        }
        else{
            //¶Ôdlt²ð·Ö
            long long bas=wk(dlt),div=abss(2*a);
            dlt=dlt/(bas*bas);

            if(dlt==1){
                if(a<0){
                    op(-b-bas,2*a);
                    printf("\n");
                    continue;
                }else{
                    op(-b+bas,2*a);
                    printf("\n");
                    continue;
                }
            }else{
                long long ggcd=gcd(bas,div);
                bas=bas/ggcd;
                div=div/ggcd;
                if(b!=0){
                    op(-b,a*2);
                    printf("+");
                }
                if(bas!=1){
                    printf("%lld*",bas);
                }
                printf("sqrt(%lld)",dlt);
                if(div!=1){
                    printf("/%lld",div);
                }
                printf("\n");
            }
        }
    }
    return 0;
}
