#include <iostream>
#include <cmath>
using namespace std;
int n,v[10010],a[10010],dp[10010];
double ans,now,sumv,d;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d %lf",&n,&d);
    for(int i=1;i<n;i++)scanf("%d",v+i);
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    for(int i=1,j;i<n;i++){
        if(a[i]>a[i+1]){
            ans+=(int)((ceil(v[i]/d)*d-now)/d)*a[i];
            now=ceil(v[i]/d)*d+now-v[i];
        }
        else{
            for(j=i;j<=n&&a[i]<=a[j];j++)
                if(a[i]<=a[j])sumv+=v[j];
            ans+=ceil((ceil(sumv/d)*d-now)/d)*a[i];
            now=(ceil(sumv/d))*d+now-sumv;
            i=j-1;
        }
    }
    printf("%lld",(long long)ans);
    return 0;
}
