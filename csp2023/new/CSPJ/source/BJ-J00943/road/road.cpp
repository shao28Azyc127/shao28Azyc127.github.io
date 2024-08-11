/*
*/
#include<bits/stdc++.h>
#define ll long long
#define N 200000
using namespace std;
ll n,m,k,ans,a[N],v[N],s[N],f[N],minn;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<n;i++){
        cin>>v[i];
    }
    for(int i=1;i<=n;i++) { cin>>a[i]; minn=min(minn,a[i]);}
    if(minn==a[1]){
         ll k=(s[n]-s[1])/m*a[1]+((s[n]-s[1])%m!=0)*a[1];
         cout<<k;
         return 0;
    }
    for(int i=2;i<=n;i++){
        s[i]=s[i-1]+v[i-1];
    }
    memset(f,0x3f,sizeof(f));
    f[1]=0;
    for(int i=2;i<=n;i++){
            int id;
        for(int j=1;j<i;j++){
            ll k=(s[i]-s[j])/m*a[j]+((s[i]-s[j])%m!=0)*a[i];
              if(f[i]>f[j]+k){
                f[i]=f[j]+k;
                id=j;
              }
        }
        //cout<<f[i]<<" ";
    }
    cout<<f[n];
    return 0;
}
