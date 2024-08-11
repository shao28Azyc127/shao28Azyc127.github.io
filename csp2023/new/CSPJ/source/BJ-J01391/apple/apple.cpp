#include <iostream>
using namespace std;

int main() {
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,cnt=0,day=0;
    bool havday=0;
    cin>>n;
    for(;n;) {if(n%3==1&&!havday) {day=cnt+1;havday=1;} n-=(n%3==0?n/3:n/3+1),cnt++;}
    cout<<cnt<<" "<<day<<endl;
    return 0;
}
