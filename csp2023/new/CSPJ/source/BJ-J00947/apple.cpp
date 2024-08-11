#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,cnt,ans;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    while(n>0){
        cnt++;
        if(n%3==1 && ans==0)ans=cnt;
        if(n%3==0 || n%3==1)n=n/3*2;
        else n=n/3*2+1;
    }
    cout<<cnt<<" "<<ans;
    return 0;
}
