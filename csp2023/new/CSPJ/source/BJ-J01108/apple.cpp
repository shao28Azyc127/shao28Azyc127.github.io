#include<iostream>
using namespace std;

int n,d,ans;

int ceil(int a,int b){
    if(!(a%b)) return a/b;
    return a/b+1;
}
int main(){
    freopen("apple.in","r",stdin);                                            
    freopen("apple.out","w",stdout);                                          
    cin>>n;
    while(n){
        d++;
        if(n%3==1&&!ans) ans=d;
        n-=ceil(n,3);
    }
    cout<<d<<" "<<ans;
    return 0;
}