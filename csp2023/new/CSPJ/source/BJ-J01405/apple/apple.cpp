#include<iostream>
#include<cstdio>
using namespace std;
int n;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    bool flag=false;
    if(n%3==1) flag=true;
    int ans=0,m=0,d=0;
    while(n>=0){
        if(!flag && n%3!=1) ans++;
        else flag=true;
        if(n%3==0)
            m=n/3;
        else
            m=n/3+1;

        n-=m;
        d++;
    }
    cout<<d<<' '<<ans+1;
    return 0;
}
