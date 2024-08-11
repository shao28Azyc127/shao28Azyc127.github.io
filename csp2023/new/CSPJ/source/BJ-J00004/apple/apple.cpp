#include<iostream>
using namespace std;
long long f1(long long k){
    if(k<=3)return k;
    return f1(k-(k+2)/3)+1;
}
long long f2(long long k){
    if(k<=3)return k;
    if((k%3)==1)return 1;
    return f2(k-(k+2)/3)+1;
}
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    long long n;
    cin>>n;
    cout<<f1(n)<<" "<<f2(n);
    return 0;
}
