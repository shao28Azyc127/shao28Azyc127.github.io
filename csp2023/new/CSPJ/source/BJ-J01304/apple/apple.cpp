#include<bits/stdc++.h>
using namespace std;
bool findd=true,flag=true;
int n,i,t,num;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    while(n!=0){
        ++i;
        if(n%3==1&&findd){
            findd=false;
            num=i;
        }
        if(n%3==0) n-=n/3;
        else n-=n/3+1;
    }
    cout<<i<<' '<<num;
    return 0;
}
