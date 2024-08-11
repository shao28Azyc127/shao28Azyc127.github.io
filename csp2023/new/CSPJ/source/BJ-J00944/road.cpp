#include<bits/stdc++.h>
#define N 100010
int v[N],a[N];
long long ans;
using namespace std;
int main(){
    int n,d;
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d",&n,&d);
    for(int i=1;i<=n-1;i++) scanf("%d",&v[i]);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    int now=1;
    int yx=0;
    while(now<n){
        int m;
        int num=0,i;
        for(i=now+1;i<=n;i++){
            num+=v[i-1];
            if(a[i]<=a[now]){
                break;
            }
        }
        m=ceil((num-yx)*1.0/d);
        //yx+=m*d-v[now-1]*d;
        yx+=m*d-num;
        ans+=m*a[now];
        now=i;
        //cout<<now<<" "<<num<<" "<<yx<<""<<ceil((num-yx)*1.0/d)<<" "<<m<<" "<<ans<<endl;
    }
    cout<<ans;
    return 0;
}
