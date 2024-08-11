#include<bits/stdc++.h>
using namespace std;
int n;
int cnt=0;
int ans=0;
int t=0;
void num(int n){
    if(n%3==1&&t==0){
            ans=cnt;
            t++;
    }
    while(n!=0){
        if(n>3){
            if(n%3!=0){
                n=n-n/3-1;
            }else{
                n=n-n/3;
            }
        }else{
            n--;
        }
        cnt++;
        if(n%3==1&&t==0){
            ans=cnt;
            t++;
        }
    }
}
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    num(n);
    cout<<cnt<<" "<<ans+1;
    return 0;
}