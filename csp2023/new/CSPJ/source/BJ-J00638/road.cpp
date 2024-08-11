#include<bits/stdc++.h>
using namespace std;
int flag[100010],s=1,ans;
int n,d,now_o,now_r,l,r,v[100010],a[100010];
int The_most_cheap(int l,int r){
    int s=l;
    for(int i=l=1;i<r;i++){
        if(a[i]<a[s])s=i;
    }
}
int The_roads(int l,int r){
    int s;
    for(int i=l;i<r;i++)s+=v[i];
    return s;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    r=n;l=1;
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    while(l<=r&&r>1){
        flag[s]=The_most_cheap(l,r);
        r=flag[s];
        s++;
    }
    for(int i=s;i>1;i--){
        int roads=(The_roads(now_r,flag[i]));
        ans+=((roads-now_o*d)/d+1)*a[flag[i]];
        now_r=flag[i];
        now_o+=(roads-now_o*d)/d+1;
    }
    ans+=((The_roads(flag[1],n)-now_o*d)/d+1)*a[flag[1]];
    cout<<ans<<endl;
    return 0;
}
