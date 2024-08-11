#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<map>
#include<vector>
#include<set>
#include<stack>
#define int long long
#define ull unsigned long long
using namespace std;
int t,m;
int gcd(int x,int y){
    if(x<y)swap(x,y);
    if(y==0)return x;
    return gcd(y,x%y);
}
int pf[105];
signed main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    scanf("%lld%lld",&t,&m);
    for(int i=1;i<=100;i++){
        pf[i]=i*i;
    }
    while(t--){
        int a,b,c;
        scanf("%lld%lld%lld",&a,&b,&c);
        if(b*b-4*a*c<0){
            puts("NO");
            continue;
        }
        int dt=b*b-4*a*c;
       // cout<<"dt:"<<dt<<endl;
        if((int)(sqrt(dt))*(int)(sqrt(dt))==dt){
            int s=sqrt(dt);
            int up;
            if(a>0)up=-b+s;
            else up=-b-s;
            if(up==0){
                puts("0");
                continue;
            }
            int down=2*a;
            if(up*down>0){//tong hao
                if(up<0)up*=-1,down*=-1;
                int g=gcd(up,down);
                up/=g,down/=g;
                if(down==1){
                    printf("%lld\n",up);
                }else{
                    printf("%lld/%lld\n",up,down);
                }
            }else{
                if(up<0)up*=-1;
                if(down<0)down*=-1;
                int g=gcd(up,down);
                up/=g,down/=g;
                if(down==1){
                    printf("-%lld\n",up);
                }else{
                    printf("-%lld/%lld\n",up,down);
                }
            }
        }else{
            int s=1;
            for(int i=2;i<=100;i++){
                if(dt<pf[i])break;
                while(dt%pf[i]==0){
                       // cout<<dt<<' '<<pf[i]<<endl;
                    dt/=pf[i];
                    s*=i;
                }
            }
            //cout<<s<<endl;
            int up=-b,tmpdown=2*a;
            if(up!=0){
                int down=tmpdown;
                if(up*down>0){
                    if(up<0)up*=-1,down*=-1;
                    int g=gcd(up,down);
                    up/=g,down/=g;
                    if(down==1)printf("%lld",up);
                    else printf("%lld/%lld",up,down);
                    putchar('+');
                }else{
                    if(up<0)up*=-1;
                    if(down<0)down*=-1;
                    int g=gcd(up,down);
                    up/=g,down/=g;
                    if(down==1)printf("-%lld",up);
                    else printf("-%lld/%lld",up,down);
                    putchar('+');
                }
            }
            int down=tmpdown;
            if(down<0)down*=-1;
            int g=gcd(s,down);
            s/=g,down/=g;
            if(down==1){
                if(s==1)printf("sqrt(%lld)\n",dt);
                else printf("%lld*sqrt(%lld)\n",s,dt);
            }
            else{
                if(s!=1)
                    printf("%lld*sqrt(%lld)/%lld\n",s,dt,down);
                else
                    printf("sqrt(%lld)/%lld\n",dt,down);
            }
        }
    }
    return 0;
}
