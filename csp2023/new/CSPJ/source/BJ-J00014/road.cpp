#include<bits/stdc++.h>
using namespace std;
struct node{
    long long u,a;
}t[100005];
bool cmp(node x,node y){
    return x.a<y.a;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    long long n,d,sum=0,cnt=1,ans=0,asd;
    cin>>n>>d;
    for(int i=2;i<=n;i++){
        scanf("%d",&t[i].u);
        t[i].u+=t[i-1].u;
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&t[i].a);
    }
    while(cnt<n){
        for(int i=cnt;i<n;i++){
            if(t[i].a<t[cnt].a){
                ans+=((t[i].u-t[cnt].u-sum)/d+1)*t[cnt].a;
                asd=sum;
                sum+=((t[i].u-t[cnt].u-sum)/d+1)*d;
                if((t[i].u-t[cnt].u-asd)%d==0)ans-=t[cnt].a,sum-=d;
                sum-=(t[i].u-t[cnt].u);
                cnt=i;
                goto tutu;
            }
        }
        ans+=((t[n].u-t[cnt].u-sum)/d+1)*t[cnt].a;
        asd=sum;
        sum+=((t[n].u-t[cnt].u-sum)/d+1)*d;
        if((t[n].u-t[cnt].u-asd)%d==0)ans-=t[cnt].a,sum-=d;
        sum-=(t[n].u-t[cnt].u);
        cnt=n;
        cout<<ans;
        return 0;
        tutu:;
    }
    cout<<ans;
    return 0;
}
