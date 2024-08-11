#include <bits/stdc++.h>
using namespace std;
int n,d,ans;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    bool b=1;
    while(n>0){
        d++;
        if(n%3==1 && b){
            ans=d;
            b=0;
        }
        int x=(n+2)/3;
        n-=x;
    }
    cout<<d<<" "<<ans;
    return 0;
}