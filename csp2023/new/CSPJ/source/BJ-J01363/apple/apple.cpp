#include <iostream>
using namespace std;
unsigned long long n,ans=0,a;
int main(){
    bool uft=true;
    freopen("apple.in",'r',stdin);
    freopen("apple.out",'w',stdout);
    cin>>n;
    while(n>0){
        ans++;
        if(n%3==1&&uft){
            uft=false;
            a=ans;
        }
        n=n*(2/3);
    }
    cout<<ans<<" "<<a;
    return 0;
}