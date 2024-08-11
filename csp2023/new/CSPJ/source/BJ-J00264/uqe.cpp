#include <bits/stdc++.h>
using namespace std;

int T,m,pri[1005],head=1;

void init() {
    pri[head]=2;
    for(int i=3;i<=1000;i++) {
        bool flag=true;
        for(int j=1;j<=head;j++) {
            if(i%pri[j]==0) {
                flag=false;
                break;
            }
        }
        if(flag) pri[++head]=i;
    }
}

int getgcd(int x,int y) {
    if(y==0) return x;
    return getgcd(y,x%y);
}

void printQ(int p,int q) {
    if(p==0) {
        printf("0");
        return ;
    }
    if(p%q==0) {
        printf("%d",p/q);
        return ;
    }
    int gcd=getgcd(p,q);
    p/=gcd; q/=gcd;
    if(q<0) p=-p,q=-q;
    printf("%d/%d",p,q);
}

void printS(int x,int a) {
    int times=1;
    for(int i=1;i<=head && pri[i]*pri[i]<=x;i++) {
        while(x%(pri[i]*pri[i])==0) {
            times*=pri[i];
            x/=pri[i]*pri[i];
        }
    }
    double q2=(times*1.0)/(a*1.0),q3=1/q2;
    if(q2==1) {
        printf("sqrt(%d)",x);
        return ;
    }
    else if(q2==floor(q2)) {
        printf("%d*sqrt(%d)",(int)q2,x);
        return ;
    }
    else if(q3==floor(q3)) {
        printf("sqrt(%d)/%d",x,(int)q3);
        return ;
    } else {
        int gcd=getgcd(times,a);
        if(times<0 && a<0) gcd=-gcd;
        times/=gcd,a/=gcd;
        printf("%d*sqrt(%d)/%d",times,x,a);
        return ;
    }
}

int main() {
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    init();
    cin>>T>>m;
    while(T--) {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        double derta=b*b-4*a*c;
        //cout<<endl<<derta<<endl;
        if(derta<0) {
            printf("NO\n");
            continue;
        }
        if(a>0) {
            if(derta==0) {
                printQ(-b,2*a);
                printf("\n");
            } else {
                if((int)sqrt(derta)*(int)sqrt(derta)==derta) {
                    int cur=sqrt(derta);
                    printQ(-b+cur,2*a);
                    printf("\n");
                    continue;
                }
                if(b!=0) {
                    printQ(-b,2*a);
                    printf("+");
                }
                printS(derta,2*a);
                printf("\n");
            }
        } else {
            if(derta==0) {
                printQ(-b,2*a);
                printf("\n");
            } else {
                if((int)sqrt(derta)*(int)sqrt(derta)==derta) {
                    int cur=sqrt(derta);
                    printQ(-b-cur,2*a);
                    printf("\n");
                    continue;
                }
                if(b!=0) {
                    printQ(-b,2*a);
                    printf("+");
                }
                printS(derta,-2*a);
                printf("\n");
            }
        }
    }
    return 0;
}
//meow