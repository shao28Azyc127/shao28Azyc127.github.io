#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],b[100005],cnt=0,max,x,sum,c;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)scanf("%d",&b[i]);
    for(int i=1;i<=n;i++){
        sum=0;
        x=n-i;
        max=b[i];
        for(int j=i+1;j<=n;j++)if(b[j]<max){
            x=j-i;
            max=b[j];
            j=n;
        }
        for(int j=i;j<=x;j++)sum+=a[j];
        cnt+=b[i]*((sum-c)/m);
        if(sum%m>=0)cnt+=b[i];
        i+=x-1;
        c=m*cnt-sum;
    }
    printf("%d",cnt);
    return 0;
}