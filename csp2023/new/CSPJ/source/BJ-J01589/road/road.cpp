#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int a[100001][3]={};
    int n,d;cin>>n>>d;long long sum=0;
    for(int i=1;i<n;i++){cin>>a[i][0];sum+=a[i][0];}
    for(int i=1;i<=n;i++)cin>>a[i][1];
    if(sum%d!=0)cout<<(sum/d+1)*a[1][1];
    else cout<<sum/d*a[1][1];
}