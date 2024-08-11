#include<bits/stdc++.h>
#define up(i,l,r) for(int i=(l);i<=(r);++i)
#define down(i,l,r)for(int i=(l);i>=(r);--i)
using namespace std;
typedef long long ll;
inline ll read(){
    ll x=0;
    short t=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')t=-1;
        ch=getchar();
    }while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x*t;
}int calc1(ll n){
    int cnt=0;
    while(n)n-=n/3+((n%3>=1)?1:0),cnt++;
    return cnt;
}int calc2(ll n){
    int cnt=0;
    while(n%3!=1)n=n/3*2+((n%3>1)?1:0),cnt++;
    return cnt+1;
}void slv(){
    ll n=read();
    printf("%d %d\n",calc1(n),calc2(n));
}int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    slv();
    fclose(stdin);
    fclose(stdout);
    return 0;
}