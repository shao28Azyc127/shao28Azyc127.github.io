#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}
void prt(int fz,int fm){
    if(fz*fm<0){
        printf("-");
        fz=abs(fz);
        fm=abs(fm);
    }
    int gy=gcd(fz,fm);
    fz/=gy;
    fm/=gy;
    printf("%d",fz);
    if(fm!=1){
        printf("/%d",fm);
    }
}
void prtr(int dlt,int fm){
   // cout<<"\nqwq"<<" "<<dlt<<" "<<fm<<endl;
    int fz=1;
    for(int i=2;i*i<=dlt;i++){
        while(dlt%(i*i)==0){
            fz*=i;
            dlt/=(i*i);
        }
    }
    //cout<<"\nqwq"<<" "<<fz<<" "<<dlt<<" "<<fm<<endl;
    if(fz!=1){
        int gy=gcd(fz,fm);
        fz/=gy;
        fm/=gy;
        if(fz*fm<0){
            fz=abs(fz);
            fm=abs(fm);
        }
        if(fz!=1){
            printf("%d*",fz);
        }

    }
    if(fz*fm<0){
        fz=abs(fz);
        fm=abs(fm);
    }
    printf("sqrt(%d)",dlt);
    if(fm!=1){
        printf("/%d",fm);
    }
}
void sol(int a,int b,int c){
    int dlt=b*b-4*a*c;
    if(dlt<0){
        printf("NO");
        return;
    }else{
        if(dlt==0){
            prt(-b,2*a);
            return;
        }
        int s=sqrt(dlt);
        if(s*s==dlt){
            int fm=2*a,fz;
            if(2*a>0){
                fz=-b+s;
            }else{
                fz=-b-s;
            }
            prt(fz,fm);
        }else{
            if(b!=0){
                prt(-b,2*a);
                printf("+");
            }
            prtr(dlt,2*a);
        }
    }
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int T,M;
    scanf("%d%d",&T,&M);
    while(T--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        sol(a,b,c);
        printf("\n");
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
