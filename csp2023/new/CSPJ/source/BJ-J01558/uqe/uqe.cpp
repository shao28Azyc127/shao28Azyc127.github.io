#include<bits/stdc++.h>
using namespace std;
template<typename T>void read(T &x){
    x=0;char c=getchar();int f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
    x*=f;
}
template<typename T,typename ...Args>
void read(T &x,Args &...rest){read(x);read(rest...);}

int T,M,a,b,c,delta;

int gcd(int x,int y){return y==0?x:gcd(y,x%y);}
void write_Q(int b,int a){
    if(a<0)a=-a,b=-b;
    if(b<0)putchar('-'),b=-b;
    int g=gcd(b,a);
    b=b/g;a=a/g;
    if(a==1)printf("%d",b);
    else printf("%d/%d",b,a);
}
void solve(){
    read(a,b,c);
    delta=b*b-4*a*c;
    if(delta<0)return (void)printf("NO\n");
    if(a<0)a=-a,b=-b,c=-c;
    if(delta==0){
        write_Q(-b,2*a);
        printf("\n");
        return;
    }
    int p1=1;
    for(int i=1500;i>1;i--)if(delta%(i*i)==0){
        delta/=i*i;
        p1*=i;
    }
    if(delta==1)write_Q(-b+p1,2*a),printf("\n");
    else{
        if(b)write_Q(-b,2*a),putchar('+');
        int g=gcd(p1,2*a);
        p1/=g;a=a*2/g;
        if(p1==a)printf("sqrt(%d)\n",delta);
        else if(a==1)printf("%d*sqrt(%d)\n",p1,delta);
        else if(p1==1)printf("sqrt(%d)/%d\n",delta,a);
        else printf("%d*sqrt(%d)/%d\n",p1,delta,a);
    }
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    read(T,M);
    while(T--)solve();
    return 0;
}
