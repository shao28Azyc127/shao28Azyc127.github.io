#include<bits/stdc++.h>
using namespace std;
bool pfm(int a){
    int s=sqrt(a);
    return s*s==a;
}
int z(int a,int b){
    return b==0?a:z(b,a%b);
}
int sf(int a){
    int an=1;
    for(int i=2;i<a;i++){
        while(a%(i*i)==0){
            a=a/(i*i);
            an*=i;
        }
    }
    return an;
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int a,m;
    scanf("%d%d",&a,&m);
    for(int i=1;i<=a;i++){
        int b,c,d;
        scanf("%d%d%d",&b,&c,&d);
        int f=c*c-4*b*d;
        int fm,fz;
        if(f<0){
            printf("NO\n");
            continue;
        }
        if(pfm(f)){
            fm=sqrt(f)-c;
            fz=2*b;
            int c=z(fm,fz);
            fm/=c;
            fz/=c;
            if(fz<0){
                fz=0-fz;
                fm=0-fm;
            }
            if(fm!=0){
                if(fz!=1)printf("%d/%d\n",fm/fz);
                else printf("%d\n",fm);
            }
        }else{
            fm=0-c;
            fz=2*b;
            int c=z(fm,fz);
            fm/=c;
            fz/=c;
            if(fz<0){
                fz=0-fz;
                fm=0-fm;
            }
            if(fm!=0){
                if(fz!=1)printf("%d/%d+",fm/fz);
                else printf("%d+",fm);
            }
            int st=sf(f);
            f/=st;
            int bf=2*b;
            int cm=z(st,bf);

            bf/=cm;
            st/=cm;
            printf("%d*sqrt(%d)/%d\n",st,f,bf);
        }
    }
}
