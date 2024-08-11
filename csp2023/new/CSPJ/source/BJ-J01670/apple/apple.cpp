#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    int i=0,p=n;
    while(n>0){
        i++;
        if (n%3==1)p=min(i,p);
        if (n%3==0)n-=n/3;
        else n-=n/3+1;
    }
    cout<<i<<" "<<p;
}
