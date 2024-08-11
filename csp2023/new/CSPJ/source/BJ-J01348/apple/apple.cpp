#include<bits/stdc++.h>
using namespace std;
long long n,ans=0,flag;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    freopen("apple.in","w",stdout);
    cin>>n;
    while(n!=0){
        if((n-1)%3==0&&flag==0){
            flag=1;
            cout<<ans;
        }
        ans++;
        long long x;
        x=(n-1)/3+1;
        n-=x;
    }
    cout<<ans;
    return 0;
}
