#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,pos,ans=0,fin;
    cin>>n;
    pos=n;
    while(n){
        ans++;
        if(n%3==1)fin=ans+1;
       if(n%3==0) n-=n/3;
        else  n-=(n+3-(n%3))/3;
    }
    cout<<ans<<' '<<fin;
    return 0;
}