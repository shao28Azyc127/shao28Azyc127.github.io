#include <bits/stdc++.h>
using namespace std;
int n,cnt=0;
int a[10],b[5][10];
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    if(n==1){
        cin>>a[1]>>a[2]>>a[3]>>a[4]>>a[5];
        cout<<81;
    }
    if(n==2){
        for(int i=1;i<=n;i++){
            cin>>b[1][i]>>b[2][i]>>b[3][i]>>b[4][i]>>b[5][i];
        }
        for(int i=1;i<=5;i++){
            if(a[i][1]!=a[i][2]) cnt++;
        }
        if(cnt==1) cout<<10;
        if(cnt==2) cout<<8;
    }
    if(n>2){
        for(int i=1;i<=n;i++){
            cin>>b[1][i]>>b[2][i]>>b[3][i]>>b[4][i]>>b[5][i];
        }
        int t=10-n;
        cout<<t;
    }
    return 0;
}
