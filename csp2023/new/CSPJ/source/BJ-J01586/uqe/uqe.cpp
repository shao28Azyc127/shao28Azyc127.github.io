#include<stdio.h>
#include<cmath>
#include<algorithm>
using namespace std;
int t,m,a[1001],b[1001],c[1001];
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    scanf("%d %d",&t,&m);

    for(int i=1;i<=t;i++){
        scanf("%d %d %d",&a[i],&b[i],&c[i]);
        if(b[i]*b[i]-4*a[i]*c[i]<0){
            printf("NO\n");
        }
        else{
            int sum=b[i]*(-1);
            int sum2=sum;
            sum+=sqrt(b[i]*b[i]-4*a[i]*c[i]);
            sum2-=sqrt(b[i]*b[i]-4*a[i]*c[i]);
            sum/=(2*a[i]);
            sum2/=(2*a[i]);
            printf("%d\n",max(sum,sum2));
        }

    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
