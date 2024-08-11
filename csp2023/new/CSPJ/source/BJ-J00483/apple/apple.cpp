#include<bits/stdc++.h>
using namespace std;
long long n,cnt,day,a[100100];
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    if(n<=100){
        if(n%3==1){
            day=1;
            cnt=(n/3)+2;
        }
        if(n%3==2){

            cnt=(n/3)+3;
            day=cnt;
        }
    }
    if(n>=100){
        if(n%3==1){
            day=1;
            cnt=1+3*(10/3+2);
        }
        if(n%3==2){
            day=(n/3)-3-(n%3);
            cnt=1+3*(10/3+3);
        }
    }
    cout<<cnt<<" "<<day;
    return 0;

}

