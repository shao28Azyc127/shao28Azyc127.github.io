#include<bits/stdc++.h>
using namespace std;
long long n,cnt,ans;
bool flag=0;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    while(n!=0){
        cnt++;
        if(n%3==1&&!flag){
            ans=cnt;
            flag=1;
        }
        if(n%3==0){
            n=n-n/3;
        }else{
            n=n-n/3-1;
        }
    }
    cout<<cnt<<" "<<ans;
    return 0;
}
