#include<iostream>
#include<cstring>
#define int long long
using namespace std;
int n,t=0,m;
int f(int n){
    if(n==1)return 1;
    if(n==2)return 2;
    if(n==3)return 3;
    int k=n/3+1,l=n%3;
    if(l==0){
        n--;
    }
    return 1+f(n-k);
}
signed main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    int ans1=f(n);
    cout<<ans1<<" ";
    if(n%3==1){
        cout<<1;
    }
    else if(n%3==2){
        cout<<ans1;
    }
    else if(n==3)cout<<3;
    else if(n==6)cout<<2;
    else if(n=9)cout<<3;
    else if(n==12)cout<<6;
    else{
       if(n%2==0)cout<<2;
       else cout<<3;
    }
    return 0;
}
