#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    ll n;
    cin>>n;
    ll x=n,sum=0,id=0;
    bool flag=1;
    while(x){
        sum++;
        if(x%3==1&&flag){
            id=sum;
            flag=0;
        }
        if(x%3==0){
            x-=x/3;
        }else{
            x=x-x/3-1;
        }
    }
    cout<<sum<<" "<<id<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
