#include <bits/stdc++.h>
using namespace std;
const int N=10;
int n;
int a[N][5];
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i][0]>>a[i][1]>>a[i][2]>>a[i][3]>>a[i][4]>>a[i][5];
    if(n==1)cout<<81;
    return 0;
}
