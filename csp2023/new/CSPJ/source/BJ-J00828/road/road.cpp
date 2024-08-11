#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll a[100001],b[100001];
bool vis[1000001];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ll n,m,minn=LLONG_MAX,ide=-1,tsum=0;
    cin>>n>>m;
    for(int i=1;i<=n-1;i++){
        cin>>a[i];
        tsum+=a[i];
    }
    a[n]=a[n-1];
    for(int i=1;i<=n;i++){
        cin>>b[i];
        if(b[i]<minn){
            minn=b[i];
            ide=i;
        }
    }
    if(ide==1){
        if(tsum%m==0){
            cout<<tsum/m*b[1];
        }else{
            cout<<(tsum/m+1)*b[1];
        }
        return 0;
    }
    ll ro=0,sum=0,s=0;
    for(int i=1;i<=n-1;i++){
        ll id=-1;
        if(vis[i]){
            continue;
        }
        for(int j=i+1;j<=n;j++){
            ro+=a[j];
            if(b[i]>b[j]){
                id=j;
                break;
            }
            vis[j]=1;
        }
        //cout<<ro<<endl;
        if(ro%m==0){
            sum+=ro/m*b[i];
        }else if(s>=ro%m){
            sum+=ro/m*b[i];
            s-=ro%m;
        }else{
            sum+=(ro/m+1)*b[i];
            s+=(ro/m+1)*m-ro;
        }
        //cout<<sum<<endl;
        ro=0;
    }
    cout<<sum<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
