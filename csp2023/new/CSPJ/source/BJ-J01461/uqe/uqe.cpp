#include<bits/stdc++.h>
#define up(i,l,r) for(int i=(l);i<=(r);++i)
#define down(i,l,r)for(int i=(l);i>=(r);--i)
#define p_b push_back
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
inline ll read(){
    ll x=0;
    short t=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')t=-1;
        ch=getchar();
    }while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x*t;
}ll a,b,c;
bool chk(int x){
    int y=sqrtl(x);
    return (y*y==x);
}int gcd(int a,int b){
    return ((!b)?a:gcd(b,a%b));
}void print(int x,int y){
    if(!x){printf("0");return;}
    if(y<0)y=-y,x=-x;
    if(x<0)printf("-"),x=-x;
    int g=gcd(x,y);
    x/=g,y/=g;
    if(y==1)printf("%d",x);
    else printf("%d/%d",x,y);
}
void slv(){
    a=read(),b=read(),c=read();
    if(a<0)a=-a,b=-b,c=-c;
    ll d=b*b-4*a*c;
    if(d<0){
        printf("NO\n");
        return;
    }if(chk(d)){
        ll x=-b+sqrtl(d);
        print(x,2*a);printf("\n");
        return;
    }if(b){
        print(-b,2*a);
        printf("+");
    }int q2=1;
    up(i,2,sqrtl(d)){
        if(d%(i*i)==0)q2=i;
    }d/=q2*q2;a*=2;
    ll g=gcd(q2,a);
    q2/=g,a/=g;
    if(q2!=1)printf("%d*",q2);
    printf("sqrt(%d)",d);
    if(a!=1)printf("/%d",a);
    printf("\n");
}int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t=read();read();while(t--)slv();
    fclose(stdin);
    fclose(stdout);
    return 0;
}