#include<bits/stdc++.h>
using namespace std;
const int MAX =1e9 + 5;

int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    int getN=0;
    
    int sum=0,apples=n,getA;

    while(apples>0){
        getA = ceil(apples/3.0);
        apples-=getA;
        sum++;
    }
    if((n-1)%3==0){
        getN=1;
    }

    cout<<sum<<' '<<getN;
    return 0;
}