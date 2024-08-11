#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,cnt=0,ans;
    cin>>n;
    bool f=1;
    while(n>0){
        cnt++;
        if(n%3==1&&f){
            ans=cnt;
            f=0;
        }
        n-=(n+2)/3;
    }
    cout<<cnt<<" "<<ans<<endl;
    return 0;
}
