#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int sum(int n,int x){
    if(n<=3){
        return x+n-1;
    }
    if(n%3==0){
        return sum(n-(n/3),x+1);
    }
    return sum(n-(n/3)-1,x+1);
}
int f(int n,int x){
    if(n<=3){
        return x+n-1;
    }
    if(n%3==1){
        return x;
    }
    if(n%3==0){
        return f(n-(n/3),x+1);
    }
    return f(n-(n/3)-1,x+1);
}
void text(){
    cin>>n;
    cout<<sum(n,1)<<" "<<f(n,1);
    return;
}
signed main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    text();
    return 0;
}