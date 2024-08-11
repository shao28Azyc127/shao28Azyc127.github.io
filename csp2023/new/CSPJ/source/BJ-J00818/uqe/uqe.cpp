#include<bits/stdc++.h>
using namespace std;
int T,M;
int a,b,c;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    scanf("%d%d",&T,&M);
    for(int t=1;t<=T;t++){
        scanf("%d%d%d",&a,&b,&c);
        int delta=b*b-4*a*c;
        if(delta<0)printf("NO\n");
        else if(delta==0){
            if(b/2*2==b)printf("%d\n",-1*b/2);
            else {
                printf("%d/2\n",-1*b);
            }

        }
        else if(delta>0){
            int f=0;
            if(b/2*2==b)f=1;
            else if(b/2*2!=b) printf("-%d/2+",-1*b);
            if(sqrt(delta)*sqrt(delta)==delta){
                if((int)sqrt(delta)%2==0){
                    if(f==1)printf("%d\n",sqrt(delta)/2+-1*b/2);
                    else if(f==0) printf("%d\n",sqrt(delta)/2);
                }
                else if((int)sqrt(delta)%2!=0)printf("%d/2\n",sqrt(delta));
            }
            else{
                int xishu=1;
                for(int k=1;k<delta;k++){
                    if(delta%(k*k)==0){
                        delta/=k*k;
                        xishu*=k*k;
                        //cout<<"k="<<k<<endl;
                    }
                }
                if(xishu>1){
                    if(xishu%2==0)printf("%d*sqrt(%d)\n",xishu/2,delta);
                    else if(xishu%2==1) printf("%d*sqrt(%d)/2\n",xishu,delta);
                }
                else if(xishu==1) printf("sqrt(%d)/2\n",delta);
            }
        }
    }
    return 0;
}

