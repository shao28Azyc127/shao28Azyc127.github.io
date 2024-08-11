#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=5000010;
int t,m,a,b,c,delta,pfs[MAXN];
void is_pfs(){
    for(int i=1;i<=m*2;i++){
        pfs[i*i]=i;
    }
}
int ggcd(int x,int y){
    if(x==0)return y;
    return ggcd(y%x,x);
}
int pfsyz(int x){
    int ans=1;
    for(int i=2;i*i<=x;i++){
        if(pfs[i*i]>0&&x%(i*i)==0)ans=i;
    }
    return ans;
}
signed main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    scanf("%lld%lld",&t,&m);is_pfs();
    while(t--){
        scanf("%lld%lld%lld",&a,&b,&c);
        delta=b*b-4*a*c;
        if(delta<0){
            printf("NO\n");
            continue;
        }
        if(delta==0){
            if(b!=0){
                int gd=ggcd(-b,2*a);
                if(2*a<0)gd=-abs(gd);
                else gd=abs(gd);
                int p=(-b)/gd,q=(2*a)/gd;
                if(q==1){
                    printf("%lld\n",p);
                }
                else{
                    printf("%lld/%lld\n",p,q);
                }
            }
            else{
                printf("0\n");
            }
        }
        if(delta>0){
            if(pfs[delta]>0){
                if(2*a>0){
                    int gac4=pfs[delta];
                    if(-b+gac4!=0){
                        int gd=ggcd(-b+gac4,2*a);
                        if(2*a<0)gd=-abs(gd);
                        else gd=abs(gd);
                        int p=(-b+gac4)/gd,q=(2*a)/gd;
                        if(q==1){
                            printf("%lld\n",p);
                        }
                        else{
                            printf("%lld/%lld\n",p,q);
                        }
                    }
                    else{
                        printf("0\n");
                    }
                }
                else{
                    int gac4=pfs[delta];
                    if(-b-gac4!=0){
                        int gd=ggcd(-b-gac4,2*a);
                        if(2*a<0)gd=-abs(gd);
                        else gd=abs(gd);
                        int p=(-b-gac4)/gd,q=(2*a)/gd;
                        if(q==1){
                            printf("%lld\n",p);
                        }
                        else{
                            printf("%lld/%lld\n",p,q);
                        }
                    }
                    else{
                        printf("0\n");
                    }
                }
            }
            else{
                if(b!=0){
                    int gd=ggcd(-b,2*a);
                    if(2*a<0)gd=-abs(gd);
                    else gd=abs(gd);
                    int p=(-b)/gd,q=(2*a)/gd;
                    if(q==1){
                        printf("%lld+",p);
                    }
                    else{
                        printf("%lld/%lld+",p,q);
                    }
                }
                int q2=pfsyz(delta);
                if(q2%(2*a)==0){
                    if(abs(q2/(2*a))==1){
                        printf("sqrt(%lld)\n",delta/q2/q2);
                    }
                    else{
                        printf("%lld*sqrt(%lld)\n",abs(q2/(2*a)),delta/q2/q2);
                    }
                }
                else{
                    if((2*a)%q2==0){
                        printf("sqrt(%lld)/%lld\n",delta/q2/q2,abs(2*a/q2));
                    }
                    else{
                        int ggcc=ggcd(q2,a*2);
                        printf("%lld*sqrt(%lld)/%lld\n",abs(q2/ggcc),delta/q2/q2,abs(a*2/ggcc));
                    }
                }
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
//zycakioi