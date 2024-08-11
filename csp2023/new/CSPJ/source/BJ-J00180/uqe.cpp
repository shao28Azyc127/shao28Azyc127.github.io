#include<bits/stdc++.h>
using namespace std;
int p[1010],n,m,p1[1010],cnt,x,y;
void es(){
    for(int i=1;i<=1010;i++)
        if(p[i]==0){p1[++cnt]=i;for(int j=1;j*i<=1010;j++)p[i*j]=1;}
}
void fix(int a,int b){
for(int i=1;i<=cnt;i++){
    if(a%p1[i]==0&&b%p1[i]==0){
        a/=p1[i],b/=p1[i],i--;
    }
}
x=a,y=b;
}
int fix1(int a){
int sum=1;
    for(int i=1;i<=cnt;i++){
        if(a/(p1[i]*p1[i])*(p1[i]*p1[i])==a)sum*=p1[i],i--;
    }
    return sum;
}
int main(){
freopen("uqe.in","r",stdin);
freopen("uqe.out","w",stdout);
    scanf("%d%d",&n,&m);
    es();
    while(n--){
        printf("%d",ans);
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        long long data=b*b-4*a*c;
        if(data<0)printf("NO/n");
        else {
            fix(abs(-b),abs(2a));
            if(-b*2*a<0){
                if(y==1)printf("-%d",x);
                else ptinf("-%d/%d",x,y);
            }else{
                if(y==1)printf("%d",x);
                else ptinf("%d/%d",x,y);
            }
            if(data==0)continue;
            printf("+");
            int u=fix1(data);
            int v=data/(u*u);
            fix(u,abs(2*a));
            u=x,2*a=y;
            if(v==1){
                if(u==1&&2*a==1){
                    printf("1");
                }else if(u==1){
                    printf("1/%d",2*a)
                }else if(2*a==1){
                    printf("%d",u);
                }else{
                    printf("%d/%d",u,2*a);
                }
            }else{
                if(u==1&&2*a==1){
                    printf("sqrt(%d)",v);
                }else if(u==1){
                    printf("sqrt(%d)/%d",v,2*a)
                }else if(2*a==1){
                    printf("%d*sqrt(%d)",u,v);
                }else{
                    printf("%d*sqrt(%d)/%d",u,v,2*a);
                }
            }
        }
    }
    return 0;
}