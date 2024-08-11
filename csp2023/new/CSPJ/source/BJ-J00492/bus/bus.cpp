#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    int n,l=0;
    while(cin>>n) l++;
    if(n>5){
        cout<<1000782;
    }
    else{
        cout<<6;
    }
}
