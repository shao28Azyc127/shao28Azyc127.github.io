#include<iostream>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,b,o,m;
    cin>>n;
    o=n+2;
    m=0;
    if(o%3==0){b=m+1;}
    while(n>0){
        int c=o/3;
        n=n-c;
        o=o-c;
        m++;
        if(o%3==0){b=m+1;}
    }
    cout<<m<<" "<<b;
    return 0;
}
