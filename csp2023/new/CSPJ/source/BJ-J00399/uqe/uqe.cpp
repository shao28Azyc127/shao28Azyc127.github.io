#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e3+10;
int gcd(int a,int b){
    return !b?a:gcd(b,a%b);
}
int p[MAXN],ip[MAXN],cnt;
void diaomao(int n){
    for(int i=2;i<=n;i++){
        if(!ip[i]) p[++cnt]=i;
        for(int j=1;j<=cnt&&i*p[j]<=n;j++){
            ip[i*p[j]]=1;
            if(i%p[j]==0) break;
        }
    }
}
struct in{
    int fz,fm;
    void easy(){
        int g=gcd(fz,fm);
        fz/=g,fm/=g;
        if(fz>0&&fm<0) fz*=-1,fm*=-1;
    }
    void print(){
        easy();
        if(fz==0) return;
        if(fm==1) printf("%d",fz);
        else printf("%d/%d",fz,fm);
    }
    in operator +(const in &x){
        in ans=(in){fz*x.fm+fm*x.fz,fm*x.fm};
        ans.easy();
        return ans;
    }
};
struct nn{
    in a;
    int r;
    void easy(){
        int i=1;
        while(r&&i<=cnt){
            while(r%(p[i]*p[i])==0){
                r/=p[i]*p[i];
                a.fz*=p[i];
            }
            i++;
        }
        a.easy();
    }
    void print(){
        a.easy();
        if(a.fz==0||r==0) return;
        if(a.fz!=1) printf("%d",a.fz);
        if(a.fz!=1&&r!=1) putchar('*');
        if(r!=1) printf("sqrt(%d)",r);
        if(a.fm!=1) printf("/%d",a.fm);
    }
};
int t,m;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    diaomao(1000);
    scanf("%d%d",&t,&m);
    while(t--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        int delta=b*b-4*a*c;
        if(delta<0){
            printf("NO\n");
            continue;
        }
        in dcz;
        nn rot;
        if(a>0){
            dcz=(in){-b,2*a};
            dcz.easy();
            rot=(nn){(in){1,2*a},delta};
            rot.easy();
            if(rot.r==1)dcz=dcz+rot.a;
        }
        else{
            dcz=(in){-b,2*a};
            dcz.easy();
            rot=(nn){(in){-1,2*a},delta};
            rot.easy();
            if(rot.r==1)dcz=dcz+rot.a;
        }
        if(rot.r==1){
            if(dcz.fz==0) putchar('0');
            else dcz.print();
        }
        else{
            dcz.print();
            if(dcz.fz!=0&&rot.a.fz!=0&&rot.r!=0) putchar('+');
            rot.print();
            if(dcz.fz==0&&(rot.a.fz==0||rot.r==0)) putchar('0');
        }
        putchar('\n');
    }
    return 0;
}
