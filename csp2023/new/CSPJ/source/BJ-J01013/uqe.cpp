//uqe.cpp
#include <bits/stdc++.h>

using namespace std;
bool bigflag=false;
struct fract{
    int fz,fm;
};
int t,m;
int gd(int a,int b){
    if(b==0) return a;
    else return gd(b,a%b);
}
fract ad(fract a,fract b){
    fract ret;
    ret.fm=a.fm*b.fm;
    ret.fz=a.fz*b.fm+b.fz*a.fm;
    int g=gd(ret.fz,ret.fm);
    ret.fz/=g;ret.fm/=g;
    return ret;
}
void prfrac(fract a){
    if(a.fz==0){
        bigflag=true;
        return;
    }
    int g=gd(a.fz,a.fm);
    a.fz/=g;a.fm/=g;
    if(a.fm<0){
        a.fm=-a.fm;
        a.fz=-a.fz;
    }
    bigflag=false;
    if(a.fm==1){
        printf("%d",a.fz);
    }else{
        printf("%d/%d",a.fz,a.fm);
    }
}
fract frac(int a,int b){
    fract ret;
    if(a*b<0){
        ret.fz=-1;
    }else{
        ret.fz=1;
    }
    if(a<0)a=-a;
    if(b<0)b=-b;
    if(a%b==0){
        ret.fm=1;ret.fz*=a/b;
        return ret;
    }
    int g=gd(a,b);
    ret.fz*=(a/g);ret.fm=b/g;
    return ret;
}
fract sq(int dt,int fm,fract prev){
    int outer=0;
    for(int i=sqrt(dt);i*i>=1;i--){
        if(dt%(i*i)==0){
            outer=i;
            break;
        }
    }
    dt=dt/(outer*outer);
    int g=gd(outer,fm);
    if(dt==1){
        return frac(outer,fm);
    }else{
        prfrac(prev);
        bigflag=false;
        if(prev.fz!=0)printf("+");
        if(outer==1){
            if(outer%fm==0){
                printf("sqrt(%d)",dt);
            }else{
                printf("sqrt(%d)/%d",dt,fm);
            }
        }else{
            if(outer%fm==0){
                if(outer/fm==1)printf("sqrt(%d)",dt);
                else printf("%d*sqrt(%d)",outer/fm,dt);
            }else{
                if(outer/g==1)printf("sqrt(%d)/%d",dt,fm/g);
                else printf("%d*sqrt(%d)/%d",outer/g,dt,fm/g);
            }
        }
    }
    fract z;
    z.fm=0;
    return z;
}
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    scanf("%d%d",&t,&m);
    while(t--){
        bigflag=false;
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if(b*b-4*a*c<0){
            printf("NO\n");
            continue;
        }
        int opt=1;
        double fir=(-b+sqrt(1.0*b*b-4.0*a*c))*1.0/(a*2.0);
        double sec=(-b-sqrt(1.0*b*b-4.0*a*c))*1.0/(a*2.0);
        if(fir<sec)opt=-1;
        fract p,q;
        p=frac(-b,a*2);
        if(b*b-4*a*c==0){
            prfrac(p);
            if(bigflag){
                printf("0");
            }
            printf("\n");
            continue;
        }
        if(opt==-1){
            q=sq(b*b-4*a*c,a*-2,p);
        }else{
            q=sq(b*b-4*a*c,a*2,p);
        }
        if(q.fm!=0){
            prfrac(ad(q,p));
        }
        if(bigflag){
            printf("0");
        }
        printf("\n");
    }
    return 0;
}
