#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    bool f=1;
    int tm=0,t2;
    while(n){
        n--;
        tm++;
        if(n%3==0&&f){
            t2=tm;
            f=0;
        }
        n-=n/3;
    }
    cout<<tm<<" "<<t2;
    return 0;
}
