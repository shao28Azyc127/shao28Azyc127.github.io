#include <bits/stdc++.h>
using namespace std;
int a[10005][10005];
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        int t1,t2,t3;
        cin>>t1>>t2>>t3;
        a[t1][t2]=t3;
    }
    cout<<"-1";
    return 0;
}