#include<iostream>
#include<cmath>
using namespace std;
int b[100005],c[100005],u[100005],v[100005];
long long a[100005];
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    int n,ans=0,sum=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    for(int i=1;i<n;i++){
        cin>>u[i]>>v[i];
    }
    while(sum<a[1]){
        ans++;
        sum+=max(b[1]+ans*c[1],1);
    }
    ans=max(ans,n);
    cout<<ans;
    return 0;
}
