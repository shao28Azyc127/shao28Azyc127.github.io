#include <bits/stdc++.h>
using namespace std;
#define M 1000005
long long int a[M],p[M];
long long int ans,sum,cha,s,n,m;
long long int celi(long long int n,long long int m){
    if(n%m==0)return n/m;
    else return n/m+1;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(int i=1;i<n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)scanf("%d",&p[i]);
    ans+=celi(a[1],m)*p[1];
    cha=celi(a[1],m)*m-a[1];
    sum=p[1];
    for(int i=2;i<n;i++){
        sum=min(sum,p[i]);
        ans+=sum*celi(a[i]-cha,m);
        s=celi(a[i]-cha,m)*m-a[i]+cha;
        cha=s;
    }
    printf("%d",ans);
    return 0;
}
