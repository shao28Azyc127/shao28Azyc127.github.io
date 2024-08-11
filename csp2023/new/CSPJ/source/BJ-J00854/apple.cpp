#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple2.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    int ans=0,an=0,x=0;
    while(n){
        if(n<=3){
            ans+=n;
            break;
        }
        ans++;
        if((n-1)%3==0){
            if(!an) an=ans;
        }
        x=1;
        x+=n/3;
        n-=x;
    }
    if(!an) an=ans;
    cout<<ans<<" "<<an;
    return 0;
}