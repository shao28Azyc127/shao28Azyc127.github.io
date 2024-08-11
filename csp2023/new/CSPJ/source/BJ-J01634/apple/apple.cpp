#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    long long n,c1=0,c2,j=0;
    cin>>n;
    for(;n!=0;){
        if(n%3==1&&j==0){
            c2=c1+1;
            j=1;
        }
        if(n>3){
            if((n+1)%3==2)
                n-=((n+1)/3)+1;
            else
                n-=(n+1)/3;
        }
        else
            n--;
        c1++;
    }
    cout<<c1<<" "<<c2;
    return 0;
}