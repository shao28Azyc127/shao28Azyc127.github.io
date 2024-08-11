#include<bits/stdc++.h>
using namespace std;
int n;
int a[10][10];
int main(){
    //const char*_restrict_modes r,w;
    freopen("lock.in",r,stdin);
    freopen("lock.in",w,stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            cin>>a[i][j];
        }
    }
    if(n==1){
        cout<<81;
        return 0;
    }
    /*for(int i=1;i<=n;i++){
        for(int j=1;j<=45;j++){
            if()
        }
    }*/
}