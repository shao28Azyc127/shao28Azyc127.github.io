#include<bits/stdc++.h>
using namespace std;
bool prime[1000001];
vector<int>zhi;
int t,m,a,b,c;
void as(){
    prime[0]=prime[1]=1;
    for(int i=2;i<=10000;i++){
        if(prime[i]==1)continue;
        for(int j=i*2;j<=10000;j+=i)prime[j]=1;
    }
}
int gcd(int X,int Y){
    if(Y==0)return X;
    return gcd(Y,X%Y);
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    scanf("%d%d",&t,&m);
    as();
    for(int i=1;i<=10000;i++){
        if(prime[i]==0){
            zhi.push_back(i);
        }
    }
    while(t--){
        scanf("%d%d%d",&a,&b,&c);
        int dt=b*b-4*a*c;
        if(dt<0){
            printf("NO\n");
            continue;
        }int x=0,y=0;
        int s=sqrt(dt);
        if(s*s==dt)x=s,y=1;
        else{
            int lzb=zhi.size();
            int dt2=1,dt3=dt;
            for(int i=0;i<lzb;i++){
                int lzx=zhi[i]*zhi[i];
                if(lzx>dt3)break;
                while(dt3%lzx==0){
                    dt3/=lzx;
                    dt2*=zhi[i];
                }
            }
            x=dt2,y=dt3;
        }
        int OT1=-b,OT2=2*a,OT3=2*a;
        int L1=gcd(OT1,OT2);
        OT1/=L1,OT2/=L1;
        int L2=gcd(x,OT3);
        x/=L2,OT3/=L2;
        //cout<<OT1<<" "<<OT2<<" "<<OT3<<" "<<x<<" "<<y<<endl;
        if(a!=0&&b!=0){
            if(a>0){
            if(OT2==1&&y==1&&OT3==1)printf("%d\n",OT1+x);
            else if(x+OT3*OT1!=0&&OT2==1&&y==1&&OT3!=1){
                    if(OT3<0)printf("%d/%d\n",-x-OT3*OT1,-OT3);
                    else printf("%d/%d\n",x+OT3*OT1,OT3);
            }
            else if(OT1!=0&&OT2==1&&y!=1&&OT3==1)printf("%d+%d*sqrt(%d)\n",OT1,x,y);
            else if(OT1!=0&&x!=0&&y!=1&&OT3!=0&&OT2==1&&y!=1&&OT3!=1&&x!=1)printf("%d+%d*sqrt(%d)/%d\n",OT1,x,y,OT3);
            else if(OT1!=0&&y!=0&&OT3!=0&&OT2==1&&y!=1&&OT3!=0&&x==1)printf("%d+sqrt(%d)/%d\n",OT1,y,OT3);
            else if(OT1+x*OT2!=0&&OT2!=0&&OT2!=1&&y==1&&OT3==1){
                    if(OT2<0)printf("%d/%d\n",-OT1-x*OT2,-OT2);
                    else printf("%d/%d\n",OT1+x*OT2,OT2);
            }
            else if(OT2!=1&&y==1&&OT3!=1){
                    int PP=OT1*OT3+OT2*x;
                    int PP2=OT2*OT3;
                    int MMM=gcd(PP,PP2);
                    PP/=MMM;
                    PP2/=MMM;

                    if(PP!=0&&PP2!=0){
                        if(PP2!=1){
                                if(PP2<0)printf("%d/%d\n",-PP,-PP2);
                                else printf("%d/%d\n",PP,PP2);
                        }
                        else printf("%d\n",PP);
                    }
            }
            else if(OT1!=0&&x!=0&&y!=1&&OT2!=1&&y!=1&&OT3==1){
                    if(OT2<0) printf("%d/%d+%d*sqrt(%d)\n",-OT1,-OT2,x,y);
                    else printf("%d/%d+%d*sqrt(%d)\n",OT1,OT2,x,y);
            }
            else if(OT1!=0&&x!=0&&y!=1&&OT2!=1&&y!=1&&OT3!=1&&x!=1){
                    if(OT2<0)printf("%d/%d+%d*sqrt(%d)/%d\n",-OT1,-OT2,x,y,OT3);
                    else printf("%d/%d+%d*sqrt(%d)/%d\n",OT1,OT2,x,y,OT3);
            }
            else if(OT1!=0&&OT2!=1&&y!=1&&OT3!=0&&x==1){
                    if(OT2<0)printf("%d/%d+sqrt(%d)/%d\n",-OT1,-OT2,y,OT3);
                    else printf("%d/%d+sqrt(%d)/%d\n",OT1,OT2,y,OT3);
            }
        }else{
            if(OT2==1&&y==1&&OT3==1)printf("%d\n",OT1-x);
            else if(x+OT3*OT1!=0&&OT2==1&&y==1&&OT3!=1){
                    if(OT3<0)printf("%d/%d\n",x-OT3*OT1,-OT3);
                    else printf("%d/%d\n",-x+OT3*OT1,OT3);
            }
            else if(OT1!=0&&OT2==1&&y!=1&&OT3==1)printf("%d-%d*sqrt(%d)\n",OT1,-x,y);
            else if(OT1!=0&&x!=0&&y!=1&&OT3!=0&&OT2==1&&y!=1&&OT3!=1&&x!=1)printf("%d-%d*sqrt(%d)/%d\n",OT1,x,y,-OT3);
            else if(OT1!=0&&y!=0&&OT3!=0&&OT2==1&&y!=1&&OT3!=0&&x==1)printf("%d-sqrt(%d)/%d\n",OT1,y,-OT3);
            else if(OT1+x*OT2!=0&&OT2!=0&&OT2!=1&&y==1&&OT3==1){
                    if(OT2<0)printf("%d/%d\n",-OT1+x*OT2,-OT2);
                    else printf("%d/%d\n",OT1-x*OT2,OT2);
            }
            else if(OT2!=1&&y==1&&OT3!=1){
                    int PP=OT1*OT3-OT2*x;
                    int PP2=OT2*OT3;
                    int MMM=gcd(PP,PP2);
                    PP/=MMM,PP2/=MMM;
                    if(PP!=0&&PP2!=0){
                        if(PP2!=1){
                            if(PP2<0)printf("%d/%d\n",-PP,-PP2);
                            else printf("%d/%d\n",PP,PP2);
                        }
                        else printf("%d\n",PP);
                    }
            }
            else if(OT1!=0&&x!=0&&y!=1&&OT2!=1&&y!=1&&OT3==1){
                    if(OT2<0)printf("%d/%d-%d*sqrt(%d)\n",-OT1,-OT2,-x,y);
                    else printf("%d/%d-%d*sqrt(%d)\n",OT1,OT2,-x,y);
            }
            else if(OT1!=0&&x!=0&&y!=1&&OT2!=1&&y!=1&&OT3!=1&&x!=1){
                    if(OT2<0) printf("%d/%d-%d*sqrt(%d)/%d\n",-OT1,-OT2,x,y,-OT3);
                    else printf("%d/%d-%d*sqrt(%d)/%d\n",OT1,OT2,x,y,-OT3);
            }
            else if(OT1!=0&&OT2!=1&&y!=1&&OT3!=0&&x==1){
                    if(OT2<0)printf("%d/%d-sqrt(%d)/%d\n",-OT1,-OT2,y,-OT3);
                    else printf("%d/%d-sqrt(%d)/%d\n",OT1,OT2,y,-OT3);
            }
        }
        }else if(b==0){
            int lzb=zhi.size();
            int KK=gcd(a,c);
            a/=KK,c/=KK;
            int dt2=1,dt3=-c;
            for(int i=0;i<lzb;i++){
                int lzx=zhi[i]*zhi[i];
                if(lzx>dt3)break;
                while(dt3%lzx==0){
                    dt3/=lzx;
                    dt2*=zhi[i];
                }
            }
            if(a==1){

                if(int(sqrt(dt3))*int(sqrt(dt3))!=dt3)cout<<dt2<<"*sqrt("<<dt3<<")"<<endl;
                else cout<<int(dt2*sqrt(dt3))<<endl;
            }
            else{
                if(a<0)cout<<-dt2<<"/"<<-a<<"*sqrt("<<dt3<<")"<<endl;
                else cout<<dt2<<"/"<<a<<"*sqrt("<<dt3<<")"<<endl;
            }
        }
    }
    return 0;
}
