#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int T,M;
bool zheng(double a){
    int b=a;
    return !(a-b);
}
void youli(double a){
    for(int i=1;i<=M;i++){
        if(zheng(a*i)){
            printf("%d/%d",int(a*i),i);
            return;
        }
    }
}
int der(int a){
    int ans=1;
    for(int i=2;i<=a&&a!=1;i++){
        while(!(a%(i*i))){
            ans*=i;
            a/=i*i;
        }
    }
    return ans;
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    scanf("%d%d",&T,&M);
    for(int i=1;i<=T;i++){
        cout<<i;
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        double derta=(double)b*b-4*a*c,x;
        if(derta<0){
            printf("NO\n");
            continue;
        }
        x=max((double)(sqrt(derta)-double(b))/double(2*a),(double)(-1*sqrt(derta)-double(b))/double(2*a));
        if(zheng(x))printf("%.0lf\n",x);
        else{
            if(zheng(sqrt(derta))){
                youli(x);
                printf("\n");
            }
            else{
                double q1=(double)(-1*b)/(double)(2*a),q2=abs(double(1/(double)(2*a)));
                if(q1==0);
                else if(zheng(q1))printf("%.0lf+",q1);
                else{
                    youli(q1);
                    printf("+");
                }
                int k=der(derta);
                q2*=k;
                derta/=k*k;
                if(q2==1)printf("sqrt(%.0lf)\n",derta);
                else{
                    if(zheng(q2))printf("%.0lf*sqrt(%.0lf)\n",q2,derta);
                    else if(zheng(1/q2))printf("sqrt(%.0lf)/%.0f\n",derta,1/q2);
                    else{
                        for(double j=1;j<=M;j++){
                            double t=q2*j;
                            if(zheng(t)){
                                printf("%d*sqrt(%.0lf)/%d\n",int(q2*j),derta,j);
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
