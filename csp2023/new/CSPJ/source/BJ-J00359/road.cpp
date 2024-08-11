#include<iostream>
#include<cmath>
using namespace std;
int n;
int d;
int v[100005];
int a[100005];
int q;
int sum;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdut);
    cin>>n>>d;
    for(int i=1;i<=n-1;i++){
        cin>>v[i];
        sum+=v[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    q=ceil(sum/d)*a[1];
    cout<<q;
    return 0;
}
