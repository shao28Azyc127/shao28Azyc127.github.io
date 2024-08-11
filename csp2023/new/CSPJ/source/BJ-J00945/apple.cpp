#include<bits/stdc++.h>
using namespace std;
int n,p,l;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin >> n;
    while(n){
        l++;
        if(n%3==1&&!p) p=l;
        n=n*2/3;
    }
    cout << l << ' ' << p;
    return 0;
}
