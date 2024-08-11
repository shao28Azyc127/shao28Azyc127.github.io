#include<bits/stdc++.h>
using namespace std;
long long n,ans,cnt;
long long p,l,k;
struct d{
    long long a,b,c;
};
d m[100005];
struct r{
    int x,y;
};
r v[100005];
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&m[i].a,&m[i].b,&m[i].c);
    }
    for(int i=1;i<n;i++){
        scanf("%lld%lld",&v[i].x,&v[i].y);
    }
    for(long long i=1;i<=n;i++){
        p=n-i+1;
        l=0,k=0;
        while(k<m[i].a){
            l=max((long long )1,m[i].b+p*m[i].c);
            k+=l;
            p++;
        }
        ans=max(ans,i+p);
    }
    printf("lld",ans);
    return 0;
}
