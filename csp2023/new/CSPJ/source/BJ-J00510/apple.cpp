#include<iostream>
using namespace std;
int n,ans,nn;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    nn=n;
    while(n){
        n-=(n+2)/3;
        ans++;
    }
    cout<<ans<<" ";
    ans=0;
    while(nn%3!=1&&ans<10){
        nn-=(nn+2)/3;
        ans++;
    }
    cout<<ans+1<<endl;
    return 0;
}
