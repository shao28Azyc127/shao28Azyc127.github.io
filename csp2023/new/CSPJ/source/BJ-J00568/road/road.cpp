#include <bits/stdc++.h>
using namespace std;

int n,d;
int l=0;
long long int ans=0;

void addgas(int x,int y){
    while(x>0){
        if(x<d) l=d-x;
        ans+=y;
        x-=d;
    }
}

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int v[100005],a[100005],sta=1,allv;
    scanf("%d%d",&n,&d);
    for(int i=1;i<n;i++){
        scanf("%d",&v[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=2;i<=n;i++){
        if(a[i]<a[sta]){
            for(int j=sta;j<i;j++){
                allv+=v[j];
            }
            addgas(allv-l,a[sta]);
            sta=i,allv=0;
        }
    }
    printf("%lld",ans);
    return 0;
}
