#include<iostream>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int a[10001],b[10001];
    int n,d,cost=0,sx=0;
    cin>>n>>d;
    for(int i=1;i<n;i++){
        cin>>b[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cost+=(b[1]/d+1)*a[1];
    for(int i=2;i<n;i++){
        if(b[i]<b[i+1]){
            cost+=((b[i]+b[i+1]-sx)/d+1)*a[i];
            sx=((b[i]+b[i+1]-sx)/d+1)*a[i]-(b[i]+b[i+1]);
            i++;
        }
    }
    cout<<cost;
    return 0;
}
