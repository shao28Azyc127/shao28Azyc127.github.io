#include <bits/stdc++.h>
using namespace std;
int n,num=0,ans;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    int a=n,apple[n+1];
    for (int i=1;i<=n;i+=3){
        apple[i]=i;
    }
    while(apple.length()>1){
        num++;
        for (int i=1;i<=apple.length();i+=3){
            apple.pop(i);
            if (apple[i]==n){
                ans=num;
            }
        }
    cout<<num<<ans;
}