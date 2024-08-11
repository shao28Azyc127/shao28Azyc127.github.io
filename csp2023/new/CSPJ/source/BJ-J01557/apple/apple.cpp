#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    long long n;
    cin>>n;
    int day=0,pos=0x3f3f3f3f;
    while(1){
        day++;
        if(n%3==1){
            pos=min(pos,day);
        }
        if(n<=1) break;
        if(n%3==0){
            n=n-n/3;
        }
        else n-=n/3+1;
    }
    cout<<day<<' '<<pos;
    return 0;
}
