#include<bits/stdc++.h>
using namespace std;
int n,k,m;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    while(n>0){
        k++;
        if(n%3==1&&!m)
            m=k;
        if(n%3)n-=(n/3+1);
        else n-=(n/3);
    }
    cout<<k<<' '<<m;
    return 0;
}
