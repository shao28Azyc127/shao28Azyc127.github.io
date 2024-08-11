#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,ansb=-1,i=1;
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    if(n%3==1)ansb=0;
    while(n!=0){
        n-=(n-1)/3+1;
        if(n%3==1&&ansb==-1)ansb=i;
        i++;
    }
    cout<<i-1<<" "<<ansb+1;
    return 0;
}