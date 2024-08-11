#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define rep0(i,n) for(int i=0;i<n;i++)
const int N=1e5+5;
int n,d;
struct node{
    int price,id;
}a[N];
long long v,s[N];
bool cmp(node a,node b){
    if(a.price!=b.price) return a.price>b.price;
    return a.id>b.id;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d",&n,&d);
    rep(i,n-1){
        scanf("%d",&v);
        s[i]=s[i-1]+v;
    }
    rep(i,n-1){
        scanf("%d",&a[i].price);
        a[i].id=i;
    }
    sort(a+1,a+n,cmp);
    int pos=1,k;
    rep(i,n){
        if(a[i].id==1) {
            k=i;
            break;
        }
    }
    long long ans=0;
    while(pos<n){
        int next=0;
        for(int i=k;i<=n;i++){
            if(a[i].price<a[k].price && a[i].id>a[k].id){
                next=i;
                break;
            }
        }
        if(next==0){
            double dis=s[n-1]-s[pos-1];
            ans+=a[k].price*ceil(double(dis/d));
            break;
        }

        else{
            double dis=s[a[next].id-1]-s[pos-1];
            ans+=a[k].price*ceil(double(dis/d));

            pos=a[next].id;
            k=next;
        }

    }
    cout<<ans<<endl;
    return 0;
    }

