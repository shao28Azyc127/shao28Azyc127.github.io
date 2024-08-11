#include<iostream>
using namespace std;
int find(long long x){
    if(x%3==1) return 1;
    return 1+find(x-(x+2)/3);
}
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    long long n,a,x;
    cin>>n;
    a=0;
    x=n;
    while(x>0){
        x-=(x+2)/3;
        a++;
    }
    cout<<a<<" ";
    cout<<find(n);
    return 0;
}
