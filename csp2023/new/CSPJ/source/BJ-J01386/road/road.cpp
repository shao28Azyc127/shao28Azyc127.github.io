#include <iostream>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d,a[1000005],b[1000005],sum=0;
    cin>>n>>d;
    for(int i=1;i<=n-1;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    int one=a[1]/d;
    if(one*d==a[1]){
        sum+=b[1]*one;
    }else{
        sum+=b[1]*(one+1);
    }
    cout<<sum;
    return 0;
}
