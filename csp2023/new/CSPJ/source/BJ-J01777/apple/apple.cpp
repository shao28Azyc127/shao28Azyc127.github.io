#include<iostream>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    int m=n;
    int b;
    if(n%3==1||n==5){
    b=1;
    }
    int cnt=0;
    while(m>0){
    if(m%3==0){
    m=m/3;
    }
    else{
    m=m/3-1;
    }
    cnt++;
    }
    if(n%3==0){
    b=cnt;
    }
    cout<<cnt<<" "<<b;
    return 0;
}
