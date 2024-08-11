#include<bits/stdc++.h>
using namespace std;
//cout<<"Thanks god.Please help me AK CSP-J!";
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,cnt=0,f=0;
    cin>>n;
    while(n){
        cnt++;
        if(!f&&n%3==1){
            f=cnt;
        }
        if(n%3==0)n-=n/3;
        else n=n-(n/3+1);
    }
    cout<<cnt<<" "<<f;
    return 0;
}
