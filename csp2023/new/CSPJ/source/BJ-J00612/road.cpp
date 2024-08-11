#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int n,d,price=0;
    cin>>n>>d;
    int a[100005],b[100005],v[100005];
    for(int i=0;i<n-1;i++)
        cin>>v[i];
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n-1;i++){
        if(v[i]%d==0) price+=v[i]/d*a[i];
        else{
            price+=(v[i]/d+1)*a[i];
            v[i+1]-=(v[i]/d+1)*d-v[i];
        }
        if(a[i]<a[i+1]) a[i+1]=a[i];
    }
    cout<<price;
    return 0;
}
