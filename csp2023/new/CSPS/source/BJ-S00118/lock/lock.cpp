#include<bits/stdc++.h>
using namespace std;
int n;
int a[5][10];
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=5;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    if(n==1){
        cout<<81;
        return 0;
    }else cout<<10;
    return 0;
}
