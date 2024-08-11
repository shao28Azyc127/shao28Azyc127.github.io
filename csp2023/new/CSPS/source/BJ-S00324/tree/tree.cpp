#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
int n,d[100005],u,v;
long long a,b,c,ans,x=0;
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld%lld%lld",&a,&b,&c);
        if(i==1){
            for(int j=1;j<=1e9&&x<a;j++){
                x+=(b+j*c)>1?b+j*c:1;
                ans=j;
            }
        }
    }
    for(int i=1;i<=n-1;i++){
        scanf("%d%d",&u,&v);
    }
    printf("%d",ans+1);
    return 0;
}
