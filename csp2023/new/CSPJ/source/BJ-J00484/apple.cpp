#include<bits/stdc++.h>
using namespace std;
int n,n2,cnt=1,cnt1=0;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    n2=n;
    while(n%3!=1){
        if(n%3==0) n-=n/3;
        else n-=n/3+1;
        cnt++;
    }
    while(n2>0){
        if(n2%3==0) n2-=n2/3;
        else n2-=n2/3+1;
        cnt1++;
    }
    cout<<cnt1<<' '<<cnt;
    return 0;
}

