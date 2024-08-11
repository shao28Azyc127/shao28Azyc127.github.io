#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,up;
    scanf("%d%d",&t,&up);
    while(t--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        int drta=b*b-4*a*c;
        if(drta<0){
            printf("NO\n");
        }else{
            int c=sqrt(drta);
            if(c*c==drta){
                int z=(-b+sqrt(drta)),m=2*a;
                if(m<0){
                    m*=-1;
                    z*=-1;
                }
                int o=z;
                z/=__gcd(m,abs(z));
                m/=__gcd(m,abs(o));
                if(m==1){
                    printf("%d\n",z);
                }else{
                    printf("%d/%d\n",z,m);
                }
            }else{
                int z=-b,m=-2*a;
                if(m<0){
                    m*=-1;
                    z*=-1;
                }
                int o=z;
                z/=__gcd(m,abs(z));
                m/=__gcd(m,abs(o));
                if(m==1){
                    if(z!=0){printf("%d+",-z);}
                }else{
                    if(z!=0){printf("%d/%d+",-z,m);}
                }
                int q2=1,x=2*a;
                for(int i=2;i*i<=drta;i++){
                    if(drta%i==0){
                        q2*=i;
                        drta/=(i*i);
                    }
                }
                int o1=q2;
                q2/=__gcd(q2,x);
                x/=__gcd(x,o1);
                if(q2==x){
                    printf("sqrt(%d)\n",drta);
                }
                else if(x==1){
                    printf("%d*sqrt(%d)\n",q2,drta);
                }
                else if(q2==1){
                    printf("sqrt(%d)/%d\n",drta,x);
                }else{
                   printf("%d*sqrt(%d)/%d\n",q2,drta,x);
                }
            }
        }

    }
}
