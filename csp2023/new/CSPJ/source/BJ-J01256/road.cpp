#include<iostream>
#define int long long
using namespace std;
const int N=100005;
int n,d,dis=0;
int sum,n,d,x;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>x;
        sum+=x;
    }
    cin>>x;
    cout<<int(sum*x*1.0/d);
}
