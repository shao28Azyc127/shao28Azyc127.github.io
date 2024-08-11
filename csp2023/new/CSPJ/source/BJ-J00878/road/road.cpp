#include <iostream>
using namespace std;
int v[100005];
int a[100005];
int pm[100005];
int f[100005];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d,c=0;
    cin>>n>>d;
    for(int i=1;i<n;i++){
        cin>>v[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    pm[0]=0x3f3f3f3f;
    for(int i=1;i<=n;i++){
        pm[i]=min(pm[i-1],a[i]);
    }
    for(int i=1;i<n;i++){
        f[i+1]=f[i]-v[i];
        if(f[i+1]<0){
            int p=(-f[i+1]-1)/d+1;
            c+=p*pm[i];
            f[i+1]+=p*d;
        }
    }
    cout<<c;
    return 0;
}