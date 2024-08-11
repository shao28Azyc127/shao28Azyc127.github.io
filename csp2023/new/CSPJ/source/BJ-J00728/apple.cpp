#include<iostream>
#include<stdio.h>
#include<cstdio>
using namespace std;
int main(){
    freopen("apple.in",'r',stdin);
    freopen("apple.out",'w',stdout);
    int n,num,first,day=0,x=0;
    cin>>n;
    while(n!=0){
        day+=1;
        for(int i=1;i<=n;i+=3){
            num+=1;
            if(i==n){
                if(x==0){
                    first = day;
                    x = 1;
                }
            }
        }
    n -= num;
    num = 0;
    }
    cout<<day<<' '<<first;
    return 0;
}