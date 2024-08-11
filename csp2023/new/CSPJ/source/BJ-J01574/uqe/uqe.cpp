#include<bits/stdc++.h>
using namespace std;
int a[50007];
int gcd(int a,int b){
    int k;
    while(a!=0){
        k=a;
        a=b%a;
        b=k;
    }
    return b;
}
int kaipingfangzheng(int n){
    int zheng=1,gen=1,i;
    for(i=1;i<=50007;i++){
        a[i]=0;
    }
    for(i=2;i<=n;i++){
        if(n%i==0){
            while(n%i==0){
                n/=i;
                a[i]++;
            }
        }
    }
    for(i=2;i<=50007;i++){
        if(a[i]==0) continue;
        else {
            zheng*=pow(i,a[i]/2);
        }
    }
    return zheng;
}

int kaipingfanggen(int n){
    int zheng=1,gen=1,i;
    for(i=1;i<=50007;i++){
        a[i]=0;
    }
    for(i=2;i<=n;i++){
        if(n%i==0){
            while(n%i==0){
                n/=i;
                a[i]++;
            }
        }
    }
    for(i=2;i<=50007;i++){
        if(a[i]==0) continue;
        else {
            gen*=pow(i,a[i]%2);
        }
    }
    return gen;
}
int main(){
    //freopen("uqe.in","r",stdin);
    //freopen("uqe.out","w",stdout);
    int T,m,i,a,b,c,delta,q1_mu,q1_zi,q1_fu,q2_mu,q2_zi1,q2_zi2,q2_fu;
    scanf("%d%d",&T,&m);
    for(i=1;i<=T;i++){
        scanf("%d%d%d",&a,&b,&c);
        delta=b*b-4*a*c;
        if(delta<0){
            printf("No");

        }
        if(delta>=0){
            q1_mu=abs(2*a/gcd(2*a,b));
            q1_zi=abs(b/gcd(2*a,b));
            q1_fu=-a*b/abs(a*b);
            q2_mu=2*a/gcd(2*a,kaipingfangzheng(delta));
            q2_zi1=abs(kaipingfangzheng(delta)/gcd(2*a,kaipingfangzheng(delta)));
            q2_zi2=kaipingfanggen(delta);
            q2_fu=a/abs(a);

            if(q1_mu==1){
                if(q1_fu==1) printf("%d",q1_zi);
                else printf("-%d",q1_zi);
            }
            else{
                if(q1_fu==1) printf("%d/%d",q1_zi,q1_mu);
                else printf("-%d/%d",q1_zi,q1_mu);
            }
            if(q2_mu==1){
                if(q2_fu==1) printf("+%d*sqrt(%d)",q2_zi1,q2_zi2);
                else printf("-%d*sqrt(%d)",q2_zi1,q2_zi2);
            }
            else{
                if(q2_fu==1) printf("%d/%d*sqrt(%d)",q2_mu,q2_zi1,q2_zi2);
                else printf("-%d/%d*sqrt(%d)",q2_mu,q2_zi1,q2_zi2);
            }
            printf("\n");
        }

    }





}
