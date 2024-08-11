#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,m,i=0;
    cin>>n;
    m=1000000000;
    while(n>=1){
        i++;
        if((n-1)%3==0){
            m=min(m,i);
        }
        if(n%3>=1){
            n-=n/3+1;
        }else{
        n-=n/3;
        }
    }
    cout<<i<<" "<<m;
    return 0;
}
