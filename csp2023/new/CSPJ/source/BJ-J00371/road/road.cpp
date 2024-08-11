#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
int a[MAX],v[MAX],f[MAX];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    long long n,d;
    long long tt=0;
    cin>>n>>d;
    for(int i=1;i<n;i++){
        cin>>v[i];
        tt+=(long long)v[i];
    }
    int m=100005;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        m=min(m,a[i]);
    }
    if(m==a[1]){
        if(tt%d==0)cout<<1ll*tt/d*a[1];
        else cout<<1ll*(tt/d+1)*a[i];
    }
else{
    long long ans=0,surpls=0;
    int i,j;
    for(i=1;i<n-1;i++){
        int cnt=v[i]-surpls;
        surpls=0;
        for(j=i+1;j<n;j++,i++){
            if(a[j]<a[i])break;
            else cnt+=v[j];
        }
        if(cnt%d==0){
            ans+=1ll*cnt/d*a[i];
        }
        else{
            ans+=1ll*(cnt/d+1)*a[i];
            surpls=1ll*(cnt/d+1)*d-cnt;
        }
    }
    cout<<ans;
}
    fclose(stdin);
    fclose(stdout);
    return 0;
}