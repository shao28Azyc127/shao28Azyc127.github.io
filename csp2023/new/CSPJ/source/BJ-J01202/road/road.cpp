#include <bits/stdc++.h>
using namespace std;
int n,d,dis[100005],c[100005],minn,q[100005],k,s,ans,s1,tmp;
struct p{
    int id,cost;
}a[100005];
bool cmp1(p x,p y){
    if(x.cost==y.cost)return x.id<y.id;
    return x.cost<y.cost;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<=n-1;i++)cin>>dis[i];
    for(int i=1;i<=n;i++){
            cin>>c[i];
            a[i].cost=c[i];
            a[i].id=i;
    }
    k=1;
    q[0]=n;
    sort(a,a+n,cmp1);
    for(int i=1;i<=n-1;i++){
            if(a[i].id<q[k-1]){
                    q[k]=a[i].id;
                    if(a[i].id==1)break;
                    k++;
            }
    }
    for(int i=k;i>=1;i--){
            tmp=0;
            for(int j=q[i];j<q[i-1];j++)tmp+=dis[j];
            s1=(tmp-s)%d;
            ans+=((tmp-s)/d+1)*c[q[i]];
            if(!s1)ans-=c[q[i]];
            s=s1;
    }
    cout<<ans;
    return 0;
}
