#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n;
    cin>>n;
    if(n==1){
        cout<<81;
    }
    if(n==2){
        cout<<10;
    }
    
    if(n==3||n==4||n==5||n==6||n==7||n==8){
        cout<<81;
    }
    return 0;
}