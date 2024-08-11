#include<iostream>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    long long n,ans=-1,cnt=0;;
    cin>>n;
    while(n){
        if(ans==-1 && n%3==1) ans=cnt+1;
        if(n>3){
            n-=(n+2)/3;
        }else n--;
        cnt++;
    }
    cout<<cnt<<" "<<ans;
    return 0;
}
