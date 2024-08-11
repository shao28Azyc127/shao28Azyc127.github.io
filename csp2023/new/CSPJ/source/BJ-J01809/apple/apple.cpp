#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,x=0,m,y=0;
    cin>>n;
    m=n;
    while(n>0){
        if(n%3==1&&y==0){
            y=x+1;
        }
        n-=(n+2)/3;
        x++;
    }
    cout<<x<<" "<<y;
    return 0;
}
