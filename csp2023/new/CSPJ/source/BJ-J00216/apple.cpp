#include<bits/stdc++.h>
using namespace std;
int n,ans2=0,ans1=0,cnt=0;
signed main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    while(n){
        cnt++;
        if((n%3==1)&&(ans2==0)) ans2=cnt;
        if(n%3==0) n=n/3*2;
        else if(n%3==1) n=n/3*2;
        else if(n%3==2) n=n/3*2+1;
    }
    cout<<cnt<<" "<<ans2<<endl;
    return 0;
}
