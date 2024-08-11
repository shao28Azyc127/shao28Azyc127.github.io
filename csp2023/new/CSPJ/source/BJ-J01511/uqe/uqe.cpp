#include <bits/stdc++.h>
using namespace std;
int t,m;
int w[1000010],cnt;
bool book[1000010];
void print(int s,int x){
    int gcd=__gcd(s,x);
    s/=gcd;
    x/=gcd;
    if(x==1) printf("%d",s);
    else{
        if(x<0) x*=-1,s*=-1;
        printf("%d/%d",s,x);
    }
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    scanf("%d%d",&t,&m);
    for(int i=2;i*i<=m*m;i++){
        if(!book[i]){
            w[++cnt]=i*i;
            for(int j=i*i;j<=m*m;j+=i*i) book[j]=1;
        }
    }
    while(t--){
        double a,b,c;
        scanf("%lf%lf%lf",&a,&b,&c);
        double dt=b*b-4*a*c;
        if(dt<0){
            printf("NO\n");
            continue;
        }
        /*double x1=(-b+sqrt(dt))/(2*a);
        double x2=(-b-sqrt(dt))/(2*a);
        double x=max(x1,x2);*/
        if(int(sqrt(dt))*int(sqrt(dt))==dt){
            bool fff=0;
            double x1=(-b+sqrt(dt))/(2*a);
            double x2=(-b-sqrt(dt))/(2*a);
            if(x1>x2) fff=1;
            int s=fff?(-b+sqrt(dt)):(-b-sqrt(dt)),x=(2*a);
            print(s,x);
            putchar('\n');
        }else{
            if(b!=0){
                print(int(-b),int(2*a));
                putchar('+');
            }
            int s=1,x=2*a;
            for(int i=cnt;i>=1;i--)
                while(int(dt)%w[i]==0) s*=sqrt(w[i]),dt/=w[i];
            int gcd=__gcd(s,x);
            s/=gcd;
            x/=gcd;
            if(x<0) x*=-1,s*=-1;
            if(s==1&&x==1) printf("sqrt(%.0lf)",dt);
            else if(x==1) printf("%d*sqrt(%.0lf)",s,dt);
            else if(s==1) printf("sqrt(%.0lf)/%d",dt,x);
            else printf("%d*sqrt(%.0lf)/%d",s,dt,x);
            putchar('\n');
        }
    }
    return 0;
}
