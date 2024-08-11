#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int n,d,a[100005],v[100005];
int main(){
    freopen("rode.in","w",stdin);
    freopen("rode.out","r",stdout);
    cin>>n>>d;
    int sum=0;
    for(int i=1;i<=n-1;i++){
        cin>>v[i];
        sum+=v[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int mn=2e9;
    int t=sum/d;
    cout<<t*a[1];
    return 0;
}
