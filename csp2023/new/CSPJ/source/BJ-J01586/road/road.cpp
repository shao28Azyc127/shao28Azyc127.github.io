#include<stdio.h>
using namespace std;
long long n,d,u[10001],a[10001],sum,j;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld %lld",&n,&d);
    for(long long i=1;i<n;i++){
        scanf("%lld",&u[i]);
    }
     for(long long i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    long long S=0;
    for(long long i=1;i<=n;i=j){
        for( j=i+1;j<=n;j++){
            if(a[j]<a[i]){
                break;
            }
        }
        long long s=0;
        for(long long k=i;k<j;k++){
            s+=u[k];
        }
        s-=S;
        long long v=s/d;
        if(s%d!=0) v++;
        sum+=v*a[i];
        S+=v*d;
        for(long long k=i;k<j;k++){
            S-=u[k];
        }

    }
    printf("%lld",sum);
    fclose(stdin);
    fclose(stdout);
    return 0;
}