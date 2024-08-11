#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    
    long long n;
    cin>>n;
    
    long long t=0;
    long long v=n;
    while(v!=0){
        if(v==1){
            t++;
            break;
        }
        if(v%3==1) v=v-(v/3);
        else v=v-(v/3+1);
        t++;
    }
    if(n%3!=1){
        t++;
    }
    if(n==2){
        t=2;
    }
    
    long long c=0;
    if(n%3==0){
        cout<<t<<" "<<n/3<<endl;
        return 0;
    }else if(n%3==1){
        cout<<t<<" "<<1<<endl;
        return 0;
    }
    
    
    if(n==2){
        cout<<t<<" "<<2<<endl;
    }else{
        cout<<t<<" "<<n/3+n%3+1<<endl;
    }
    return 0;
}