#include<bits/stdc++.h>
using namespace std;
long long n;
long long cnt,ans;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    long long a=n;
    bool f=false;
    while(n!=0){
        cnt++;
        if(n%3==1&&f==false){
                ans=cnt;
                f=true;
        }
        if(n%3==0){
            n=n-(n/3);
        }else{
            n=n-(n/3)-1;
        }
    }
    cout<<cnt<<' '<<ans;
    return 0;
}
