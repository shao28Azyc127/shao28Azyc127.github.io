#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    scanf("%d%d",&n,&d);
    int l[n],m[n];
    long long res=0;
    for (int i=0;i<n-1;i++)
    {
        scanf("%d",&l[i]);
        res+=l[i];
    }
    for (int i=0;i<n;i++)
    {
        scanf("%d",&m[i]);
    }
    long long ans=ceil(res*1.0/d)*m[0];
    printf("%lld",ans);
    return 0;
}
