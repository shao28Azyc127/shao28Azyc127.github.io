#include<iostream>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,a[1000]={},b[1000]={},sum=0,sum2=0;
    cin>>n>>m;
    for(int i=1;i<n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    for(int i=1;i<n;i++){
        int k=((a[i]+m-1-sum2)/m);
        sum+=b[i]*((a[i]+m-1-sum2)/m);
        sum2=k*m-a[i];
    }
    cout<<sum<<endl;

    return 0;
}
