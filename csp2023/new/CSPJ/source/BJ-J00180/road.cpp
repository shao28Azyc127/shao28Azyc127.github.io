#include<bits/stdc++.h>
using namespace std;
int n,d,ans,cnt,v[100010],a[100010][2];
double last;
long long sum[100010];
int main(){
freopen("road.in","r",stdin);
freopen("road.out","w",stdout);
    scanf("%d%d",&n,&d);
    for(int i=1;i<n;i++){
        scanf("%d",&v[i]);
    }
    for(int i=1,i<n;i++){
        sum[i]=sum[i-1]+v[i];
    }
    scanf("%d",&a[++cnt]);
    a[cnt][1]=1;
    for(int i=2;i<=n;i++){
        int dp;
        scanf("%d",&dp);
        if(dp<a[cnt][0])a[++cnt][0]=dp,a[cnt][1]=i;
    }
    for(int i=1;i<cnt;i++){
        if(i==cnt-1){
            ans+=a[i][0]*ceil((double)((sum[n-1]-sum[a[i][1]])/d)-last);
        }
        else{
            ans+=a[i][0]*ceil((double)((sum[a[i+1][1]]-sum[a[i][1]])/d)-last);
            last=ceil((sum[a[i+1][1]]-sum[a[i][1]])/d)+last-(double)((sum[a[i+1][1]]-sum[a[i][1]])/d);
        }
    }
    printf("%d",ans);
    return 0;
}