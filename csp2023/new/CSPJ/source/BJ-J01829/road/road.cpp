#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N],v[N],f[N];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d,s=0,t=0,x,minn=N;
    cin>>n>>d;
    for(int i=1;i<n;i++){
        cin>>v[i];s+=v[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];minn=min(minn,a[i]);
    }
    if(minn==a[1]){
        x=ceil(1.0*s/d);
        cout<<x*a[1];
        return 0;
    }
    s=0;
    f[1]=v[1];
    for(int i=1;i<=n;i++){
        if(a[i]<a[i+1]){
            f[i]=v[i];
            for(int j=i+1;j<=n;j++){
                if(a[i]<a[j]){
                    f[i]+=v[j];
                    f[j]=-1;
                }
                else break;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(f[i]==0)f[i]=v[i];
        //cout<<f[i]<<" ";
    }
    for(int i=1;i<=n;i++){
        if(f[i]==-1||f[i]==0)continue;
        if(ceil((f[i]-t)*1.0/d)*a[i]==ceil(f[i]*1.0/d)*a[i]){
            s=s+ceil((f[i]-t)*1.0/d)*a[i];
        }
        else {
            s=s+ceil((f[i]-t)*1.0/d)*a[i];
            t=0;
        }
        t+=ceil((f[i]*1.0-t)/d)*d-f[i];
        //cout<<t<<endl;
    }
    cout<<s;
    return 0;
}
/*5 4
10 10 10 10
9 8 9 6 5*/