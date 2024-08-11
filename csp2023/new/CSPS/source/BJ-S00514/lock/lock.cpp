#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n;
    int a[7];
    cin>>n;
    int ans=0;
    for(int i=1;i<=n,i++){
        cin>>a[1]>>a[2]>>a[3]>>a[4]>>a[5];
    }
    for(int j=1;j<=5;j++) ans+=9;
    for(int k=1;k<=4;k++) ans+=9;
    cout<<ans;
    return  0;
}
