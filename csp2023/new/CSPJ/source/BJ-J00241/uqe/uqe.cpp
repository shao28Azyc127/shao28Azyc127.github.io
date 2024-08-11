#include<bits/stdc++.h>
#define int long long
using namespace std;

const int maxn=2100+10;
int t,m,a,b,c;
int sq[maxn]; 
inline void init(){
    for(int i=0;i<=2100;i++)sq[i]=i*i;
}
inline int gcd(int x,int y){
    if(x<0)return gcd(abs(x),y);
    if(y<0)return gcd(x,abs(y));
    if(x<y)return gcd(y,x);
    if(y==0)return x;
    return gcd(y,x%y);
}
inline void solve(){
    scanf("%lld%lld",&t,&m);
    while(t--){
        scanf("%lld%lld%lld",&a,&b,&c);
        if(b*b-4*a*c<0)printf("NO\n");
        else if(b*b-4*a*c==0){
            if(b==0){
                printf("0\n");
                continue;
            }
            else{
                b=-b;
                if(a<0)b=-b;
                a=abs(a);
                int p=gcd(2*a,b);
                if(2*a/p==1)printf("%lld\n",b/p);
                else printf("%lld/%lld\n",b/p,2*a/p);
            }
        }
        else{
            int x=b*b-4*a*c,s=1;
            bool is=false;
            if(a<0)is=true;
            for(int i=2100;i>=1;i--){
                if(x%sq[i]==0){
                    s=i;
                    break;
                }
            }
            // printf("%lld\n",s);
            // if((int)x/sq[s]==4)s*=2;
            // int l=x/sq[s];
            // if(l==4)s*=2;
            if(s==1){
                if(x==1){
                    b=-b;
                    if(!is)++b;
                    else --b;
                    if(a<0)b=-b;
                    a=abs(a);
                    int p=gcd(2*a,b);
                    if(2*a/p==1)printf("%lld\n",b/p);
                    else printf("%lld/%lld\n",b/p,2*a/p);
                }
                else{
                    b=-b;
                    bool flag=false;
                    if(a<0){
                        b=-b;
                        a=abs(a);
                        flag=true;
                    }
                    int p=gcd(2*a,b);
                    if(b==0)goto end1;
                    if(2*a/p==1)printf("%lld",b/p);
                    else printf("%lld/%lld",b/p,2*a/p);
                    printf("+");
                    end1:
                    // if(flag)a=-a;
                    printf("sqrt(%lld)/%lld\n",x,2*a);
                }
            }
            else{
                x/=sq[s];
                if(abs(x)==1){
                    b=-b;
                    if(!is)b+=s;
                    else b-=s;
                    if(a<0)b=-b;
                    a=abs(a);
                    int p=gcd(2*a,b);
                    if(2*a/p==1)printf("%lld\n",b/p);
                    else printf("%lld/%lld\n",b/p,2*a/p);
                }
                else{
                    b=-b;
                    bool flag=false;
                    if(a<0){
                        a=abs(a);
                        b=-b;
                        s=-s;
                        flag=true;
                    }
                    int p=gcd(2*a,b);
                    if(b==0)goto end2;
                    if(2*a/p==1)printf("%lld",b/p);
                    else printf("%lld/%lld",b/p,2*a/p);
                    printf("+");
                    end2:
                    int q=gcd(2*a,s);
                    int cnt=0;
                    // if(flag)++cnt;
                    if(abs(2*a/q)==1){
                        if(abs(s/q)==1){
                            // if(s/q==-1)++cnt;
                            // if(flag)printf("-");
                            printf("sqrt(%lld)\n",x);
                        }
                        else {
                            // if(flag)s=-s;
                            printf("%lld*sqrt(%lld)\n",abs(s)/q,x);
                        }
                    }
                    else{
                        if(abs(s/q)==1){
                            // if(s/q==-1)++cnt;
                            // if(flag)a=-a;
                            printf("sqrt(%lld)/%lld\n",x,2*a/q);
                        }
                        else {
                            // if(flag)printf("-");
                            printf("%lld*sqrt(%lld)/%lld\n",abs(s)/q,x,2*a/q);
                        }
                    }
                }
            }
        }
    }
}
signed main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    init();
    solve();
    return 0;
}