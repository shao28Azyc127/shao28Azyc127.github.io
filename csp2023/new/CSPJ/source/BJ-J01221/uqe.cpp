#include <bits/stdc++.h>

using namespace std;

int gcd(int x,int y){
    int tmp=0;
    if(x>y)
        tmp=x-y;
    else
        tmp=y-x;
    if(tmp==0)
        return x;
    return gcd(tmp,min(x,y));
}

int check(float k,float l){
    float asd=k/l;
    if(asd>=0)
        return 1;
    else if(asd<0)
        return -1;
}

int outint(int z,int d){
    int pn=check(z,d);
    if(pn==-1) printf("-");
    int gg=gcd(abs(z),abs(d));
    if(abs(d)/gg==1)
        printf("%d",abs(z)/gg);
    else
        printf("%d/%d",abs(z)/gg,abs(d)/gg);
}

int split(int qq,int mode){
    for(int ii=int(sqrt(qq));ii>0;ii--){
        if(qq%(ii*ii)==0){
            if(mode==0)
                return ii;
            if(mode==1)
                return qq/(ii*ii);
        }
    }
}

int spe(int z, int d,int del){
    int pn=check(z,d);
    if(pn==-1) printf("-");
    int gg=gcd(abs(z),abs(d));
    printf("%d*sqrt(%d)/%d\n",abs(z)/gg,del,abs(d)/gg);
}
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m; float a,b,c;
    scanf("%d%d",&t,&m);
    for(int i=0;i<t;i++){
        scanf("%f%f%f",&a,&b,&c);
        float delta=b*b-4*a*c;
        if(delta<0){
            printf("NO\n");
            continue;
        }
        float anssqrt=sqrt(delta);
        float ans1=(-b+anssqrt)/2*a, ans2=(-b-anssqrt)/2*a; int ud,geshi; //1=+ -1=-
        if(ans1>=ans2) ud=1; else if(ans2>ans1) ud=-1;
        if(float(int(anssqrt))==anssqrt){
            int up,down;
            up=-b+anssqrt; down=2*a;
            if(up==0||down==0){
                printf("0\n");
                continue;
            }
            outint(up,down); printf("\n");
            continue;
        }
        float q1=-b/(2*a), q2=split(delta,0)*ud/(2*a); int inside=split(delta,1);
        if(q1!=0){
            outint(-b,2*a); printf("+");
        }

       if(q2==0)
            printf("sqrt(%d)\n",inside);
        else if(float(int(q2))==q2){
            outint(split(delta,0)*ud,(2*a)); printf("*sqrt(%d)\n",inside);
        }
        else if(float(int(1/q2))==(1/q2)){
            int q4=(2*a)/(ud*split(delta,0));
            printf("sqrt(%d)/",inside); printf("%d\n",q4);
        }
        else{
            spe(split(delta,0)*ud,(2*a),inside);
        }
    }
    return 0;
}
