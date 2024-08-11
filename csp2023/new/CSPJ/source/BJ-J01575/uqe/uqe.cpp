#include<bits/stdc++.h>
using namespace std;
int T,M;
int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
void printpq(int fz,int fm){
    int g=gcd(fz,fm);
    fz/=g,fm/=g;
    if(fm<0)fm=-fm,fz=-fz;
    if(fm==1) printf("%d",fz);
    else printf("%d/%d",fz,fm);
}
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    scanf("%d%d",&T,&M);
    while(T--){
        int a,b,c,dt;
        scanf("%d%d%d",&a,&b,&c);
        dt=b*b-4*a*c;
        if(dt<0)printf("NO\n");
        else{
            int gdt=sqrt(dt);
            if(gdt*gdt==dt){
                int fz=(a>0)?(-b+gdt):(-b-gdt),fm=2*a;
                printpq(fz,fm);printf("\n");
            }
            else{
                if(b!=0){
                    printpq(-b,2*a);printf("+");
                }
                int q2=1,fm=2*a;
                if(fm<0)fm=-fm;
                for(register int i=2;i*i<=dt;++i)
                    while(dt%(i*i)==0)q2*=i,dt=dt/i/i;
                int g=gcd(q2,fm);
                q2/=g,fm/=g;
                if(fm==1){
                    if(q2==1)printf("sqrt(%d)\n",dt);
                    else printf("%d*sqrt(%d)\n",q2,dt);
                }else{
                    if(q2==1)printf("sqrt(%d)/%d\n",dt,fm);
                    else printf("%d*sqrt(%d)/%d\n",q2,dt,fm);
                }
            }
        }
    }
    return 0;
}