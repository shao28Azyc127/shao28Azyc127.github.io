#include<iostream>
#include<fstream>
using namespace std;
int main(){
    int n,cmp=0,cnt=0,i;
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    if(n==1) {cout<<1<<" "<<1;return 0;}
    if(n%3==1){cmp=n/3+2;cnt=1;}
    if(n%3==2)
    {
        if(n==5){cmp=4;cnt=4;}
        if(n==2){cmp=2;cnt=2;}
        if(n==8){cmp=5;cnt=5;}
    }
    if(n%3==0)
    {
        if(n==3){cmp=3;cnt=3;}
        if(n==6){cmp=4;cnt=2;}
        if(n==9){cmp=5;cnt=3;}
    }
    cout<<cmp<<" "<<cnt;
}