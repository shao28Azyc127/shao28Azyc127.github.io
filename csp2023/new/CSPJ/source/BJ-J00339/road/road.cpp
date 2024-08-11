#include<iostream>
using namespace std;
int n,d;
int v[100005],a[100005];
int now=1;
int ans=0;
int o=0;
int f(int m){
    for(int i=m+1;i<=n;i++){
        if(a[i]<a[m]) return i;
    }
    return n;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=2;i<=n;i++){
        cin>>v[i];
        v[i]+=v[i-1];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    while(true){
        if(now==n) break;
        int x=f(now);
        int s=v[x]-v[now]-o;
        o=0;
        int p=((s%d)?(s/d+1):(s/d));
        ans+=p*a[now];
        o+=p*d;
        o-=s;
        now=x;
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
}
