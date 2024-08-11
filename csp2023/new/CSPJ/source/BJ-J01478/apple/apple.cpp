#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("apple.in","r","stdin");
    freopen("apple.out","w","stdout");
    int n,ans=0,ansn=0,f=0;
    cin>>n;
    while(n>0){
        ans++;
        if(n%3==1&&f==0){
            ansn=ans;
            f=1;
        }
        n-=((n-1)/3+1);
    }
    cout<<ans<<" "<<ansn;
    return 0;
}