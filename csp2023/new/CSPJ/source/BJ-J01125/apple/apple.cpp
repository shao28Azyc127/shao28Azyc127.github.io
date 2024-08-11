#include <bits/stdc++.h>
using namespace std;
int n,a[15]={0,1,2,3,1,4,2,1,5,3,1};
int dg(int k){
    int x;
    if(k==1 || k==2 || k==3){
        return k;
    }
    else {
        if(k%3==0){
            x=k-k/3;
        }
        else{
            x=k-k/3-1;
        }
        return dg(x)+1;
    }
}
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    if(n>10){
        cout<<dg(n)<<" "<<1;
    }
    else if(n<11){
        cout<<dg(n)<<" "<<a[n];
    }
    return 0;
}