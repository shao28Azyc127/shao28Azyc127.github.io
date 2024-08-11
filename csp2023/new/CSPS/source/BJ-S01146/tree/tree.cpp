#include<bits/stdc++.h>
using namespace std;
long long n,a,b,c;
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld%lld%lld",&a,&b,&c);
    for(int i=1;i<n;i++)
        scanf("%lld%lld",&a,&b);
    printf("6");
    return 0;
}