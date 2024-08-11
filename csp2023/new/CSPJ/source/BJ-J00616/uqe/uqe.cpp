#include<bits/stdc++.h>
using namespace std;
int T,M;
int a,b,c;
int GYS(int x,int y){
    int MO=1;
    int tmp=min(max(x,-1*x),max(y,-1*y));
    for(int i=1;i<=tmp;i++){
        if(x%i==0&&y%i==0) MO=i;
    }
    return MO;
}
void OT1(int lup,int ldown){
    if(lup==0){
            cout<<0;
        return;
    }
    int cy=GYS(lup,ldown);
    lup/=cy;ldown/=cy;
    if(ldown<0){
        lup*=-1;ldown*=-1;
    }
    if(ldown==1)printf("%d",lup);
    else printf("%d/%d",lup,ldown);
    return;
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>T>>M;
    while(T--){
        cin>>a>>b>>c;
        int drta=b*b-4*a*c;
        if(drta<0){
            cout<<"NO"<<endl;
            continue;
        }
        int lup=-1*b,ldown=2*a;
        if(int(sqrt(drta))*int(sqrt(drta))==drta){
            lup+=max(sqrt(drta),-1*sqrt(drta));OT1(lup,ldown);
            printf("\n");continue;
        }else{
            int rup=1,rdown=2*a;
            for(int i=sqrt(drta);i>1;i--){
                if(drta%(i*i)==0){
                    drta/=(i*i);
                    rup*=i;
                }
            }
            if(lup!=0) OT1(lup,ldown);
            if(lup!=0) printf("+");
            int cy=GYS(rup,rdown);
            rup/=cy;rdown/=cy;
            if(rdown<0){
                rup*=-1;rdown*=-1;
            }
            rup=max(rup,-1*rup);
            if(rup!=1) printf("%d*",rup);
            printf("sqrt(%d)",drta);
            if(rdown!=1) printf("/%d",rdown);
            printf("\n");
        }
    }
    return 0;
}
