#include<iostream>
#include<cmath>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,a=1,ay=0,flag=1;
    cin>>n;
    while(n>3){
        if(n%3==1&&flag){
            flag=0;
            ay=a;
            n*=2;
            n/=3;

    }else{
        n*=2;
        n/=3;
    }
    a++;
    }
    if(ay==0)
        ay=a+n-1;
    cout<<a+n-1<<" "<<ay;
    fclose(stdin);
    fclose(stdout);
    return 0;
}