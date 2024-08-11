#include<bits/stdc++.h>
using namespace std;
inline int abs(int a){
    return (a>=0)?(a):(a*-1);
}
inline int gcd(int a,int b){
    if(a==0||b==0) return 1;
    return (a%b)?(gcd(b,a%b)):(b);
}
inline int essq(int a){
    int k=a,ans=1;
    for(int i=2;i*i<=k;i++){ while(k%(i*i)==0) k/=(i*i),ans*=i;}
    return ans;
}
int T,a,b,c,m;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    scanf("%d%d",&T,&m);
    while(T--){
        scanf("%d%d%d",&a,&b,&c);
        int dt=b*b-4*a*c;
        if(dt<0){
            printf("%s\n","NO");
            continue;
        }
        int k=essq(dt);
        if(k*k==dt){
            int up=k-b;
            int down=2*a;
            if(down<0) up=-k-b;
            int g;g=gcd(abs(up),abs(down));
            up/=g;down/=g;
            if(down<0){up*=-1,down*=-1;}
            if(up==0) printf("%d",0);
            else if(down==1) printf("%d",up);
            else printf("%d/%d",up,down);
        }else{
            int up,down,g;
            bool f=0;
            up=b*-1;down=2*a;
            g=gcd(abs(up),abs(down));
            up/=g;down/=g;
            if(down<0){up*=-1,down*=-1;}
            if(up==0) ;
            else if(down==1) printf("%d",up),f=1;
            else printf("%d/%d",up,down),f=1;
            int lup=up;
            up=k;down=2*a;
            if(down<0) up*=-1;
            g=gcd(abs(up),abs(down));
            up/=g;down/=g;
            //bool f=0;
            if(up!=0&&dt!=0){
                if(down<0){up*=-1,down*=-1;}
                if(lup!=0) printf("+");
                if(up!=1) printf("%d*",up),f=1;
                if(dt!=0) printf("sqrt(%d)",dt/k/k),f=1;
                if(down!=1&&(up!=1||dt!=0)) printf("/%d",down),f=1;
            }if(!f) printf("0");
        }printf("\n");
        //cout<<k<<' '<<dt<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
