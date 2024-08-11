#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    long long n,t,a1,a2;
    bool f=0;
    cin>>n;
    t=n;
    if(n%3==1){
        a2=1;
    }

    for(long long i=1;i<n;i++){
        f=0;
        if(t%3==1){
            a2=i;
        }
        if(t%3!=0){
            f=1;
        }

        t=t-t/3;
        t-=f;
        if(t==0){
            a1=i;

            break;
        }
    }
    if(n%3==1){
        a2=1;
    }
    cout<<a1<<' '<<a2;
    return  0;
}
