#include <bits/stdc++.h>
using namespace std;

int n,cnt,id;

int main() {
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    bool flag=false;
    while(n) {
        if(n<=3) {
            cnt+=n;
            if(!flag) id=cnt;
            break;
        }
        cnt++;
        if(n%3==1 && !flag) {
            id=cnt;
            flag=true;
        }
        n-=(n+2)/3;
    }
    cout<<cnt<<" "<<id<<endl;
    return 0;
}
//meow

