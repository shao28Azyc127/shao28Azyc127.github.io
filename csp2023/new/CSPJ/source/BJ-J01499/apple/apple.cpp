#include<bits/stdc++.h>
using namespace std;
long long n,a,b,len,ans;
bool flag=0;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;len=n,len--;
    if(n==0){
        cout<<0<<' '<<0<<endl;
        return 0;
    }
    while(n!=4 && n!=3){
        if(flag==0 && len%3==0) flag=1,ans=a+1;
        if(n%3==0) n=n-n/3,len-=n/3;
        else n=n-n/3-1,len-=n/3+1;
        a++;
    }
    cout<<a+3<<' ';
    if(!flag) cout<<a+3;
    else cout<<ans<<endl;
    return 0;
}
