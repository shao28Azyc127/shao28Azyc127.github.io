#include<bits/stdc++.h>
using namespace std;
int T,M;
int a,b,c;
//ding si !!!!!!!!!!!!
int dt,t;
int cal_sq(int x){
    if(x==0) return 0;
    int res;
    for(int i=1;i*i<=x;i++){
        if(x%(i*i)==0) res=i;
    }
    return res;
}
//10:41  ->  18:41
int gcd(int x,int y){
return __gcd(abs(x),abs(y));
}
bool chk(){
    if(gcd(b,2*a)==gcd(t,2*a)&&dt==1) return 1;
    return 0;
}
void yf(int &x,int &y){
    bool fl=0;
    if(x<0) fl^=1;
    if(y<0) fl^=1;
    x=abs(x);
    y=abs(y);

    int cnt=gcd(x,y);
    x/=cnt;
    y/=cnt;

    if(fl==1) x=-x;
}
void out_fm(int x){
    if(x==1) return;
    printf("/%d",x);
    return;
}
void out_sq(int x){
    if(x==1){
        printf("1");
    }
    else
    printf("sqrt(%d)",x);
    return;
}
void out_mtp(int x){
    if(x==1) return;
    if(x==-1){
        printf("-");
        return;
    }
    printf("%d*",x);
    return;
}
void out_st1(){
    int fz=-b+t;

    int fm=a*2;



    yf(fz,fm);
    printf("%d",fz);
    out_fm(fm);
}
bool out_fr(){
    //-b/2a
    int fz=-b;
    int fm=a*2;
    if(fz==0) return 0;
    yf(fz,fm);
    printf("%d",fz);
    out_fm(fm);
    return 1;
}
void out_ls(int op){
    int fz=t;
    int fm=abs(a*2);

    yf(fz,fm);
    if(fz==0) return;
    if(op==1){
        if(fz>0){
            printf("+");
            out_mtp(fz);
            out_sq(dt);
            out_fm(fm);
        }
        if(fz<0){
            out_mtp(fz);
            out_sq(dt);
            out_fm(fm);
        }
    }
    else{
        out_mtp(fz);
        out_sq(dt);
        out_fm(fm);
    }
}
//-3 -18 54
int main(){
 //   freopen("dat","r",stdin);
    freopen("uqe.in","r",stdin);
        freopen("uqe.out","w",stdout);


    cin>>T>>M;
    while(T--){
        cin>>a>>b>>c;
        dt=b*b-4*a*c;
        if(dt<0){
            puts("NO");
            continue;
        }
        t=cal_sq(dt);
        //xi shu
        if(t!=0)
            dt/=(t*t);
        if(chk())
            out_st1();
        else{
            int op=out_fr();
            out_ls(op);
        }
        printf("\n");
    }
    return 0;
}
