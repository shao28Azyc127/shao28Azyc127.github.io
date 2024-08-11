#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,c=0,j=0;
    cin>>n;
    n=1e9;
    while(n){
        c++;
        if(n%3==1&&j==0){
            j=c;
        }
        n=(n/3+(n%3>0))*2-(n%3!=0)*(3-n%3);
        //cout<<n;
    }cout<<c<<" "<<j;
    return 0;
}
