#include<bits/stdc++.h>
using namespace std;
int n;
int f(int x){
    if(x==1||x==2||x==3)return x;
    return (x%3==0)?f(x-x/3)+1:f(x-x/3-1)+1;
}
int ff(int x){
    if(x==1||(x-1)%3==0)return 1;
    return (x%3==0)?ff(x-x/3)+1:ff(x-x/3-1)+1;
}
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    cout<<f(n)<<endl;
    cout<<ff(n)<<endl;
    return 0;
}
