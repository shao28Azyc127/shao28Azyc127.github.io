#include<bits/stdc++.h>
using namespace std;
int v[100001],a[100001],minn=2147483647,pos;
int main(){
    //freopen("road.in","r",stdin);
    //freopen("road.out","w",stdout);
    int n,d,pass=0,sum=0;
    cin>>n>>d;
    for(int i=1;i<=n-1;i++){
        cin>>v[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        if(minn>a[i]){
            minn=a[i];
            pos=i;
        }
    }
    if(pos==1){
        int route=0;
        for(int i=1;i<=n-1;i++){
            route+=v[i];
        }
        cout<<int(ceil(route*1.0/d)*1.0*a[1]);
        return 0;
    }
    minn=2147483647;
    for(int i=1;i<n;i++){
        minn=min(minn,a[i]);
        int r=v[i]-pass;
        int oil=int(ceil(r*1.0/d));
        pass=(pass+oil*d)-v[i];
        sum+=oil*minn;
    }
    cout<<sum;
    return 0;
}