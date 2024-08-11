#include<bits/stdc++.h>
using namespace std;
long long n,d;
const int N=1e5+10;
long long v[N];
long long a[N];
long long q[N];
long long ans;
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
    for(int i=2;i<=n;i++){
        q[i]=q[i-1]+v[i-1];
    }
    for(int i=1;i<=n;i++){
        if(q[i]%d==0){
            q[i]/=d;
        }else{
            q[i]=(q[i]/d)+1;
        }
        //cout<<q[i]<<endl;
    }
    int k=1;
    for(int i=2;i<=n;i++){
        if(i==n&&a[k]<=a[n]){
            ans+=(q[n]-q[k])*a[k];
            break;
        }
        if(a[k]>a[i]){
            ans+=(q[i]-q[k])*a[k];
            k=i;
        }
    }
    cout<<ans;
    return 0;
}
