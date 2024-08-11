#include<iostream>
using namespace std;
int f(int n){
    if (n==0) return 0;
    else return f(n-(n+2)/3)+1;
}
int g(int n){
    if (n%3==1) return 1;
    else return g(n-(n+2)/3)+1;
}
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    cout<<f(n)<<" "<<g(n);
    return 0;
}