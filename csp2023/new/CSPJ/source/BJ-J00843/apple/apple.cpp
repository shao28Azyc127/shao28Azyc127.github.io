#include<iostream>
using namespace std;
int n;
int cnt,ok,x;
int ans;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    while(n){
        cnt++;
        if(n%3==1&&ok==0){
            ans=cnt;
            ok=1;
        }
        if(n%3==0)n-=n/3;
        else n-=n/3+1;
    }
    cout<<cnt<<" "<<ans;
    return 0;
}