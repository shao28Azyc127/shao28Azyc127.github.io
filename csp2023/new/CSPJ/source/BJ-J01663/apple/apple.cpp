#include<iostream>
#include<cstdio>
using namespace std;
int ans=0;
int f(int i){
    if(i==0)return 0;
    int l=(i-1)/3+1;
    int res=f(i-l)+1;
    if((i-1)%3==0){
        ans=res;
    }
    return res;
}
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    int day=f(n);
    cout<<day<<" "<<day-ans+1;
    return 0;
}
