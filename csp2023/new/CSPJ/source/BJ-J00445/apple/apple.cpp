#include<iostream>
#include<cstdio>
using namespace std;

int n,c1,c2;

int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    while(n){
        if(n%3==1&&!c2)c2=c1+1;
        n-=(n-1)/3+1,c1++;
    }
    cout<<c1<<' '<<c2;

    return 0;
}
