#include<bits/stdc++.h>
using namespace std;
int n,d,x,now,v[100005],a[100005];
int main(){
    freopen("road.in",stdin,"r");
    freopen("road.out",stdout,"w");
    cin>>n>>d;
    for(int i=2;i<=n;i++){
        scanf("%d",&x);
        v[i]=v[i-1]+x;
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    int ans1=v[n]/d,ans;
    bool comp=0;
    if(v[n]%d>0)ans1++;
    ans1*=a[1];
    for(int i=2;i<=n;i++){
        if(a[i]<a[1]){
            comp=1;
            break;
        }
    }
    if(comp==0){
        cout<<ans1;
        return 0;
    }
    for(int i=1;i<n;i++){
        int u1=0;
        int g=v[i+1]-v[i];
        d-=g;
        if(i==1){
            g/=d;
            if(g%d>0)++g;
            ans+=g*v[1];
            now+=d*g;
            continue;
        }
        for(int j=i+1;j<n;j++){
            if(a[j]<a[i]){
                u1=j;
                break;
            }
        }
        if(u1>0){
            int t=v[u1]-v[i];
            t-=now;
            t/=d;
            if(t%d>0)t++;
            now+=d*t;
            ans+=a[i]*t;
        }
        else{
            int t=v[n]-v[i];
            t-=now;
            t/=d;
            if(t%d>0)t++;
            now+=d*t;
            ans+=a[i]*t;
        }
    }
    if(ans>ans1)cout<<ans1;
    else cout<<ans;

    return 0;
}
