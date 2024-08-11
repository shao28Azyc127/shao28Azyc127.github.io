#include<iostream>
#include<cstdio>
using namespace std;
int n,ans1,ans2,f=0;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    while(n>0){
        ans1++;
        if(f==0&&n%3==1){
            ans2=ans1;
            f=1;
        }
        n=n-(n/3+(n%3!=0));
    }
    cout<<ans1<<" "<<ans2;
    return 0;
}