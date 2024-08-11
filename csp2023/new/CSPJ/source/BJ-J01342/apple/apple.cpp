#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,cnt,num;
ll k=0;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    while(n){
        if(n%3==1&&k==0) num=cnt+1,k=1;
        if(n%3==0) n-=n/3;
        else n-=(n/3+1);
        cnt++;
    }
    cout<<cnt<<" "<<num;
    return 0;
}
