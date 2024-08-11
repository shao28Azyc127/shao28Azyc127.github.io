#include <iostream>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,m;
    int i=0;
    cin>>n;
    for(i=0,m=n;m;i++,m=m*2/3){}
    cout<<i<<" ";
    for(i=1,m=n-1;m%3;i++,m=m*2/3){}
    cout<<i;
    return 0;
}