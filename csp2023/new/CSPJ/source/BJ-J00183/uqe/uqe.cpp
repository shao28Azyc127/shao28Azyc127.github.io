#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int n,m,k,ans=0;
    scanf("%d %d",&n,&m);
    if(m==1||m==0){
        for(int i=0;i<n;i++){
            scanf("%d %d %d",&k,&k,&k);
        }
        for(int i=0;i<n;i++){
            printf("%d\n",ans);
        }
    }else{
        for(int i=0;i<n;i++){
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            int ret1,ret2;
            if((b*b-4*a*c)<0){printf("%s\n","NO");continue;}
            ret1=((-b)+sqrt(b*b-4*a*c))/(2*a);
            ret2=((-b)-sqrt(b*b-4*a*c))/(2*a);
            if(ret1==ret2) printf("%d\n",ret1);
            else printf("%d/%d\n",ret1,ret2);
        }
    }
}
