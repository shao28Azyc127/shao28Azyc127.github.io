#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,d;
int v[N];
int a[N];
long long ans;
int minn=2147483647;
long long s;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<=n-1;i++){
        cin>>v[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    minn=a[1];
    for(int i=1;i<=n-1;i++){
        //cout<<s<<"______"<<endl;
        minn=min(minn,a[i]);
        if(s>=v[i]){
            s-=v[i];
            continue;
        }
        long long cnt=(v[i]-s+d-1)/d;
        ans+=cnt*minn;
        s+=d*cnt-v[i];
        //cout<<i<<" "<<cnt<<endl;
    }
    cout<<ans;
    return 0;
}
