#include<bits/stdc++.h>
using namespace std;
int n,d,minn=1e8+7,now,ans;
const int M=1e5+3;
int a[M],v[M];
void gou(int minn,int i){
    while(now<v[i]){
        now+=d;
        ans+=minn;
    }
    return;
}
void work(int now,int i){
    if(i==n) return;
    minn=min(minn,a[i]);
    gou(minn,i);
    now-=v[i];
    return;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<=n-1;i++){
        cin>>v[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        work(now,i);
    }
    cout<<ans;
    return 0;
}
