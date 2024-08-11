#include<bits/stdc++.h>
using namespace std;
#define int long long
int a1(int n){
    if(n==0){
        return 0;
    }
    int m;
    m=1;
    n--;
    m+=n/3;
    n++;
    n-=m;
    return a1(n)+1;
}
int a2(int n){
    if(n%3==1){
        return 1;
    }
    int m;
    m=1;
    n--;
    m+=n/3;
    n++;
    n-=m;
    return a2(n)+1;
}
signed main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    cout<<a1(n)<<" "<<a2(n)<<endl;
    return 0;
}
