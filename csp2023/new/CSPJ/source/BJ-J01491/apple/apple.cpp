#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    int m=n,sum=0;
    while(m){
        if(m%3)m=m-m/3-1;
        else m=m-m/3;
        sum++;
    }
    cout<<sum<<" ";
    int day=0;
    while(n){
        day++;
        if(n%3==1){
            cout<<day<<endl;
            return 0;
        }else{
            if(n%3)n=n-n/3-1;
            else n=n-n/3;
        }
    }
    return 0;
}
