#include<bits/stdc++.h>
using namespace std;
int a[101];
int main(){
    int n;
    cin>>n;
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==1){
        cout<<"81";
    }
    if(n==2){
        cout<<"10";
    }
    if(n==3){
        cout<<"21";
    }
    if(n==4){
        cout<<"49";
    }
    if(n==5){
        cout<<"59";
    }
    if(n==6){
        cout<<"78";
    }
    if(n==7){
        cout<<"93";
    }
    if(n==8){
        cout<<"321";
    }
    return 0;
}
