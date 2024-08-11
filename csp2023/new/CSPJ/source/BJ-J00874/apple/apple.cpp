#include <iostream>
using namespace std;
int a[11]={0,1,2,3,1,2,3,1,5,3,1};
int t[11]={0,1,2,3,3,3,4,4,5,5,5};
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    cout<<t[n]<<" "<<a[n];
    return 0;
}
